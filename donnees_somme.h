/*
  donnees_somme.h --- Fichier de données pour l'exercice 1.3 du TP 1 
  X5I0030 (Architecture des ordinateurs).
  
 */


#ifndef __donnees_somme_h__
#define __donnees_somme_h__

#include <stdint.h>

/* Workaround pour définir une *constante* autrement que par un #define */
enum szT { szT = 31 };

/*
  S = \sum T = 2.6
*/
const double T[szT] = 
  { 9007199254740992.0, 999999999999.9, -999999999998.9, 3.56, 12.8766, 
    0.0123, 999394.4453, 1265356.434536, 23.53, 7889.123, 0.00002145, 0.5, 
    0.06456, 1254534536.4574, -1254534536.4575, -9007199254740992.0, 
    -999999999999.9, 999999999998.9, -3.56, -12.8766, -0.0123, 
    -999394.4453, -1265356.434536, -23.53, -7889.123, -0.00002145, 
    -0.5, -0.06456, -1254534536.4574, 1254534536.4575, 2.6 };

#endif /* __donnees_somme_h__ */
