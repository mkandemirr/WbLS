
#ifndef LABBuilder_h
#define LABBuilder_h 1

#include "VMaterialBuilder.hh"

class G4Material;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class LABBuilder: public VMaterialBuilder{

  public:
    LABBuilder(); 
    virtual ~LABBuilder();

  protected:
    virtual G4Material* Build() override;
       
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

