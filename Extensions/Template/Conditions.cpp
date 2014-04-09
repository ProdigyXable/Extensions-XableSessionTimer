/* Conditions.cpp
 * This is where you should define the
 * behavior of your conditions. Make sure
 * the parameters and return types match those
 * in the JSON exactly! Double check Extension.h
 * as well.
 */

#include "Common.h"

bool Extension::IsSessionActive(unsigned int x)
{
	if (x < 0 || x > GlobalData->_SessionNames.size())
	{
		return false;
	}

	else if(GlobalData->_EntireGamePaused == false)
	{
		return !GlobalData->_PauseStates[x];
	}

	else
	{
		return false;
	}
}
bool Extension::IsGameSessionActive()
{
	return !GlobalData->_EntireGamePaused;
}
bool Extension::FrameModulus(unsigned int modulus)
{

	if(GlobalData->_EntireGamePaused != true &&
		GlobalData->_EntireGamePaused != false)
	{
		GlobalData->_FrameCounter = 0;
	}

	if  (GlobalData->_FrameCounter % modulus == 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}
bool Extension::ImmediateFrameModulus(unsigned int modulus)
{
	if(GlobalData->_EntireGamePaused != true &&
		GlobalData->_EntireGamePaused != false)
	{
		GlobalData->_FrameCounter = 0;
	}

	if  (GlobalData->_FrameCounter % modulus == 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}
bool Extension::AutomationTest()
{
	if( GlobalData->automate == true)
	{
		return true;
	}

	else
	{
		return false;
	}
}
bool Extension::AutomationChanged()
{
	return true;
}
bool Extension::RefreshTest()
{
	if( GlobalData->refresh == true)
	{
		return true;
	}

	else
	{
		return false;
	}
}
bool Extension::RefreshChanged()
{
	return true;
}