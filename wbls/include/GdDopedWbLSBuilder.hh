
#ifndef GdDopedWbLSBuilder_h
#define GdDopedWbLSBuilder_h 1

#include "VMaterialBuilder.hh"

class GdDopedWbLSBuilderMessenger;
class G4Material;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class GdDopedWbLSBuilder: public VMaterialBuilder{

  public:
    GdDopedWbLSBuilder(G4String macroFilePath, 
                       G4bool enableOpticalProperty = false
                      );
    
    //user interface commands are defined but
    //any default macro file does not called.
    GdDopedWbLSBuilder(G4double labFraction,
    									 G4double ppoFraction,
    									 G4double waterFraction,
    									 G4double gdFraction	
    									 );		
    									 
    virtual ~GdDopedWbLSBuilder();
    
		//User Interface Commands
		void SetLABFraction(G4double labFraction);
		void SetPPOFraction(G4double ppoFraction);
		void SetWaterFraction(G4double waterFraction);
		void SetGdFraction(G4double gdFraction);
	
	protected:
    virtual G4Material* Build() override;
    
	private:
		void SetComponentsFractionWithAMacroFile();
		void SetOpticalPropertiesWithAMacroFile();
	  
	  G4String mMacroFilePath;
	  
  	GdDopedWbLSBuilderMessenger* fMessenger;
  	
  	G4double fLABFraction;
  	G4double fPPOFraction;
  	G4double fWaterFraction;
  	G4double fGdFraction;
  	     
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

