#include "WbLSFactory.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"

#include "WbLSBuilder.hh"
#include "GdDopedWbLSBuilder.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

WbLSFactory* WbLSFactory::fInstance = nullptr;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

WbLSFactory::WbLSFactory():
VMaterialFactory()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

WbLSFactory::~WbLSFactory()
{	
 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4Material* WbLSFactory::CreateMaterial(const G4String& name, 
                                        G4bool enableOpticalProperty
                                       )
{
  G4String macroFileName = name; //file name equal to product name
  G4String macrosDirectoryPath{};
  G4String macroFilePath{};
  
  if (name == "wbls_1pct" || name == "wbls_3pct" || name == "wbls_5pct" )
  {
    macrosDirectoryPath = "wbls/macros/pure/";  
    macroFilePath       = macrosDirectoryPath + macroFileName + ".mac"; 
    WbLSBuilder builder(macroFilePath, enableOpticalProperty);
    return builder.GetProduct();
  }else if (name == "wbls_1pct_gd_01pct" || name == "wbls_3pct_gd_01pct" )
  {
    macrosDirectoryPath = "wbls/macros/gdDoped/";
    macroFilePath       = macrosDirectoryPath + macroFileName + ".mac";
    GdDopedWbLSBuilder builder(macroFilePath, enableOpticalProperty);
    return builder.GetProduct();
  }
  else
  {
    return nullptr;
  }
   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

WbLSFactory* WbLSFactory::GetInstance()
{
  static WbLSFactory instance;
  
  if(fInstance == nullptr)
  {
    fInstance = &instance;
  }
    
  return fInstance;
   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

