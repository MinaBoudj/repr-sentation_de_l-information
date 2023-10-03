/**
 * @author Amina BOUDJEDIR
 * @date 3/10/2023
 * le code utilise l'encodage UTF-8
*/
#include<iostream>
#include<algorithm> //pour utiliser la fonction reversed

//Écrire le code d'une fonction strlength() prenant en entrée un objet de type std::string et retournant un compte correct du nombre de caractères qu’elle contient.
int strlength(std::string chaine){
    int cpt = 0;
    for(int i = 0; i<chaine.length(); i++){
        // Comparaison en hexadécimal : le bit le plus significatif doit être C0 ou supérieur,
        // et le bit suivant doit être 80 ou supérieur (10xxxxxx en binaire).
        if ((chaine[i] & 0xC0) != 0x80) 
            cpt++;
    }
    return cpt;
}

//Écrire une fonction std::string retourner(const std::string& s) retournant une chaîne contenant tous les caractères de s dans l’ordre inverse.
// La chaîne s est codée en UTF-8.
std::string retourner(const std::string& s) {
    std::string reversed = s;  // Copie de la chaîne d'origine
    std::reverse(reversed.begin(), reversed.end());  // Inversion de la copie
    return reversed;
}

int main(){
    std::string ch1 = "See you soon !" ;
    std::string ch2 = "A bientôt !" ;
    std::string s = "é";
    for(auto c : s){
        std::cout << int(c) << std::endl;
    }

    std::cout << "la taille de la chaine 1 :" << ch1.length() << std::endl;
    std::cout << "la taille de la chaine 2 en utilisant length():" << ch2.length() << std::endl;
    std::cout << "la vrai taille de la chaine 2 avec strlength() :" << strlength(ch2) << std::endl;

    std::cout << "la chaine : " << ch1 << " son inverse est : " << retourner(ch1) << std::endl; 

}