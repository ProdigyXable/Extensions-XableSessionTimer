
/* Expressions.cpp
 * This is where you should define the
 * behavior of your expressions. Make sure
 * the parameters and return types match those
 * in the JSON exactly! Double check Extension.h
 * as well.
 */

#include "Common.h"


unsigned int Extension::GetFrameRate()
{
	return ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_FrameRate;
}

unsigned int Extension::GetOverAllSeconds()
{
	return	((((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_OverAllGameTime)/(((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_FrameRate));
}

int Extension::GetSessionSecondsbyIndex(unsigned int x)
{
	if(x >= 0 && x < (((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionTime.size()))
	{
		return	((((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionTime[x]) /(((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_FrameRate));
	}

	else
	{
		return -666;
	}
} 

char * Extension::GetSessionNameByIndex(unsigned int x)
{
	if(x >= 0 && x < (((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionTime.size()))
	{
		return	((((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionNames[x]));
	}
	else
	{
		return "No value stored at this index";
	}
}

int Extension::GetSessionIndexbyName(char * Name)
{
	unsigned int x = 0;
	bool Nothing = false;

	do
	{
		if(strcmp((((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionNames[x]), _strdup(Name)) == 0)
		{
			bool Nothing = true;
			return x;	
		}

		++x;
	}
	while(x < (((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionNames.size()) && Nothing == false);
	
	if(Nothing == false)
	{
		return -1;
	}

	else
	{
		return -2;
	}

}

int Extension::NumberofSessions()
{
	return (((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionTime.size());
}

int Extension::SessionState(unsigned int x)
{
	if(((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_EntireGamePaused == false)
	{
		if(((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_PauseStates[x] == false)
		{
			return 1;
		}

	}

	else if(((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_EntireGamePaused == true)
	{
		if(((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_PauseStates[x] == false)
		{
			return 2;
		}
	
	}


	else 
	{
		return 0;
	}

	return 0;
}

int Extension::GlobalSessionState()
{
	if(((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_EntireGamePaused == true)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

bool Extension::ReturnAutomation()
{
	return ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->automate;
}