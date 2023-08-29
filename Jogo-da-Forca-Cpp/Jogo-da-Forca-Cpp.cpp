// Jogo-da-Forca-Cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>

int pontos = 0;
int random;

std::map<int, std::string> secreta;

bool retornaPalpite(char palpite, std::string palavra)
{
    bool estaCorreto = false;
    for (int i = 0; i <= palavra.size(); i++)
    {
        if (palavra[i] == toupper(palpite))
        {
            std::string s(1,palpite);
            estaCorreto = true;
            secreta[random].replace(i, 1, s);
            pontos += 1;
        }
    }
    return estaCorreto;
}

int main()
{
    setlocale(LC_ALL, "");

    int tentativas = 6;
    std::map<int, std::string> section;

    section[0] = "BANANA";
    section[1] = "APPLE";
    section[2] = "ORANGE";

    secreta[0] = "______";
    secreta[1] = "_____";
    secreta[2] = "______";


    char palpite;

    srand((unsigned)time(NULL)); //Seed para gerar um número aleatório

    random = rand() % 3; // Gera um número aleatório entre 0 e 2

    std::cout << "Jogo da Forca" << std::endl;

    //Game Loop
    while (tentativas >= 0)
    {

        std::cout << "Vidas = " << tentativas << std::endl;
        //std::cout << "Pontos = " << pontos << std::endl;

        for (int i = 0; i <= secreta[random].size(); i++)
        {
            std::cout << secreta[random][i];
        }

        std::cout << "\nQual o seu palpite? \n";
        std::cin >> palpite;

        if (!retornaPalpite(palpite, section[random]))
        {
            tentativas -= 1;
        }

        if (tentativas == 0)
        {
            char opt;
            system("cls");
            std::cout << "FIM DE JOGO\n";
            std::cout << "Deseja jogar novamente? s/n: ";
            std::cin >> opt;
            if (opt == 's' || opt == 'S')
            {
                tentativas = 6;
            }
            else break;
        }

        if (pontos == section[random].size())
        {
            char opt;
            system("cls");
            std::cout << "Você venceu\n";
            std::cout << "A palavra era " << section[random] << std::endl;
            std::cout << "Deseja jogar novamente? s/n: ";
            std::cin >> opt;
            if (opt == 's' || opt == 'S')
            {

                tentativas = 6;
                pontos = 0;

                secreta[0] = "______";
                secreta[1] = "_____";
                secreta[2] = "______";

            }
            else break;
        }
        system("cls");

    }

    return 0;

}
