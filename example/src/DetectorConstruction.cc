#include "DetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "MaterialPropertiesTable.hh"

#include "WbLSBuilder.hh"
#include "GdDopedWbLSBuilder.hh"
#include "WbLSFactory.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  G4NistManager* nistManager = G4NistManager::Instance();

  G4Material* worldMat = nistManager->FindOrBuildMaterial("G4_AIR");


  G4double worldSizeX = 100*cm;
  G4double worldSizeY = 100*cm;
  G4double worldSizeZ = 100*cm;
  auto worldBox = new G4Box("world", 
                            worldSizeX*0.5, 
                            worldSizeY*0.5, 
                            worldSizeZ*0.5
                            );
  
  auto worldLV  = new G4LogicalVolume(worldBox,worldMat,"WorldLV");            
                                                                               
  auto worldPV = new G4PVPlacement(nullptr,  // no rotation
                                  G4ThreeVector(),  // at (0,0,0)
                                  worldLV,          // its logical volume
                                  "WorldPV",        // its name
                                  nullptr,          // its mother  volume
                                  false,            // no boolean operations
                                  0,                // copy number
                                  true);            // checking overlaps
    
  
  // Simple box    filled with WbLS
  G4double simpleBoxSizeX = 50*cm;
  G4double simpleBoxSizeY = 50*cm;
  G4double simpleBoxSizeZ = 50*cm;
  
  auto simpleBox = new G4Box("simpleBox", 
                             simpleBoxSizeX*0.5, 
                             simpleBoxSizeY*0.5, 
                             simpleBoxSizeZ*0.5
                             );
  
  /* WbLS factory products 
  //pure WbLS
    wbls_1pct
    wbls_3pct
    wbls_5pct
    
    //gdDoped WbLS
    wbls_1pct_gd_01pct
    wbls_3pct_gd_01pct
    
    */
    
    G4bool enableOpticalProperty = true;
    
    G4Material* wbls = WbLSFactory::GetInstance()->
                         GetMaterial("wbls_1pct", enableOpticalProperty);
    
    
  /* 
  G4String path = "wbls/macros/pure/wbls_1pct.mac";
  WbLSBuilder wblsBuilder(path, true);
  G4Material* wbls = wblsBuilder.GetProduct();
  */
  
  /*
  G4String path = "wbls/macros/gdDoped/wbls_1pct_gd_01pct.mac";
  GdDopedWbLSBuilder* wblsBuilder = new GdDopedWbLSBuilder(path, true);                                                       
  G4Material* wbls = wblsBuilder->GetProduct();
  */
  
  G4cout<<*(G4Material::GetMaterialTable())<<G4endl;
  
  if (enableOpticalProperty)
    wbls->GetMaterialPropertiesTable()->DumpTable();
  
  
  auto simpleBoxLV = new G4LogicalVolume(simpleBox, wbls, "SimpleBoxLV");            
                                                                                
  auto simpleBoxPV = new G4PVPlacement(nullptr,  // no rotation
                                      G4ThreeVector(), // at (0,0,0)
                                      simpleBoxLV,     // its logical volume
                                      "simpleBoxPV",   // its name
                                      worldLV,         // its mother  volume
                                      false,           // no boolean operations
                                      0,               // copy number
                                      true);           // checking overlaps
 
  return worldPV;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


