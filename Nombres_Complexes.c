#include<stdio.h> 

#include<ctype.h> 

#include <math.h> 

typedef struct complexe{ 

  float x; 
  float y; 
} Complexe; 

int main(){ 

     

     

  

    //float n1,n2; 

  

    Complexe a, b, s; 

     

    printf("\n************************** ADDITION DE NOMBRES COMPLEXES ********************************\n"); 

    printf("Donner les valeurs complexes a.x et a.y :"); 

    scanf("%f%f",&a.x,&a.y); 

     

    printf(" \n"); 

     

    printf("Donner les valeurs complexes b.x et b.y :"); 

    scanf("%f%f",&b.x,&b.y); 

  

    s.x=a.x+b.x; 

    s.y=a.y+b.y; 

  

    printf("Le couple du nombre complexe est (%0.2f,%0.2f\n)\n",s.x,s.y); 

  

    //printf("Le couple est : %f", addition_complexe(a,b)); 

    printf("\n************************** FIN ADDITION DE NOMBRES COMPLEXES ********************************\n"); 

     

    printf("\n"); 

  

    printf("\n************************** OPPOSE DE NOMBRES COMPLEXES **************************************\n"); 

  

    Complexe op; 

  

    op.x=-(a.x+b.x); 

    op.y=-(a.y+b.y); 

  

    printf("Le couple du nombre complexe est (%0.2f,%0.2f)\n",op.x,op.y); 

  

    printf("\n************************** FIN OPPOSE DE NOMBRES COMPLEXES **************************************\n"); 

     

  

    printf("\n************************** SOUSTARCTION DE NOMBRES COMPLEXES **************************************\n"); 

  

    Complexe soust; 

  

    soust.x=a.x-b.x; 

    soust.y=a.y-b.y; 

  

    printf("Le couple du nombre complexe est (%0.2f,%0.2f)\n",soust.x,soust.y); 

  

    printf("\n************************** FIN DE SOUSTARCTION DE NOMBRES COMPLEXES **************************************\n"); 

  

  

    printf("\n************************** MODULE DE NOMBRES COMPLEXES ***************************************************\n"); 

  

    Complexe module; 

  

    module.x=a.x*b.x; 

    if (module.x<0) 

    	module.x=-module.x; 

    module.y=a.y*b.y; 

    if (module.y<0) 

    	module.y=-module.y; 

  

    printf("Le couple du nombre complexe est (%0.2f,%0.2f)\n",module.x,module.y); 

  

    printf("\n************************** FIN MODULE DE NOMBRES COMPLEXES ***************************************************\n"); 

  

    printf("\n************************** MULTIPLICATION DE NOMBRES COMPLEXES ***************************************************\n"); 

  

    Complexe mult; 

  

    mult.x=a.x*b.x; 

    mult.y=a.y*b.y; 

     

    printf("Le couple du nombre complexe est (%0.2f,%0.2f,%0.2f)\n",mult.x,mult.y,2*mult.x*mult.y); 

  

    printf("\n************************** FIN DE MULTIPLICATION DE NOMBRES COMPLEXES ***************************************************\n"); 

  

  

    printf("\n************************** INVERSE DE NOMBRES COMPLEXES ***************************************************\n"); 

  

    Complexe inv; 

  

    inv.x=1/a.x+1/b.x; 

    inv.y=1/a.y+1/b.y; 

  

  

  

    printf("Le couple du nombre complexe est (%0.2f,%0.2f)\n",inv.x,inv.y); 

    printf("\n************************** FIN DE NOMBRES COMPLEXES ***************************************************\n"); 

  

  

  

  

    return 0; 

  

}