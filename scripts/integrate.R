A<-216.194
B<-25.1515
res=integrate(function(x){A*(1+x^2)},-1,0.99)
res2=integrate(function(x){A*(1+x^2)+B*(1-x)^-2},-1,0.99)
r=res[[1]]/res2[[1]]
print(r)