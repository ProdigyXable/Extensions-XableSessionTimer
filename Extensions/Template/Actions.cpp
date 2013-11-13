/* Actions.cpp
 * This is where you should define the
 * behavior of your actions. Make sure
 * the parameters match those in the JSON
 * exactly! Double check Extension.h
 * as well.
 */

#include "Common.h"

 void Extension::SetFrameRate(int x)
{
	if(((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_EntireGamePaused != true &&
		((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_EntireGamePaused != false)
	{
		Extension::UnPauseGameSession();
		((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_OverAllGameTime = 0;
		((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_FrameCounter = 0;

	}

	if(x >= 1)
	{
		((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_FrameRate = x;
	}

	else
	{
		((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_FrameRate = 1;
	}
	
}
 void Extension::IncreaseSessionTime()
{
	if( ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_EntireGamePaused == false)
	{
		for(unsigned int x = 0; x <	((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionTime.size(); ++x)
		{
				if( ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_PauseStates[x] == false)
				{
					((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionTime[x] = min(((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionTime[x]+1, ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_OverAllGameTime+1);
				}		
		}
	}
}
 void Extension::IncreaseTotalTime()
{
	if( ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_EntireGamePaused == false)
	{
		++((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_OverAllGameTime;
	}
}
 void Extension::AddSession(char * Name, unsigned int InitialNumber)
{
	
	((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionTime.push_back(min(InitialNumber*((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_FrameRate, (((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_OverAllGameTime)));
	((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionNames.push_back(_strdup(Name));
	((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_PauseStates.push_back(false);
} 
 void Extension::PauseSession(unsigned int x )
 {
	 if(x < ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_PauseStates.size() && x >= 0)
	 {
		((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_PauseStates[x] = true;
	 }
 }
 void Extension::UnPauseSession(unsigned int x)
 {
	 if(x < ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_PauseStates.size() && x >= 0)
	 {
		((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_PauseStates[x] = false;
	 }
 }
 void Extension::PauseGameSession()
 {
	 ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_EntireGamePaused = true;
 }
 void Extension::UnPauseGameSession()
 {
	((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_EntireGamePaused = false;
 }
 void Extension::ActiveNthSession(unsigned int x)
 {
	  if(x < ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionTime.size() && x >= 0)
	 {
		++((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionTime[x];
	 }

 }
 void Extension::SetNthSession(unsigned int x, int y)
 {
	  if(x < ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionTime.size() && x >= 0)
	  {
		  if(y >= 0)
		  {
			  ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionTime[x] = y*((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_FrameRate;
		  }
	  }
 }
 void Extension::SetGlobalSessiontoValue(int x)
 {
	 if(x >= 0)
	 {
		 ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_OverAllGameTime = x*((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_FrameRate;
	 }
 }
 void Extension::DeleteSession(unsigned int x)
 {
	 if(x >= 0 && x < ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionTime.size())
	 {

		((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionTime.erase(  ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionTime.begin() + x  );
		((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionNames.erase(  ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionNames.begin() + x  );
		((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_PauseStates.erase(  ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_PauseStates.begin() + x  );
 
	 }
 }
 void Extension::ToggleSession(unsigned int x)
 {
	 if (x >=0 && x < ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_SessionTime.size())
	 {
		 ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_PauseStates[x] = !((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_PauseStates[x];
	 }
 }
 void Extension::ToggleGameSession()
 {
	 ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_EntireGamePaused = !(((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->_EntireGamePaused);
 }
 void Extension::AutomateOn()
 {
	  ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->automate = true;
 }
 void Extension::AutomateOff()
 {
	  ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->automate = false;
 }
 void Extension::AutomateToggle()
 {
	  ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->automate = !( ((Extension::OverAllGameData *)Runtime.ReadGlobal("My Global Data"))->automate);
 }