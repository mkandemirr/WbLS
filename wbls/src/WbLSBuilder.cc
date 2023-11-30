#include "WbLSBuilder.hh"
#include "LABBuilder.hh"
#include "PPOBuilder.hh"
#include "WbLSBuilderMessenger.hh"
#include "G4Material.hh"
#include "MaterialPropertiesTable.hh"
#include "G4UImanager.hh"
#include "G4NistManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

WbLSBuilder::WbLSBuilder(G4String macroFilePath, G4bool enableOpticalProperty):
VMaterialBuilder(enableOpticalProperty),
mMacroFilePath{macroFilePath}, 
fMessenger{nullptr},
fLABFraction{0.},
fPPOFraction{0.},
fWaterFraction{0.}
{
  fMessenger = new WbLSBuilderMessenger(this);

  SetComponentsFractionWithAMacroFile();

  if (IsOpticalPropertyEnabled())
  {
    SetOpticalPropertiesWithAMacroFile(); 
  }
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

WbLSBuilder::WbLSBuilder
(
  G4double labFraction, 
  G4double ppoFraction, 
  G4double waterFraction
):
VMaterialBuilder(false), 
fMessenger{nullptr},
fLABFraction{labFraction},
fPPOFraction{ppoFraction},
fWaterFraction{waterFraction}
{
  fMessenger = new WbLSBuilderMessenger(this);      
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void WbLSBuilder::SetComponentsFractionWithAMacroFile()
{
  G4UImanager::GetUIpointer()->ExecuteMacroFile(mMacroFilePath);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void WbLSBuilder::SetOpticalPropertiesWithAMacroFile()
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

WbLSBuilder::~WbLSBuilder()
{
  if(fMessenger) 
    delete fMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4Material* WbLSBuilder::Build()          
{ 
  LABBuilder labBuilder;
  G4Material* lab = labBuilder.GetProduct();

  PPOBuilder ppoBuilder;
  G4Material* ppo = ppoBuilder.GetProduct();

  G4Material* water = pNistManager->FindOrBuildMaterial("G4_WATER");

  G4Material* wbLS = new G4Material("WbLS", 1.0*g/cm3, 3);
  wbLS->AddMaterial(lab, fLABFraction);
  wbLS->AddMaterial(ppo, fPPOFraction);
  wbLS->AddMaterial(water, fWaterFraction);

  return wbLS;
      
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//User Interface Commands
void WbLSBuilder::SetLABFraction(G4double labFraction)
{
  fLABFraction = labFraction;
}

void WbLSBuilder::SetPPOFraction(G4double ppoFraction)
{
  fPPOFraction = ppoFraction;
}

void WbLSBuilder::SetWaterFraction(G4double waterFraction)
{
  fWaterFraction = waterFraction;
}

