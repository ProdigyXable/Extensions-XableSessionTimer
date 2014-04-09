
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
	return GlobalData->_FrameRate;
}

unsigned int Extension::GetOverAllSeconds()
{
	return	((GlobalData->_OverAllGameTime)/(GlobalData->_FrameRate));
}

int Extension::GetSessionSecondsbyIndex(unsigned int x)
{
	if(x >= 0 && x < (GlobalData->_SessionTime.size()))
	{
		return	((GlobalData->_SessionTime[x]) /(GlobalData->_FrameRate));
	}

	else
	{
		return -666;
	}
} 

const TCHAR * Extension::GetSessionNameByIndex(unsigned int x)
{
	if(x >= 0 && x < (GlobalData->_SessionTime.size()))
	{
		return	((GlobalData->_SessionNames[x]));
	}
	else
	{
		return (const TCHAR *)"No value stored at this index";
	}
}

unsigned int Extension::GetSessionIndexbyName(const TCHAR * Name)
{
	unsigned int x = 0;
	bool EmptyNothing = false;

	do
	{
		if(_tcscmp((GlobalData->_SessionNames[x]), _tcsdup(Name)) == 0)
		{
			bool EmptyNothing = true;
			return x;	
		}

		++x;
	}
	while(x < (GlobalData->_SessionNames.size()) && EmptyNothing == false);
	
	if(EmptyNothing == false)
	{
		return -1;
	}

	else
	{
		return -2;
	}

}

unsigned int Extension::NumberofSessions()
{
	return (GlobalData->_SessionTime.size());
}

unsigned int Extension::SessionState(unsigned int x)
{
	if(GlobalData->_EntireGamePaused == false)
	{
		if(GlobalData->_PauseStates[x] == false)
		{
			return 1;
		}

	}

	else if(GlobalData->_EntireGamePaused == true)
	{
		if(GlobalData->_PauseStates[x] == false)
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
	if(GlobalData->_EntireGamePaused == true)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

int Extension::ReturnAutomation()
{
	if(GlobalData->automate == true)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

int Extension::ReturnRefresh()
{
	if(GlobalData->refresh == true)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}