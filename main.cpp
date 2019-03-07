#include <iostream>
#include <string>   


// fonction qui convertit un entier digit inclus dans [0-9]
// en string correspondant à l'unité romaine
std::string convert_u(int digit){
    switch(digit){
        case 1 :  return "I";
        case 2 :  return "II";
        case 3 :  return "III";
        case 4 :  return "IV";
        case 5 :  return "V";
        case 6 :  return "VI";
        case 7 :  return "VII";
        case 8 :  return "VIII";
        case 9 :  return "IX";
    }
    return "";
}

// fonction qui convertit un entier digit inclus dans [0-9]
// en string correspondant à la dizaine romaine
std::string convert_d(int digit){
    switch(digit){
        case 1 :  return "X";
        case 2 :  return "XX";
        case 3 :  return "XXX";
        case 4 :  return "XL";
        case 5 :  return "L";
        case 6 :  return "LX";
        case 7 :  return "LXX";
        case 8 :  return "LXXX";
        case 9 :  return "XC";
    }
    return "";
}

// fonction qui convertit un entier digit inclus dans [0-9]
// en string correspondant à la centaine romaine
std::string convert_c(int digit)
{
    switch(digit){
        case 1 :  return "C";
        case 2 :  return "CC";
        case 3 :  return "CCC";
        case 4 :  return "CD";
        case 5 :  return "D";
        case 6 :  return "DC";
        case 7 :  return "DCC";
        case 8 :  return "DCCC";
        case 9 :  return "CM";
    }
    return "";
}

// fonction qui retourne un string comprenant un nombre de M 
// équivalent à digit
std::string convert_m(int digit){
    std::string res = "";

    if(digit > 0){
        for(int i = 0; i < digit; i++){
            res = res + "M";
        }
    }

    return res;
}

// fonction qui convertit un entier en nombre romain(string)
std::string get_rom_number(int digit)
{
    std::string romNumber = "";

    int u = digit % 10;
    int d = (digit / 10) % 10;
    int c = (digit / 100) % 10;
    int m = (digit / 1000) % 10;

    romNumber = convert_m(m) + convert_c(c) + convert_d(d) + convert_u(u);

    return romNumber;
}

int main()
{
    int digit;
    while(true){
        std::cout << "Entrer un nombre entier supérieur à 0 : ";
        std::cin >> digit; // saisir un entier au clavier

        //boucle pour gérer le cas quand une chaine de caractère est entrée
        while(std::cin.fail()) {
            std::cout << "                             résultat : " << "ERROR" << std::endl;
            std::cout << "Entrer un nombre entier supérieur à 0 : ";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> digit;
        }

        //un entier ne peut être convertis en chiffre romain que si il est supérieur à 0
        if(digit > 0){
            std::string message = get_rom_number(digit);
            std::cout << "                             résultat : " << message << std::endl;
        }
        else{
            std::cout << "                             résultat : " << "ERROR" << std::endl;
        }
    }

  return 0;
}












