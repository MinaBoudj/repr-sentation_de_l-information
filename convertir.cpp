#include<iostream>

//convertir les caractere en entier
int charToDecimal(char c){
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'Z') {
        return 10 + c - 'A';
    } else if (c >= 'a' && c <= 'z') {
        return 10 + c - 'a';
    } else {
        // Gérer les caractères non valides
        return -1;
    }
}

//convertir un entier en sa valeur en décimal
char DecimalToChar(int c){
     if (c < 10) {
            return '0' + c;
        } else if(c<=36){
            return 'A' + (c - 10);
        }else{
            return -1;
        }       
}

//convertire la chaine vers sa valeur en decimal
int  convertTo_Base10(std::string chaine, int base_depart){
    //utiliser Horner
    int result = 0;
    for (int i = 0; i < chaine.length(); i++) {
        result = result * base_depart + charToDecimal(chaine[i]);
    }
    std::cout<< "la valeur en base 10 est : " <<result << std::endl;
    return result;
}


//convertir de la valeur en décimal vers la base demander
std::string convertFrom_Base10(int chaine, int base_arrive){
    std::string result = "";
    //diviser par la base_arrivee et stocker le reste dans une chaine
    while(chaine >= base_arrive){
        int reste = chaine % base_arrive;
        chaine = chaine / base_arrive;
        result = DecimalToChar(reste) + result; //erreur dans la fonction DecimalToChar
    }
    if(chaine != 0){
        result = DecimalToChar(chaine) + result;
    }
    return result;
}


std::string base_converter(std::string chaine, int base_depart, int base_arrive){
    if(base_depart<2 || base_depart >36 || base_arrive <2 || base_arrive>36)
        return "Erreur ! numéro de base incorrect";
    else if(base_arrive == base_depart)
        return chaine;
        else if(base_depart == 10)
            return convertFrom_Base10(std::stoi(chaine),base_arrive);
            else {
                int result = convertTo_Base10(chaine, base_depart);
                return convertFrom_Base10(result, base_arrive);
            }
}

int main(){
    std::string chaine = "3eh12";
    int base_depart = 18;
    int base_arrive = 30;

    std::string converted = base_converter(chaine, base_depart, base_arrive);
    std::cout << " "<< chaine<< " en base "<< base_depart<< " égale à " << converted << " en base "<< base_arrive << "." << std::endl;
}