//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//      ----------------------------------------------------------------
//                      K600 Spectrometer (iThemba Labs)
//      ----------------------------------------------------------------
//
//      Github repository: https://www.github.com/KevinCWLi/K600
//
//      Main Author:    K.C.W. Li
//
//      email: likevincw@gmail.com
//

#include "PrimaryGeneratorAction.hh"

#include "G4RunManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"

#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4ThreeVector.hh"

#include "G4IonTable.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
fParticleGun(0)
{
    ///////////////////////////////////////////////////////////////
    //          To generate radioactive decay - enabled particles
    ///////////////////////////////////////////////////////////////
    
    G4int n_particle = 1;
    fParticleGun  = new G4ParticleGun(n_particle);
    
    //G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("He3");
    //G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("neutron");
    //G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("mu-");
    //G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("gamma");
    //G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("e-");
    //G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("alpha");
    //G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("proton");
    //G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("geantino");
    
    //fParticleGun->SetParticleDefinition(particleDefinition);
    
    //fParticleGun->SetParticleEnergy(1.*MeV);
    //fParticleGun->SetParticleEnergy(1.332*MeV);
    //fParticleGun->SetParticleEnergy(7.0*MeV);
    
    fParticleGun->SetParticleEnergy(170.*MeV);
    //fParticleGun->SetParticleEnergy(22.5*MeV);
    //fParticleGun->SetParticleEnergy(50.0*MeV);
    //fParticleGun->SetParticleEnergy(4*GeV);
    //fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(cos(14.03+35.), 0., sin(+35.)));
    
    //fParticleGun->SetParticlePosition(G4ThreeVector(0.,0.*m,1.90*m));
    //fParticleGun->SetParticlePosition(G4ThreeVector(0.,57.5*mm,1.6*m));
    fParticleGun->SetParticlePosition(G4ThreeVector((481.93-200.-50.)*cm, 0.*cm, (352.050-50.)*cm));
    //fParticleGun->SetParticlePosition(G4ThreeVector(0.,57.5*mm,2.10*m));
    
    //fParticleGun->SetParticlePosition(G4ThreeVector(0.,0.,1.));
    //fParticleGun->SetParticlePosition(G4ThreeVector(0.,0.,-1.*mm));
    //fParticleGun->SetParticlePosition(G4ThreeVector(2000.*mm,0.,3000.0*mm));
    
    //fParticleGun->SetParticlePosition(G4ThreeVector(-3.*m, 0., -3.8*m));
    
    
    
    ////////    4He, +2 charge
    //G4int Z = 2, A = 4;
     
    //G4double ionCharge   = 2.*eplus;
    //G4double excitEnergy = 0.*MeV;
     
    //G4ParticleDefinition* ion = G4ParticleTable::GetParticleTable()->GetIon(Z,A,excitEnergy);
    //G4ParticleDefinition* ion = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
    //ion->SetPDGLifeTime(1*ns);
    //fParticleGun->SetParticleDefinition(ion);
    //fParticleGun->SetParticleCharge(ionCharge);

    ////////    1H, +1 charge
    G4int Z = 1, A = 1;
     
    G4double ionCharge   = 1.*eplus;
    G4double excitEnergy = 0.*MeV;
     
    //G4ParticleDefinition* ion = G4ParticleTable::GetParticleTable()->GetIon(Z,A,excitEnergy);
    G4ParticleDefinition* ion = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
    //ion->SetPDGLifeTime(1*ns);
    fParticleGun->SetParticleDefinition(ion);
    fParticleGun->SetParticleCharge(ionCharge);

    
     /*
    VDC_CentrePositionX[0] = 481.93; // cm
    VDC_CentrePositionZ[0] = 352.050; // cm
    VDC_CentrePosition[0] = G4ThreeVector(VDC_CentrePositionX[0]*cm - 200.*cm, 0., VDC_CentrePositionZ[0]*cm - 100.*cm);
    VDC_RotationY[0] = -14.03; // deg;
    VDC_rotm[0].rotateY(VDC_RotationY[0]*deg);
     */
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete fParticleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
    
    
    ///////////////////////////////////////////////////////////////
    //          To generate radioactive decay - enabled particles
    ///////////////////////////////////////////////////////////////
    
    /*
     //G4int Z = 3, A = 11;
     //G4int Z = 6, A = 21;
     //G4int Z = 10, A = 18;
     //G4int Z = 11, A = 22;
     G4int Z = 27, A = 60;
     //G4int Z = 63, A = 152;
     
     G4double ionCharge   = 0.*eplus;
     G4double excitEnergy = 0.*MeV;
     
     //G4ParticleDefinition* ion = G4ParticleTable::GetParticleTable()->GetIon(Z,A,excitEnergy);
     G4ParticleDefinition* ion = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
     //ion->SetPDGLifeTime(1*ns);
     fParticleGun->SetParticleDefinition(ion);
     fParticleGun->SetParticleCharge(ionCharge);
     */
    
    /*
     ////////    4He, +1 charge
     G4int Z = 2, A = 4;
     
     G4double ionCharge   = 1.*eplus;
     G4double excitEnergy = 0.*MeV;
     
     //G4ParticleDefinition* ion = G4ParticleTable::GetParticleTable()->GetIon(Z,A,excitEnergy);
     G4ParticleDefinition* ion = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
     //ion->SetPDGLifeTime(1*ns);
     fParticleGun->SetParticleDefinition(ion);
     fParticleGun->SetParticleCharge(ionCharge);
     */
    
    
    ///////////////////////////////////////////////////
    //              TIME DISTRIBUTION                //
    ///////////////////////////////////////////////////
    
    /*
     initialclocktime = G4RandGauss::shoot( 0, 1.5);
     fParticleGun->SetParticleTime(initialclocktime*ns);
     */
    
    
    
    
    ///////////////////////////////////////////////////
    //       Initial Direction of Particle
    ///////////////////////////////////////////////////
    
    //      Flat Distribution
    //mx = G4RandFlat::shoot( -.15, .15);
    //my = G4RandFlat::shoot( -.15, .15);
    //mz = G4RandFlat::shoot( -1, 1);
    
    ////////////////////////////////
    ////    ISOTROPIC
    //      Exploiting the spherical symmetry of normal distributions
    //      Gaussian Distribution
    /*
     mx = G4RandGauss::shoot( 0, 1.);
     my = G4RandGauss::shoot( 0, 1.);
     mz = G4RandGauss::shoot( 0, 1.);
     
     if(mz<0) mz = -mz;
     //mz = abs(mz);
     //fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,-1.));
     //fParticleGun->SetParticleMomentumDirection(G4ThreeVector(mx, my, 10.));
     fParticleGun->SetParticleMomentumDirection(G4ThreeVector(mx, my, -mz));
     */
    
    ////    Alternative Method for ISOTROPY
    /*
    G4double theta = 2*M_PI*G4UniformRand();
    //G4double mz = -1.0 + 2*G4UniformRand();
    G4double mz = -1.0 + G4UniformRand();
    
    G4double a = sqrt(1-(mz*mz));
    
    mx = a*cos(theta);
    my = a*sin(theta);
    
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(mx, my, mz));
    */
    
    
    /*
     theta = M_PI*G4UniformRand();
     phi = 2*M_PI*G4UniformRand();
     fParticleGun->SetParticleMomentumDirection(G4ThreeVector(sin(theta*rad)*cos(phi*rad), sin(theta*rad)*sin(phi*rad), cos(theta*rad)));
     */
    
    
    
    ///////////////////////////////////////////////////
    //                  16O(a,a')
    ///////////////////////////////////////////////////
    /*
     G4double test = G4UniformRand();
     
     //if(test<=0.5) beamEnergy = G4RandGauss::shoot( 200, 0.5); // MeV
     //if(test>0.5) beamEnergy = G4RandGauss::shoot( 180, 0.5); // MeV
     
     if(test>0.0 && test<=0.1) beamEnergy = G4RandGauss::shoot( 215, 0.5); // MeV
     if(test>0.1 && test<=0.2) beamEnergy = G4RandGauss::shoot( 210, 0.5); // MeV
     if(test>0.2 && test<=0.3) beamEnergy = G4RandGauss::shoot( 200, 0.5); // MeV
     if(test>0.3 && test<=0.4) beamEnergy = G4RandGauss::shoot( 190, 0.5); // MeV
     if(test>0.4 && test<=0.5) beamEnergy = G4RandGauss::shoot( 180, 0.5); // MeV
     if(test>0.5 && test<=0.6) beamEnergy = G4RandGauss::shoot( 185, 0.5); // MeV
     if(test>0.6 && test<=0.7) beamEnergy = G4RandGauss::shoot( 170, 0.5); // MeV
     if(test>0.7 && test<=0.8) beamEnergy = G4RandGauss::shoot( 160, 0.5); // MeV
     if(test>0.8 && test<=0.9) beamEnergy = G4RandGauss::shoot( 150, 0.5); // MeV
     if(test>0.9 && test<=1.0) beamEnergy = G4RandGauss::shoot( 140, 0.5); // MeV
     
     //beamEnergy = G4RandGauss::shoot( 200, 0.5); // MeV
     //beamEnergy = 200; // MeV
     
     recoilExcitationEnergy = 15.097;  // MeV
     alphaSeperationEnergy = 7.16192;    // MeV
     protonSeperationEnergy = 12.1274;  // MeV
     //  Elastically scattered outgoing alpha
     mx = G4RandGauss::shoot( 0, 0.00001);
     my = G4RandGauss::shoot( 0, .05);
     //mx = G4RandGauss::shoot( 0, 0.00001);
     //my = G4RandGauss::shoot( 0, 0.00001);
     //mx = 0;
     //my = 0;
     
     fParticleGun->SetParticleMomentumDirection(G4ThreeVector(mx, my, 10.));
     energy = beamEnergy - recoilExcitationEnergy; // MeV
     fParticleGun->SetParticleEnergy(energy*MeV);
     fParticleGun->GeneratePrimaryVertex(anEvent);
     
     
     //////////////////////////////////////////////////////////////
     //                      16O -> 4He + 12C
     //////////////////////////////////////////////////////////////
     //  Alpha 0 isotropic decay:    15.097 MeV state of 16O -> to Ground state of 12C
     //  Alpha 1 anisotropic decay:  15.097 MeV state of 16O -> to 4.43891 MeV state of 12C
     //  Assuming recoil nucleus takes no kinetic energy from inelastic scatter
     
     G4double pAlphaDecayMode = G4UniformRand();
     
     if(pAlphaDecayMode<=0.5) alphaDecayMode = 0;
     if(pAlphaDecayMode>0.5) alphaDecayMode = 1;
     
     //alphaDecayMode = 1;
     
     ////    ALPHA 1
     if(alphaDecayMode == 0) daughterExcitationEnergy = 0; //    MeV
     
     ////    Alpha 0
     if(alphaDecayMode == 1) daughterExcitationEnergy = 4.43891; //    MeV
     
     mx = G4RandFlat::shoot( -1., 1.);
     my = G4RandFlat::shoot( -1., 1.);
     mz = G4RandFlat::shoot( -1., 1.);
     
     fParticleGun->SetParticleEnergy( (recoilExcitationEnergy - alphaSeperationEnergy - daughterExcitationEnergy)*(3/4)*MeV);
     
     fParticleGun->SetParticleMomentumDirection(ejectileDirection);
     
     fParticleGun->GeneratePrimaryVertex(anEvent);
     */
    
    
    ////    Recoil - 12C
    /*
     fParticleGun->SetParticleEnergy( (recoilExcitationEnergy - alphaSeperationEnergy - daughterExcitationEnergy)*(1/4)*MeV);
     
     recoilDirection = -ejectileDirection;
     fParticleGun->SetParticleMomentumDirection(recoilDirection);
     */
    
    /*
     Z = 6, A = 12;
     
     G4ParticleDefinition* recoil = G4IonTable::GetIonTable()->GetIon(Z, A, 4.43891*MeV);
     //G4ParticleDefinition* recoil = G4ParticleTable::GetParticleTable()->GetIon(Z, A, 0.*keV);
     fParticleGun->SetParticleCharge(0.*eplus);
     //recoil->SetPDGLifeTime(1*ns);
     //recoil->SetPDGStable(true);
     fParticleGun->SetParticleDefinition(recoil);
     
     fParticleGun->SetParticleEnergy( (recoilExcitationEnergy - alphaSeperationEnergy - daughterExcitationEnergy)*(1/4)*MeV);
     
     recoilDirection = -ejectileDirection;
     fParticleGun->SetParticleMomentumDirection(recoilDirection);
     */
    
    
    //fParticleGun->GeneratePrimaryVertex(anEvent);
    
    //G4double Lifetime = fParticleGun->GetParticleDefinition()->GetPDGLifeTime();
    //G4double Lifetime = recoil->GetPDGLifeTime();
    
    //G4cout << "Here is the alphaSeperationEnergy    "<< alphaSeperationEnergy << G4endl;
    
    
    
    ////     Gamma Decay - from Recoil Nucleus
    /*
     if(alphaDecayMode == 1)
     {
     G4ParticleDefinition* particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("gamma");
     fParticleGun->SetParticleDefinition(particleDefinition);
     
     fParticleGun->SetParticleEnergy(daughterExcitationEnergy*MeV);
     
     mx = G4RandFlat::shoot( -1., 1.);
     my = G4RandFlat::shoot( -1., 1.);
     mz = G4RandFlat::shoot( -1., 1.);
     fParticleGun->SetParticleMomentumDirection(G4ThreeVector(mx, my, mz));
     
     fParticleGun->GeneratePrimaryVertex(anEvent);
     }
     */
    
    
    ///////////////////////////////////////////////////
    //       Initial Position Distribution of Particle
    ///////////////////////////////////////////////////
    /*
    G4double targetThickness = 2.42; // um
    G4double InitialPosition = G4RandFlat::shoot(-(targetThickness/2), (targetThickness/2)); // um
    
    fParticleGun->SetParticlePosition(G4ThreeVector(0., 0., InitialPosition*um));
    */
    
    
    ///////////////////////////////////////////////////
    //       Initial Energy Distribution of Particle
    ///////////////////////////////////////////////////
    
    /*
    //G4double InitialEnergy = G4RandGauss::shoot(((12.049-7.16192)*(0.75)), ((1.5e-3)/2.3548));
    //G4double InitialEnergy = G4RandGauss::shoot(((12.049-7.16192)*(0.75)), 0.367);
    //G4double InitialEnergy = G4RandGauss::shoot(((12.049-7.16192)*(0.75)), 0.051);
    G4double InitialEnergy = G4RandGauss::shoot(((12.049-7.16192)*(0.75)), 0.12);
    
    //G4double InitialEnergy = ((12.049-7.16192)*(0.75)); // MeV
    
    //  Empirical
    //G4double InitialEnergy = G4RandGauss::shoot(2.96058e+00, ((1.5e-3)/2.3548));
    
    
    fParticleGun->SetParticleEnergy(InitialEnergy*MeV);
    */
    
    
    
    
    
    
    ////////////////////////////////////////////////////////
    //          PARTICLE INFORMATION OUTPUT
    ////////////////////////////////////////////////////////
    /*
     G4double Lifetime = fParticleGun->GetParticleDefinition()->GetPDGLifeTime();
     G4double Spin = fParticleGun->GetParticleDefinition()->GetPDGSpin();
     G4double Isospin = fParticleGun->GetParticleDefinition()->GetPDGIsospin();
     G4double Parity = fParticleGun->GetParticleDefinition()->GetPDGiGParity();
     G4String ParticleName = fParticleGun->GetParticleDefinition()->GetParticleName();
     
     
     
     G4cout << "Here is the Lifetime    "<< Lifetime << G4endl;
     G4cout << "Here is the Spin    "<< Spin << G4endl;
     G4cout << "Here is the Isospin    "<< Isospin << G4endl;
     G4cout << "Here is the Parity    "<< Parity << G4endl;
     G4cout << "Here is the ParticleName    "<< ParticleName << G4endl;
     */
    

    //create vertex
    //
    fParticleGun->GeneratePrimaryVertex(anEvent);
    
    
    
    /*
     // This function is called at the begining of event
     
     // In order to avoid dependence of PrimaryGeneratorAction
     // on DetectorConstruction class we get world volume
     // from G4LogicalVolumeStore
     //
     G4double worldZHalfLength = 0;
     G4LogicalVolume* worlLV
     = G4LogicalVolumeStore::GetInstance()->GetVolume("World");
     G4Box* worldBox = 0;
     if ( worlLV) worldBox = dynamic_cast< G4Box*>(worlLV->GetSolid());
     if ( worldBox ) {
     worldZHalfLength = worldBox->GetZHalfLength();
     }
     else  {
     G4ExceptionDescription msg;
     msg << "World volume of box not found." << G4endl;
     msg << "Perhaps you have changed geometry." << G4endl;
     msg << "The gun will be place in the center.";
     G4Exception("PrimaryGeneratorAction::GeneratePrimaries()",
     "MyCode0002", JustWarning, msg);
     }
     
     // Set gun position
     fParticleGun
     ->SetParticlePosition(G4ThreeVector(0., 0., -worldZHalfLength));
     
     fParticleGun->GeneratePrimaryVertex(anEvent);
     */
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

