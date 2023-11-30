#include "GdDopedWbLSBuilder.hh"
#include "LABBuilder.hh"
#include "PPOBuilder.hh"
#include "GdDopedWbLSBuilderMessenger.hh"

#include "G4Material.hh"
#include "MaterialPropertiesTable.hh"
#include "G4UImanager.hh"
#include "G4NistManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GdDopedWbLSBuilder::GdDopedWbLSBuilder(G4String macroFilePath, 
																			 G4bool enableOpticalProperty
																			 )
: VMaterialBuilder(enableOpticalProperty), 
mMacroFilePath{macroFilePath},
fMessenger{nullptr},
fLABFraction{0.},
fPPOFraction{0.},
fWaterFraction{0.},
fGdFraction{0.} 
{	
	
	fMessenger = new GdDopedWbLSBuilderMessenger(this);
	
	SetComponentsFractionWithAMacroFile();
	
	if (IsOpticalPropertyEnabled())
  {
    SetOpticalPropertiesWithAMacroFile(); 
  }
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GdDopedWbLSBuilder::GdDopedWbLSBuilder(G4double labFraction,
																			 G4double ppoFraction,
																			 G4double waterFraction,
																			 G4double gdFraction	
																			)
: VMaterialBuilder(false), 
fMessenger{nullptr},
fLABFraction{labFraction},
fPPOFraction{ppoFraction},
fWaterFraction{waterFraction},
fGdFraction{gdFraction} 
{
	fMessenger = new GdDopedWbLSBuilderMessenger(this);  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GdDopedWbLSBuilder::SetComponentsFractionWithAMacroFile()
{
  G4UImanager::GetUIpointer()->ExecuteMacroFile(mMacroFilePath);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GdDopedWbLSBuilder::SetOpticalPropertiesWithAMacroFile()
{
	pMatPropTable = new MaterialPropertiesTable("wbls");
	
	{ //Delete ".mac " from mMacroFilePath
	  G4String substring = ".mac";
	  std::size_t initPos = mMacroFilePath.find(substring); 
    if (initPos != std::string::npos)
      mMacroFilePath.erase(initPos, substring.length()); 
	}
	
	mMacroFilePath = mMacroFilePath + "_Optic.mac";
	G4UImanager::GetUIpointer()->ExecuteMacroFile(mMacroFilePath);
	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GdDopedWbLSBuilder::~GdDopedWbLSBuilder()
{
	if(fMessenger) delete fMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4Material* GdDopedWbLSBuilder::Build()          
{ 
  LABBuilder labBuilder;
	G4Material* lab = labBuilder.GetProduct();
	
	PPOBuilder ppoBuilder;
	G4Material* ppo = ppoBuilder.GetProduct();
	
  G4Material* water = pNistManager->FindOrBuildMaterial("G4_WATER");
  G4Material*	gd 		= pNistManager->FindOrBuildMaterial("G4_Gd");
  
  G4Material* gdDopedWbLS = new G4Material("GdDopedWbLS", 1.0*g/cm3, 4);
	gdDopedWbLS->AddMaterial(lab, fLABFraction);
	gdDopedWbLS->AddMaterial(ppo, fPPOFraction);
	gdDopedWbLS->AddMaterial(water, fWaterFraction);
	gdDopedWbLS->AddMaterial(gd, fGdFraction);
	
	return gdDopedWbLS;    

}


//User Interface Commands
void GdDopedWbLSBuilder::SetLABFraction(G4double labFraction)
{
	fLABFraction = labFraction;
}

void GdDopedWbLSBuilder::SetPPOFraction(G4double ppoFraction)
{
	fPPOFraction = ppoFraction;
}

void GdDopedWbLSBuilder::SetWaterFraction(G4double waterFraction)
{
	fWaterFraction = waterFraction;
}

void GdDopedWbLSBuilder::SetGdFraction(G4double gdFraction)
{
	fGdFraction = gdFraction;
}

