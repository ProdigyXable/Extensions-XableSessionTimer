/* Actions.cpp
 * This is where you should define the
 * behavior of your actions. Make sure
 * the parameters match those in the JSON
 * exactly! Double check Extension.h
 * as well.
 */

#include "Common.h"

 void Extension::SetFrameRate(unsigned int x)
{
	if(GlobalData->_EntireGamePaused != true &&
		GlobalData->_EntireGamePaused != false)
	{
		Extension::UnPauseGameSession();
		GlobalData->_OverAllGameTime = 0;
		GlobalData->_FrameCounter = 0;

	}

	if(x >= 1)
	{
		GlobalData->_FrameRate = x;
	}

	else
	{
		GlobalData->_FrameRate = 1;
	}
	
}
 void Extension::IncreaseSessionTime()
{
	if( GlobalData->_EntireGamePaused == false)
	{
		for(unsigned int x = 0; x <	GlobalData->_SessionTime.size(); ++x)
		{
				if( GlobalData->_PauseStates[x] == false)
				{
					GlobalData->_SessionTime[x] = min(GlobalData->_SessionTime[x]+1, GlobalData->_OverAllGameTime+1);
				}		
		}
	}
}
 void Extension::IncreaseTotalTime()
{
	if( GlobalData->_EntireGamePaused == false)
	{
		GlobalData->_OverAllGameTime++;
	}
}
 void Extension::AddSession(const TCHAR * Name, unsigned int InitialNumber)
{
	
	GlobalData->_SessionTime.push_back(min(InitialNumber*GlobalData->_FrameRate, (GlobalData->_OverAllGameTime)));
	GlobalData->_SessionNames.push_back(_tcsdup(Name));
	GlobalData->_PauseStates.push_back(false);
} 
 void Extension::PauseSession(unsigned int x )
 {
	 if(x < GlobalData->_PauseStates.size() && x >= 0)
	 {
		GlobalData->_PauseStates[x] = true;
	 }
 }
 void Extension::UnPauseSession(unsigned int x)
 {
	 if(x < GlobalData->_PauseStates.size() && x >= 0)
	 {
		GlobalData->_PauseStates[x] = false;
	 }
 }
 void Extension::PauseGameSession()
 {
	 GlobalData->_EntireGamePaused = true;
 }
 void Extension::UnPauseGameSession()
 {
	GlobalData->_EntireGamePaused = false;
 }
 void Extension::ActiveNthSession(unsigned int x)
 {
	  if(x < GlobalData->_SessionTime.size() && x >= 0)
	 {
		++GlobalData->_SessionTime[x];
	 }

 }
 void Extension::SetNthSession(unsigned int x, int y)
 {
	  if(x < GlobalData->_SessionTime.size() && x >= 0)
	  {
		  if(y >= 0)
		  {
			  GlobalData->_SessionTime[x] = y*GlobalData->_FrameRate;
		  }
	  }
 }
 void Extension::SetGlobalSessiontoValue(int x)
 {
	 if(x >= 0)
	 {
		 GlobalData->_OverAllGameTime = x*GlobalData->_FrameRate;
	 }
 }
 void Extension::DeleteSession(unsigned int x)
 {
	 if(x >= 0 && x < GlobalData->_SessionTime.size())
	 {

		GlobalData->_SessionTime.erase(  GlobalData->_SessionTime.begin() + x  );
		GlobalData->_SessionNames.erase(  GlobalData->_SessionNames.begin() + x  );
		GlobalData->_PauseStates.erase(  GlobalData->_PauseStates.begin() + x  );
 
	 }
 }
 void Extension::ToggleSession(unsigned int x)
 {
	 if (x >=0 && x < GlobalData->_SessionTime.size())
	 {
		 GlobalData->_PauseStates[x] = !GlobalData->_PauseStates[x];
	 }
 }
 void Extension::ToggleGameSession()
 {
	 GlobalData->_EntireGamePaused = !(GlobalData->_EntireGamePaused);
 }
 void Extension::AutomateOn()
 {
	bool Check = false;
	if( GlobalData->automate == false)
	{
		Check = true;	
	}
	  
	GlobalData->automate = true;
 	
	  if(Check)
	  {
		  Runtime.GenerateEvent(5);
	  }
 }
 void Extension::AutomateOff()
 {
	bool Check = false;
	if( GlobalData->automate == true)
	{
		Check = true;
	}
	  
	GlobalData->automate = false;
 	
	  if(Check)
	  {
		  Runtime.GenerateEvent(5);
	  }
 }
 void Extension::AutomateToggle()
 {
	  GlobalData->automate = !( GlobalData->automate);
	
	  Runtime.GenerateEvent(5);
 }
 void Extension::RefreshOn()
 {
	bool Check = false;
	if( GlobalData->refresh == false)
	{
		Check = true;	
	}
	  
	GlobalData->refresh = true;
 	
	  if(Check)
	  {
		  Runtime.GenerateEvent(6);
	  }
 }
 void Extension::RefreshOff()
 {
	bool Check = false;
	if( GlobalData->refresh == true)
	{
		Check = true;
	}
	  
	GlobalData->refresh = false;
 	
	  if(Check)
	  {
		  Runtime.GenerateEvent(6);
	  }
 }
 void Extension::RefreshToggle()
 {
	  GlobalData->refresh = !( GlobalData->refresh);
	
	  Runtime.GenerateEvent(6);
 }