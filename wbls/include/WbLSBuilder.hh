
#ifndef WbLSBuilder_h
#define WbLSBuilder_h 1

#include "VMaterialBuilder.hh"

class WbLSBuilderMessenger;
class G4Material;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class WbLSBuilder: public VMaterialBuilder{

  public: 
    WbLSBuilder(G4String macroFilePath,
                G4bool enableOpticalProperty = false
               );
                
    //user interface commands are defined but
    //any default macro file does not called.
    WbLSBuilder(G4double labFraction, 
    						G4double ppoFraction, 
    						G4double waterFraction
    					 ); 
    
    virtual ~WbLSBuilder();

		//User Interface Commands
		void SetLABFraction(G4double labFraction);
		void SetPPOFraction(G4double ppoFraction);
		void SetWaterFraction(G4double waterFraction);
		
	protected:
    virtual G4Material* Build() override;
    
	private:
		void SetComponentsFractionWithAMacroFile();
		void SetOpticalPropertiesWithAMacroFile();
    
    G4String mMacroFilePath;
    	  
  	WbLSBuilderMessenger* fMessenger;
  	
  	G4double fLABFraction;
  	G4double fPPOFraction;
  	G4double fWaterFraction;
  	     
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

