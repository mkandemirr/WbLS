#ifndef WbLSBuilderMessenger_h
#define WbLSBuilderMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"


class G4UIdirectory;
class G4UIcmdWithADouble;
class WbLSBuilder;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class WbLSBuilderMessenger : public G4UImessenger {
public:
    WbLSBuilderMessenger(WbLSBuilder*);
    ~WbLSBuilderMessenger();
    
    void SetNewValue(G4UIcommand*, G4String) override;

private:
 
 		WbLSBuilder* fWbLSBuilder;
 		
    G4UIcmdWithADouble* fLABFractionCmd;
    G4UIcmdWithADouble* fPPOFractionCmd;
    G4UIcmdWithADouble* fWaterFractionCmd;
   
};
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
#endif
