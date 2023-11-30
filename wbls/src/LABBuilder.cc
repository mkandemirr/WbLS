#include "LABBuilder.hh"
#include "G4Material.hh"
#include "MaterialPropertiesTable.hh"
#include "G4UImanager.hh"
#include "G4NistManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LABBuilder::LABBuilder():
VMaterialBuilder(false) 
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LABBuilder::~LABBuilder()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4Material* LABBuilder::Build()          
{ 
  //Linear alkyl benzene (LAB)
  
  G4int nElements  = 2;
  G4double density = 0.867*g/cm3;
  
  G4Material* C15H24 = new G4Material("C15H24",density,nElements);
  C15H24->AddElement(pNistManager->FindOrBuildElement("H"), 24);
  C15H24->AddElement(pNistManager->FindOrBuildElement("C"), 15);
  
  G4Material* C16H26 = new G4Material("C16H26",density,nElements);
  C16H26->AddElement(pNistManager->FindOrBuildElement("H"), 26);
  C16H26->AddElement(pNistManager->FindOrBuildElement("C"), 16);
  
  G4Material* C17H28 = new G4Material("C17H28",density,nElements);
  C17H28->AddElement(pNistManager->FindOrBuildElement("H"), 28);
  C17H28->AddElement(pNistManager->FindOrBuildElement("C"), 17);
  
  G4Material* C18H30 = new G4Material("C18H30",density,nElements);
  C18H30->AddElement(pNistManager->FindOrBuildElement("H"), 30);
  C18H30->AddElement(pNistManager->FindOrBuildElement("C"), 18);
  
  G4Material* C19H32 = new G4Material("C19H32",density,nElements);
  C19H32->AddElement(pNistManager->FindOrBuildElement("H"), 32);
  C19H32->AddElement(pNistManager->FindOrBuildElement("C"), 19);
  
  nElements = 5;
  G4Material* lab = new G4Material("LAB",density, nElements);
  lab->AddMaterial(C15H24, 0.012);
  lab->AddMaterial(C16H26, 0.204);
  lab->AddMaterial(C17H28, 0.432);
  lab->AddMaterial(C18H30, 0.334);
  lab->AddMaterial(C19H32, 0.018);
  
  return lab;
    
}

