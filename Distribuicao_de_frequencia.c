#include <stdio.h> // biblioteca
#include <math.h> // biblioteca matemática
#define SEPARADOR -6
#define SEP -4
#define SEPARA -15

 int main(void)
{
    int n;//numeros de termos
    float k;// numero de classes
    printf("\ndigite quantidade de termos:");
    scanf("%d", &n);
    printf("\nquantidade de termos: %d", n);
    k = 1 + (3.3*(log10(n)));
    int x = round(k);
    printf("\nquantidade de classes: %d\n",x);
 

   int i,l,posmaior,posmenor;
 float h, valor[n], maior, menor;
 
 printf("\ndigite cada valor:\n");
 
 //prencher valor
for ( i=0;i<n;i++){//de i igual a 0 até i menor que 10 vai se repetir somando 1 a i
    scanf("%f\n", &valor[i]);//
}

 //encontrar o maior valor e sua posição
 maior = valor[0];
 posmaior = 0;
 for ( i=1;i<n;i++){
    if(valor[i] > maior){
        maior = valor[i];
        posmaior = i;
       
    }
 } 

 //encontrar menor valor e sua posição
 menor = valor[0];
 posmenor = 0;
 for ( i=1;i<n;i++){
    if(valor[i] < menor){
        menor = valor[i];
        posmenor = i;
    }
 } 

 //cálculo amplitude
 float c=x;
 h =(maior-menor)/x;
 float prova = menor+x*h;
 if(prova > maior){
 h=h;
 }
 else{
 h= h + 0.1;
    }
 float amplitude = h;

//distribuição de classes
 float classeini[x],classefim[x],compara;
 float fi[x], fre[x], Fac[x];
 
 
 for (i=1;i<=x;i++){
     classeini[i] = menor+(i-1)*amplitude;
     classefim[i] =menor+i*amplitude;
    } 

    for (i=1;i<=x;i++){
      fre[i] = 0;
      fi[i] = 1;
      Fac[i] = 0;
    }
    //frequencia absoluta
        for (i=1;i<=x;i++){
            for(l=0;l<=n;l++){
             compara = valor[l];   
                if((compara>=classeini[i])&&(compara<classefim[i])){
                 fre[i]= fi[i]++;
                } 
            }  
        }

    //frequência absoluta acumulada
    Fac[1] = fre[1];
      for (i=1;i<=x;i++){
        Fac[i+1] = Fac[i] + fre[i+1];
      }
    fre[1] = Fac[1];

 float fri[x],Fri[i];
    for (i=1;i<=x;i++){
      fri[i] = 0;
      Fri[i] = 0;
    }
    //frequência relativa
      for (i=1;i<=x;i++){
        fri[i] = (fre[i]*100)/n;
      }

    //frequência relativa acumulada
    Fri[1] = fri[1];
      for (i=1;i<=x;i++){
        Fri[i+1] = Fri[i] + fri[i+1];
      }
    fri[1] = Fri[1];

     printf("\nMaior valor posi. %d:%.2f\n",posmaior,maior);
     printf("\nMenor valor posi. %d:%.2f\n",posmenor,menor);
     printf("\namplitude :%.2f\n",amplitude);
        for ( i=0;i<n;i++){
          printf("posição %d:%.2f\n",i,valor[i]);
        }
    printf("\n%*s|%*s|%*s|%*s|%*s|%*s|\n", 
        SEPARADOR, "posi.",
        SEPARA, "     classe", 
        SEP, " fi", 
        SEP, "Fac", 
        SEPARADOR, " fri",
        SEPARADOR, " Fri"
    );

        for ( i=1;i<=x;i++){
          printf("%*d|%*.2f|--%*.2f|%*.0f|%*.0f|%*.2f|%*.2f|\n",
          SEPARADOR, (i),
          SEPARADOR, classeini[i],
          SEPARADOR, classefim[i],
          SEP, fre[i],
          SEP, Fac[i],
          SEPARADOR, fri[i],
          SEPARADOR, Fri[i]
          );
        }
        /*for ( i=1;i<=x;i++){
          printf("fi%d: %.0f\n",(i),fre[i]);
        }
        for ( i=1;i<=x;i++){
          printf("Fac%d: %.0f\n",(i),Fac[i]);
        }
        for ( i=1;i<=x;i++){
          printf("fri%d: %.1f\n",(i),fri[i]);
        }
        for ( i=1;i<=x;i++){
          printf("Fri%d: %.1f\n",(i),Fri[i]);
        }*/
getchar();      
return 0;
}
