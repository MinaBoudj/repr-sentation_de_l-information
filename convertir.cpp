#include<iostream>

//convertir les caractere
int charToInt(char c){
    if(c>=0 && c<=9)
        return c;
    else
        return c - 'A' + 10;    
}

//convertire la chaine vers sa valeur en decimal
void  convertTo_Base10(std::string chaine, int base_depart){
    //utiliser Horner
}


//convertir de la valeur en décimal vers la base demander
std::string convertFrom_Base10(std::string chaine, int base_arrive){
    std::string result = "";
    //diviser par la base_arrivee et stocker le reste dans une chaine

    return result;
}


std::string base_converter(std::string chaine, int base_depart, int base_arrive){
    if(base_depart != 10){ //la base de départ différente de la base 10
        convertTo_Base10(chaine, base_depart);
    }
    if(base_arrive == 10)
        return chaine;
    else 
        return convertFrom_Base10(chaine, base_arrive);
}

int main(){
    std::string chaine = "A1";
    int base_depart = 16;
    int base_arrive = 10;

    std::cout << "debut " << std::endl;
    std::string converted = base_converter(chaine, base_depart, base_arrive);
    std::cout << "Fin" << std::endl;
}