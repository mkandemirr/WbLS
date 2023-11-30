#ifndef GdDopedWbLSBuilderMessenger_h
#define GdDopedWbLSBuilderMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"


class G4UIdirectory;
class G4UIcmdWithADouble;
class GdDopedWbLSBuilder;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class GdDopedWbLSBuilderMessenger : public G4UImessenger {
  public:
    GdDopedWbLSBuilderMessenger(GdDopedWbLSBuilder*);
    ~GdDopedWbLSBuilderMessenger();
    
    void SetNewValue(G4UIcommand*, G4String) override;

  private:
    GdDopedWbLSBuilder* fGdDopedWbLSBuilder;
     
    G4UIcmdWithADouble* fLABFractionCmd;
    G4UIcmdWithADouble* fPPOFractionCmd;
    G4UIcmdWithADouble* fWaterFractionCmd;
    G4UIcmdWithADouble* fGdFractionCmd;
   
};
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
#endif
