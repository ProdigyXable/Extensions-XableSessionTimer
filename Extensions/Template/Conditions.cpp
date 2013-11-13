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
	if (x < 0 || x > ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionNames.size())
	{
		return false;
	}

	else if(((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_EntireGamePaused == false)
	{
		return !((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_PauseStates[x];
	}

	else
	{
		return false;
	}
}

bool Extension::IsGameSessionActive()
{
	return !((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_EntireGamePaused;
}

bool Extension::FrameModulus(int modulus)
{

	if(((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_EntireGamePaused != true &&
		((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_EntireGamePaused != false)
	{
		((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_FrameCounter = 0;
	}

	if  (((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_FrameCounter % modulus == 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}