#include "GdDopedWbLSBuilderMessenger.hh"
#include "GdDopedWbLSBuilder.hh"


#include "G4UIdirectory.hh"
#include "G4UIcmdWithADouble.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GdDopedWbLSBuilderMessenger::GdDopedWbLSBuilderMessenger
(
  GdDopedWbLSBuilder* gdDopedWbLSBuilder
)
  : G4UImessenger(), fGdDopedWbLSBuilder(gdDopedWbLSBuilder)
{
 
	G4String commandDirectory = "/material/wbls/";
 
  //-------Command 1----------
  G4String commandName  = "labFraction";
  G4String commandPath  = commandDirectory+commandName;
  G4String usage        = "[usage] "+ commandPath + " LABFraction";
 
  fLABFractionCmd = new G4UIcmdWithADouble(commandPath, this);
  fLABFractionCmd->SetGuidance(usage);
  fLABFractionCmd->SetParameterName(commandName,false,false);
  fLABFractionCmd->AvailableForStates(G4State_PreInit, G4State_Init);
  fLABFractionCmd->SetToBeBroadcasted(false);

	//-------Command 2----------
  commandName ="ppoFraction";
  commandPath = commandDirectory+commandName;
  usage       = "[usage] "+ commandPath + " PPOFraction";
   
  fPPOFractionCmd = new G4UIcmdWithADouble(commandPath, this);
  fPPOFractionCmd->SetGuidance(usage);
  fPPOFractionCmd->SetParameterName(commandName,false,false);
  fPPOFractionCmd->AvailableForStates(G4State_PreInit, G4State_Init);
  fPPOFractionCmd->SetToBeBroadcasted(false);
  
  //-------Command 3----------
  commandName ="waterFraction";
  commandPath = commandDirectory+commandName;
  usage       = "[usage] "+ commandPath + " waterFraction";
   
  fWaterFractionCmd = new G4UIcmdWithADouble(commandPath, this);
  fWaterFractionCmd->SetGuidance(usage);
  fWaterFractionCmd->SetParameterName(commandName,false,false);
  fWaterFractionCmd->AvailableForStates(G4State_PreInit, G4State_Init);
  fWaterFractionCmd->SetToBeBroadcasted(false); 
 
  //-------Command 3----------
  commandName = "gdFraction";
  commandPath = commandDirectory+commandName;
  usage       = "[usage] "+ commandPath + " GdFraction";
  
  fGdFractionCmd = new G4UIcmdWithADouble(commandPath, this);
  fGdFractionCmd->SetGuidance(usage);
  fGdFractionCmd->SetParameterName(commandName,false,false);
  fGdFractionCmd->AvailableForStates(G4State_PreInit, G4State_Init);
  fGdFractionCmd->SetToBeBroadcasted(false);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GdDopedWbLSBuilderMessenger::~GdDopedWbLSBuilderMessenger()
{
	delete fLABFractionCmd;
  delete fPPOFractionCmd;
  delete fWaterFractionCmd;
  delete fGdFractionCmd;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GdDopedWbLSBuilderMessenger::SetNewValue(G4UIcommand* command, 
                                              G4String newValue
                                              )
{
	if(command == fLABFractionCmd)
  {
		fGdDopedWbLSBuilder->SetLABFraction(fLABFractionCmd->
		                                    GetNewDoubleValue(newValue));    
	  
  }else if(command == fPPOFractionCmd)
  {
  	fGdDopedWbLSBuilder->SetPPOFraction(fPPOFractionCmd->
                                        GetNewDoubleValue(newValue));
  
  }else if(command == fWaterFractionCmd)
  {
  	fGdDopedWbLSBuilder->SetWaterFraction(fWaterFractionCmd->
  	                                      GetNewDoubleValue(newValue));
  
  }else if (command == fGdFractionCmd)
  {
  	fGdDopedWbLSBuilder->SetGdFraction(fGdFractionCmd->
  	                                   GetNewDoubleValue(newValue));
  
  }  
  
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
