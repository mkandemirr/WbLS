#include "PPOBuilder.hh"
#include "G4Material.hh"
#include "MaterialPropertiesTable.hh"
#include "G4UImanager.hh"
#include "G4NistManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PPOBuilder::PPOBuilder():
VMaterialBuilder(false) 
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PPOBuilder::~PPOBuilder()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4Material* PPOBuilder::Build()          
{ 
  G4Material* ppo = new G4Material("PPO", 1.06*g/cm3, 4);
  ppo->AddElement(pNistManager->FindOrBuildElement("C"), 0.8142);
  ppo->AddElement(pNistManager->FindOrBuildElement("H"), 0.0501);
  ppo->AddElement(pNistManager->FindOrBuildElement("N"), 0.0633);
  ppo->AddElement(pNistManager->FindOrBuildElement("O"), 0.0723);
	
	return ppo;
    
}

