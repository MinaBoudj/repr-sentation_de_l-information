/**
 * @author BOUDJEDIR AMINA
 * @date 3/10/2023
 * On souhaite calculer le plus précisément possible une somme S de nombres flottants en double précision se 
 * trouvant dans un tableau T de taille n : S = Σ Ti
 * On va comparer la qualité de differents algorithles de sommation.
*/
#include<iostream>
#include<algorithm> //pour std::sort

/*  La somme récursive  */
//on ajoute chacun des Ti dans un accu- mulateur dans l’ordre où ils apparaissent dans le tableau. 
int somme_recursive(int T[]){
    int accum = 0;
    for(auto each  : T)
        accum += each;
    return accum;
}

/* La somme récursive inverse */
//On inverse le tableau T et l’on applique une somme récursive sur le nouveau tableau.
int somme_recursive_inverse(int t[]){
    int cpt = 0;
    for(int i=sizeof(t) / sizeof(t[0]); i>=0; i--){
        cpt += t[i];     
    }
    return cpt;
}

/* Somme en valeurs (dé)croissante */
//On trie le tableau T dans l’ordre (dé)croissant des valeurs, puis l’on applique l’algorithme de somme récursive.
// Fonction de comparaison pour trier en ordre croissant
int compareCroissant(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int somme_croissante(int t[]){
    //trier d'abord le tableau dans l'ordre croissant
    //std::sort(t, sizeof(t)/sizeof(t[0]));
    qsort(t, sizeof(t)/sizeof(t[0]), sizeof(int), compareCroissant);
    return somme_recursive(t);
}

// Fonction de comparaison pour qsort (tri en ordre décroissant)
int compareDecroissant(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int somme_decroissante(int T[]){
    // Tri du tableau en ordre décroissant en utilisant la fonction de comparaison
    qsort(T, sizeof(T)/sizeof(T[0]), sizeof(int),compareDecroissant);

    return somme_recursive(T);
}

/* Somme en valeurs absolues (dé)croissantes */
//On trie le tableau T dans l’ordre (dé)croissant des valeurs absolues, puis l’on applique l’algorithme de somme récursive.
int absolutCamparCroissant(const void* a, const void* b){
    return abs((*(int*)a) - abs(*(int*)b));
}
int somme_abs_croisante(int T[]){
    qsort(T, sizeof(T)/sizeof(T[0]), sizeof(int), absolutCamparCroissant);
    somme_recursive(T);
}

int absolutCamparDecroissant(const void* a, const void* b){
    return abs((*(int*)b) - abs(*(int*)a));
}
int somme_abs_decroisante(int T[]){
    qsort(T, sizeof(T)/sizeof(T[0]), sizeof(int), absolutCamparDecroissant);
    somme_recursive(T);
}
