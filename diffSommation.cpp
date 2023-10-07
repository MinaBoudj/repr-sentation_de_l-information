/**
 * @author BOUDJEDIR AMINA
 * @date 3/10/2023
 * On souhaite calculer le plus précisément possible une somme S de nombres flottants en double précision se 
 * trouvant dans un tableau T de taille n : S = Σ Ti
 * On va comparer la qualité de differents algorithles de sommation.
*/
#include<iostream>
#include<math.h>
#include<algorithm> //pour std::sort


/* Workaround pour définir une *constante* autrement que par un #define */
enum szT { szT = 31 };

/* Affichage d'un tableau de 'double's de taille sz � l'�cran */
void affiche_tableau(double T[]) 
{
  for (int i = 0; i < szT; ++i) {
    printf("%g ", T[i]);
  }
  printf("\n");
}

/*  La somme récursive  */
//on ajoute chacun des Ti dans un accu- mulateur dans l’ordre où ils apparaissent dans le tableau. 
double somme_recursive(double T[]){
    double accum = 0;
    for(int i=0; i<szT; i++){
        accum += T[i];     
    }
    return accum;
}

/* La somme récursive inverse */
//On inverse le tableau T et l’on applique une somme récursive sur le nouveau tableau.
double somme_recursive_inverse(double t[]){
    double cpt = 0;
    for(int i=szT-1; i>=0; i--){
        cpt += t[i];     
    }
    return cpt;
}
/* Fonction de comparaison de deux 'double's */
int croissant(const void *x, const void *y)
{
  /* Cast en le type effectif */
  double a = *(double*)(x);
  double b = *(double*)(y);

  if (a < b) {
    return -1;
  } else {
    if (a > b) {
      return 1;
    } else {
      return 0;
    }
  }
}

double somme_croissante(double t[]){
    //trier d'abord le tableau dans l'ordre croissant
    //std::sort(t, sizeof(t)/sizeof(t[0]));
    qsort(t, szT, sizeof(double), croissant);
    double somme = somme_recursive(t);
    return somme;
}

/* Fonction de comparaison de deux 'double's */
int decroissant(const void *x, const void *y)
{
  /* Cast en le type effectif */
  double a = *(double*)(x);
  double b = *(double*)(y);

  if (b < a) {
    return -1;
  } else {
    if (b > a) {
      return 1;
    } else {
      return 0;
    }
  }
}
double somme_decroissante(double T[]){
    // Tri du tableau en ordre décroissant en utilisant la fonction de comparaison
    qsort(T, szT, sizeof(double),decroissant);
    return somme_recursive(T);
}

/* Somme en valeurs absolues (dé)croissantes */
//On trie le tableau T dans l’ordre (dé)croissant des valeurs absolues, puis l’on applique l’algorithme de somme récursive.
int absolutCamparCroissant(const void* a, const void* b){
    return fabs((*(double*)a) - fabs(*(double*)b));
}
double somme_abs_croisante(double T[]){
    qsort(T, szT, sizeof(double), absolutCamparCroissant);
    return somme_recursive(T);
}

int absolutCamparDecroissant(const void* a, const void* b){
    return abs((*(double*)b) - abs(*(double*)a));
}
double somme_abs_decroisante(double T[]){
    qsort(T, szT, sizeof(double), absolutCamparDecroissant);
    return  somme_recursive(T);

}


int main(){
    double T[szT] = 
        { 9007199254740992.0, 999999999999.9, -999999999998.9, 3.56, 12.8766, 
            0.0123, 999394.4453, 1265356.434536, 23.53, 7889.123, 0.00002145, 0.5, 
            0.06456, 1254534536.4574, -1254534536.4575, -9007199254740992.0, 
            -999999999999.9, 999999999998.9, -3.56, -12.8766, -0.0123, 
            -999394.4453, -1265356.434536, -23.53, -7889.123, -0.00002145, 
            -0.5, -0.06456, -1254534536.4574, 1254534536.4575, 2.6 };
   
    std::cout<< "la somme récursive des valeurs de T est " << somme_recursive(T) << std::endl;
    std::cout << "la somme récursive inverse des valeurs de T est " << somme_recursive_inverse(T)<< std::endl;
    std::cout << "somme croissante : " << somme_croissante(T) << std::endl;
    std::cout << "somme decroissante : " << somme_decroissante(T) << std::endl;
    std::cout << "somme en valeur absolue croissante : " << somme_abs_croisante(T) << std::endl;
    std::cout << "somme en valeur absolue décroissante : " << somme_abs_decroisante(T) << std::endl;

    return 0;
}