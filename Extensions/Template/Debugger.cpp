/* Debugger.cpp
 * Here you will be able to interact
 * with the MMF2 debugger (that thing
 * in the top left when you run your
 * MFA from MMF2). You can add your own
 * fields of your choice to your object's
 * debugger tree.
 * Functions defined here:
 * GetDebugTree
 * GetDebugItem
 * EditDebugItem
 */

#include "Common.h"

#ifndef RUN_ONLY //The debugger is only available when running from MMF2, which uses the Edittime MFX

/* DB
 * This is the namespace the debugger identifiers
 * are stored in. It keeps them out of the global
 * namespace and it helps with intellisense.
 */
namespace DB
{
	/* <enum>
	 * The debugger identitifers.
	 */
	enum
	{
		Parent_Global,
		Session_Global,
		DB_Version,
		DB_SessionSize,
		DB_GlobalSessionTime,
		DB_FrameRate,
	};
}

/* DebugTree
 * The list of items to be displayed
 * in the debugger tree.
 */
WORD DebugTree[] =
{
//	DB::MyString|DB_EDITABLE,
//	DB::MyInt|DB_EDITABLE,
//	DB::SomethingThatIDontWantTheUserToBeAbleToEditAtRuntime,
//	DB::DB_Version,
	DB_PARENT|DB::Parent_Global, DB::DB_GlobalSessionTime,
	DB_PARENT|DB::Parent_Global, DB::DB_FrameRate,
	DB_PARENT|DB::Session_Global, DB::DB_SessionSize,
	DB_END
};

#endif

/* GetDebugTree
 * Plain and simple, just return the debug
 * tree pointer from above. If you really
 * want to you can create the debug tree
 * dynamically and return that, but you'll
 * need to store the pointer in your extension
 * class every time so that you can release
 * the memory in your extension class' destructor.
 */
LPWORD MMF2Func GetDebugTree(RD *rd)
{
#ifndef RUN_ONLY
	return DebugTree;
#endif
	return NULL;
}

/* GetDebugItem
 * With respect to DB_BUFFERSIZE, give
 * MMF2 the string to display in the
 * debugger. You must include both the
 * name and the value in the string,
 * or any format you want.
 */
void MMF2Func GetDebugItem(LPSTR Buffer, RD *rd, int ID)
{
	LPWSTR pBuffer = (LPWSTR)Buffer;

#ifndef RUN_ONLY
//	char temp[DB_BUFFERSIZE];
	
	#ifndef UNICODE
		switch (ID)
		{
		case DB::DB_FrameRate:
			{
				wsprintf(Buffer, "Framerate: %i", rd->pExtension->GetFrameRate());
				break;
			}
		case DB::DB_GlobalSessionTime:
			{
				wsprintf(Buffer, "Global Time: %i", rd->pExtension->GetOverAllSeconds());
				break;
			}
		case DB::DB_SessionSize:
			{
				//LoadString(hInstLib, (UINT_PTR)"NULL", temp, DB_BUFFERSIZE);
				wsprintf(Buffer, "Total Number of Sessions: %i", rd->pExtension->NumberofSessions());
				break;
			}
		case DB::Parent_Global:
			{
				wsprintf(Buffer, "Global Session Data");
				break;
			}
		case DB::Session_Global:
			{
				wsprintf(Buffer, "Session Data");
				break;
			}
		}
	#else UNICODE
		switch (ID)
		{
		case DB::DB_FrameRate:
			{
				wsprintf(pBuffer, (LPWSTR)"Framerate: %i", rd->pExtension->GetFrameRate());
				break;
			}
		case DB::DB_GlobalSessionTime:
			{
				wsprintf(pBuffer, (LPWSTR)"Global Time: %i", rd->pExtension->GetOverAllSeconds());
				break;
			}
		case DB::DB_SessionSize:
			{
				//LoadString(hInstLib, (UINT_PTR)"NULL", temp, DB_BUFFERSIZE);
				wsprintf(pBuffer, (LPWSTR)"Total Number of Sessions: %i", rd->pExtension->NumberofSessions());
				break;
			}
		case DB::Parent_Global:
			{
				wsprintf(pBuffer, (LPWSTR)"Global Session Data");
				break;
			}
		case DB::Session_Global:
			{
				wsprintf(pBuffer, (LPWSTR)"Session Data");
				break;
			}
		}

	
#endif

#endif
}

/* EditDebugItem
 * When the user chooses to edit an
 * editable debug item, this function
 * is called. You can use the RFUNCTIONs
 * provided by MMF2 to do simple text and
 * number edits, or you can do whatever you
 * want, such as creating a dialog that lets
 * the user enter more sophisticated input to
 * the debug item, or simply display more info.
 */
void MMF2Func EditDebugItem(RD *rd, int ID)
{
#ifndef RUN_ONLY
/*
	switch(ID)
	{
	case DB::MyString:
		{
			EditDebugInfo dbi;
			char buffer[256];

			dbi.pText=buffer;
			dbi.lText=TEXT_MAX;
			dbi.pTitle=NULL;

			strcpy(buffer, rdPtr->text);
			long ret=callRunTimeFunction(rdPtr, RFUNCTION_EDITTEXT, 0, (LPARAM)&dbi);
			if (ret)
				strcpy(rdPtr->text, dbi.pText);
		}
		break;
/*	case DB::MyInt:
		{
			EditDebugInfo dbi;

			dbi.value=rdPtr->value;
			dbi.pTitle=NULL;

			long ret=callRunTimeFunction(rdPtr, RFUNCTION_EDITINT, 0, (LPARAM)&dbi);
			if (ret)
				rdPtr->value=dbi.value;
		}
		break;
	}
*/
#endif
}
