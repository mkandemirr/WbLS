#ifndef WbLSFactory_h
#define WbLSFactory_h 1

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "VMaterialFactory.hh"

class VMaterialBuilder;
class G4Material;

//singleton class
class WbLSFactory: public VMaterialFactory
{
  public:
    static WbLSFactory* GetInstance();
    
    //Singletons should not be cloneable.
    WbLSFactory(const WbLSFactory&) = delete;
    
    //Singletons should not be assignable.
    WbLSFactory& operator=(const WbLSFactory&) = delete;
       
  protected:  
    WbLSFactory();
    virtual ~WbLSFactory();
      
    virtual G4Material* CreateMaterial(const G4String& name, 
                                       G4bool enableOpticalProperty
                                       ) override;
      
  private:
    static WbLSFactory* fInstance;  
                 
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif 
