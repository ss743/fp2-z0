Ncf=c(1,1,3,3)
Gf=1.16637*10^(-5)
Mz=91.188
If3=c(-1/2,1/2,-1/2,1/2)
Qf=c(-1,0,-1/3,2/3)
sin2w=0.23116

sGf=0.00001*10^(-5)
sMz=0.002
ssin2w=0.00013

gfv=If3-2*Qf*sin2w
gfa=If3

sgfv=2*Qf*ssin2w

gammaF=Ncf/(12*pi)*sqrt(2)*Gf*Mz^3*(gfv^2+gfa^2)

sgammaF=gammaF*sqrt((sGf/Gf)^2+(3*sMz/Mz)^2+(2*gfv*sgfv/(gfv^2+gfa^2))^2)

print(gammaF)
print(sgammaF)

gammaTot=3*gammaF[1]+3*gammaF[2]+3*gammaF[3]+2*gammaF[4]
sgammaTot=sqrt((3*sgammaF[1])^2+(3*sgammaF[2])^2+(3*sgammaF[3])^2+(2*sgammaF[1])^4)

gammaHad=3*gammaF[3]+2*gammaF[4]
sgammaHad=sqrt((3*sgammaF[3])^2+(2*sgammaF[1])^4)

gammaLep1=3*gammaF[1]
sgammaLep1=3*sgammaF[1]

gammaLep2=3*gammaF[2]
sgammaLep2=3*sgammaF[2]

sigmaP=0.3894*10^6*12*pi/Mz^2*gammaF[1]*gammaF/gammaTot^2
ssigmaP=sigmaP*sqrt((2*sMz/Mz)^2+(sgammaF[1]/gammaF[1])^2+(sgammaF/gammaF)^2+(2*sgammaTot/gammaTot)^2)

sigmaL=0.3894*10^6*12*pi/Mz^2*gammaF[1]*gammaLep1/gammaTot^2
ssigmaL=sigmaL*sqrt((2*sMz/Mz)^2+(sgammaF[1]/gammaF[1])^2+(sgammaLep1/gammaLep1)^2+(2*sgammaTot/gammaTot)^2)

sigmaNu=0.3894*10^6*12*pi/Mz^2*gammaF[1]*gammaLep2/gammaTot^2
ssigmaNu=sigmaNu*sqrt((2*sMz/Mz)^2+(sgammaF[1]/gammaF[1])^2+(sgammaLep2/gammaLep2)^2+(2*sgammaTot/gammaTot)^2)

sigmaQ=0.3894*10^6*12*pi/Mz^2*gammaF[1]*gammaHad/gammaTot^2
ssigmaQ=sigmaQ*sqrt((2*sMz/Mz)^2+(sgammaF[1]/gammaF[1])^2+(sgammaHad/gammaHad)^2+(2*sgammaTot/gammaTot)^2)

sigmaE=0.3894*10^6*12*pi/Mz^2*gammaF[1]^2/gammaTot^2
ssigmaE=sigmaE*sqrt((2*sMz/Mz)^2+(2*sgammaF[1]/gammaF[1])^2+(2*sgammaTot/gammaTot)^2)

#Aenderung bei weiterem leichten Fermionenpaar
p=(gammaF[1]+gammaF[2])/gammaTot
sp=p*sqrt((sgammaTot/gammaTot)^2+(sgammaF[1]^2+sgammaF[2]^2/(gammaF[1]+gammaF[2])^2))

BRl=divide(c(gammaLep1,sgammaLep1),c(gammaTot,sgammaTot))
BRn=divide(c(gammaLep2,sgammaLep2),c(gammaTot,sgammaTot))
BRq=divide(c(gammaHad,sgammaHad),c(gammaTot,sgammaTot))