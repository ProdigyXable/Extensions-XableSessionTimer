/* EditData.hpp
 * This is where you control what data
 * you want to have at edittime. You
 * are responsible for serializing and
 * deserializing (saving/loading) the
 * data to/from the SerializedED structure
 * as if it were a file on the hard drive.
 * It doesn't need to be efficient; this
 * is just at edittime and once at the
 * start of the 
 .
 */

struct EditData
{
	/* MyString, MyInt, MyArray_t, MyArray
	 * Example data
	 */
	//stdtstring MyString;
	//int MyInt;
	//typedef std::vector<float> MyArray_t;
	//MyArray_t MyArray;

	/* <default constructor>
	 * This is where you provide default values for
	 * your editdata. This constructor is used
	 * when your extension is first created and
	 * default values are needed.
	 */
	bool automation;
	bool TickSizeCheck;
	int TickSize;
	bool refresh;
	bool load;

	EditData()
	{
		automation = true;
		TickSizeCheck = false;
		TickSize = 60;
		refresh = false;
		load = true;	
	}

	/* <copy constructor>
	 * As a convenience in other parts of your code,
	 * you should copy data from another instance
	 * of the EditData class. Make sure you deep-copy
	 * dynamically allocated memory e.g. with pointers.
	 */
	EditData(const EditData &from) // : MyString(from.MyString), MyInt(from.MyInt), MyArray(from.MyArray)
	{
		automation = from.automation;
		TickSizeCheck = from.TickSizeCheck;
		TickSize = from.TickSize;
		refresh = from.refresh;
		load = from.load;
	}

	/* operator=
	 * This is essentially the same as the copy
	 * constructor above, except you are working
	 * with an instance that is already
	 * constructed.
	 */
	EditData &operator=(const EditData &from)
	{
		automation = from.automation;
		TickSize = from.TickSize;
		TickSizeCheck = from.TickSizeCheck;
		refresh = from.refresh;
		load = from.load;
	}

#ifndef RUN_ONLY
	/* Serialize
	 * This is where you need to "write" data
	 * to SerializedED like a file. Make sure
	 * you can read the data back in the
	 * constructor below!
	 */
	bool Serialize(mv *mV, SerializedED *&SED) const
	{
		//First, figure out how much space is needed
		unsigned size = 0;
		//size += (MyString.length()+1) * sizeof(stdtstring::value_type);
		//size += sizeof(MyInt);
		//size += sizeof(MyArray_t::size_type);
		//size += MyArray.size() * sizeof(MyArray_t::value_type);
		size += sizeof(automation);
		size += sizeof(TickSize);
		size += sizeof(TickSizeCheck);
		size += sizeof(refresh);
		size += sizeof(load);

		//Then, ask MMF2 to provide this space for us in the SerializedED
		{
			SerializedED *t = (SerializedED *)mvReAllocEditData(mV, SED, sizeof(SerializedED)+size);
			if(t) //if it worked
			{
				SED = t;
				//Since SED is a pointer passed by reference,
				//it will update outside this function so that
				//the calling code keeps a valid pointer to
				//the SerializedED.
			}
			else return false; //could not allocate space
		}

		//Now, the crazy-looking part: serialize the data
		char *p = (char *)(&SED->data); //put the pointer at the beginning of the space MMF2 gave us
		//Perform the copy:												Advance the pointer:
		//_tcscpy(p, MyString.c_str());									p += (MyString.length()+1) * sizeof(stdtstring::value_type);
		//memcpy(p, &MyInt, sizeof(MyInt));								p += sizeof(MyInt);
		//MyArray_t::size_type MyArray_size = MyArray.size();
		//memcpy(p, &MyArray_size, sizeof(MyArray_size));				p += sizeof(MyArray_size);
		//for(MyArray_t::size_type i = 0; i < MyArray_size; ++i)
		//{
			//memcpy(p, &MyArray[i], sizeof(MyArray_t::value_type));	p += sizeof(MyArray_t::value_type);
		//}
		//If you get tired of retyping the size stuff from above, you can always store
		//the sizes in variables or make macros for them.

		//Done!
		memcpy(p, &automation, sizeof(automation));
		p += sizeof(automation);

		memcpy(p, &TickSize, sizeof(TickSize));
		p += sizeof(TickSize);

		memcpy(p, &TickSizeCheck, sizeof(TickSizeCheck));
		p += sizeof(TickSizeCheck);

		memcpy(p, &refresh, sizeof(refresh));
		p += sizeof(refresh);

		memcpy(p, &load, sizeof(load));
		p += sizeof(load);

		return true; //return false in the event of an error
	}
#endif

	/* <constructor>
	 * This is the primary constructor for the
	 * EditData class. Here you will have to
	 * "read" SerializedED like a file and
	 * load back everything that gets saved
	 * above in Serialize. Make sure you check
	 * the version information first, this
	 * constructor is used to update from
	 * older versions of your editdata as well.
	 */
	EditData(SerializedED *SED)
	{
		if(SED->Header.extVersion == 0)
		{
			//code to update from an older version
		}
		else if(SED->Header.extVersion == 1)
		{
			//We have to do some crazy stuff again!
			char *p = (char *)(&SED->data);
			automation = *(bool *)p;
			p += sizeof(automation);

			TickSize = *(bool *)p;
			p += sizeof(TickSize);

			TickSizeCheck = *(bool *)p;
			p += sizeof(TickSizeCheck);
			
			refresh = *(bool *)p;
			p += sizeof(refresh);

			load = *(bool *)p;
			p += sizeof(load);
			//Load the data:													Advance the pointer:
			//MyString = p; /*std::string is smart enough for this*/			p += (MyString.length()+1) * sizeof(stdtstring::value_type);
			//MyInt = *(int *)p;												p += sizeof(MyInt);
			//MyArray_t::size_type MyArray_size = *(MyArray_t::size_type *)p;	p += sizeof(MyArray_size);
			//for(MyArray_t::size_type i = 0; i < MyArray_size; ++i)
			//{
				//MyArray.push_back(*(MyArray_t::value_type *)p);				p += sizeof(MyArray_t::value_type);
			//}
		}
		else //the version is newer than current
		{
			//Either try to load the data anyway assuming your
			//future self was smart enough to keep the data in
			//the same format with new data at the end, or
			//make an error dialog and load some default data.
			//MessageBox(NULL, _T("The MFA you are trying to load was saved"
			//					  "with a newer version of this extension."),
			//				   _T("Error Loading My Extension"), MB_OK);
		}
	}

	/* <destructor>
	 * If you grabbed any memory e.g. with new,
	 * make sure to e.g. delete it in here.
	 */
	~EditData()
	{
		
	}
};
