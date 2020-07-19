#include <stdlib.h>
#include <iostream>
#include <string>
#include <locale.h>

using namespace std;
//==================================VARIAVEIS=============================
int bossHissis = 0;
//===============ETC====================
int dayCount = 1;
//===============LOJA===================
int seletor_loja = 0, faca_count = 0, cortina_count = 0;
//====ITENS NO MENU====
//===========SELETORES, VENCER e FUGIR=========
int seletor = 0, seletor2 = 0, seletor_treino, seletor_bat = 0, seletor_bat_hab = 0, fugiu = 0;
bool venceuJogo = false;
//=========PERSONAGEM===========
int vida = 50, nv = 1,  def = 3, atk = 5, po = 0, TP = 5, exp = 0;
string nome;
//==========INIMIGOS=============
//Funkeiro
int funk_vida = 15, funk_def = 0, funk_atk = 7, exp_funk = 15, funk_po = 2;
const string funk_nome = "Funkeiro da Idade Media";

//Vitima
int vit_vida = 40, vit_def = 5, vit_atk = 17, exp_vit = 30, vit_atqCont = 1, vit_po = 5;
const string vit_nome = "Vítima do Hissis";
//HISSIS O BOSS
int hissis_vida = 752, hissis_def = 15, hissis_atk = 28, hissis_atqCount = 1, hissis_furia = 0;
const string hissis_nome = "Glognir, A Lança Flamejante";

//======BOSS=========
//HISSIS O TRAFICANTE DE FARINHA "INCOMPLETO"


//===========FUNÇÕES======================================================
int boss();
int loja();
string arma();
string armadura();
int fugir();
int habilidades();
int gainPo();
int expNivel();
int upNivel();
int batalhar();
int batalha();
int menu();
int dormir();
int treino();
int refNome();
//=============================================================================================
//=============================================================================================

int main ()
{
    setlocale(LC_ALL, "portuguese");
//==================================================INTRODUÇÃO===================================================================


    cout << "*********************************************RPG GENERICO**********************************************";

    cout << "\nEm mundo distante um garoto nasce e treina bastante para se tornar um guerreiro.";
    cout << "\nDevido seu treino extremamente árduo conseguiu conquistar bastante coisa, mas nunca era o suficiente.\n\n";

    system("pause");

    cout << "\nDigite o seu nome (Digite apenas um nome ou Não utilize espaçamento): ";
    cin >>  nome;
    //VAI MOSTRAR ALGUMA MENSAGEM DEPENDENDO DO NOME DIGITADO
    refNome();
    //=======================================================

    system("pause");

    cout << "\n\n ====AVISOS====\n\n";
    cout << "1- Muito cuidado para não escrever opções inválidas.";
    cout << "\n2- Jogo ainda está em desenvolvimento/completo por isso cuidado, bugs podem acontecer.";
    cout << "\n3- Não existe opção de voltar ainda, ou seja, escolha fazer algo se você estiver certo que é oque você quer.";
    cout << "\n4- TP: Train Points / PO: Ouro";
    cout << "\n5- Em batalhas contra BOSS você não pode fugir";
    cout << "\n6- Se você morrer é Fim de Jogo";
    cout << "\n7- A forma de escolher as opções são por numeros digitados dependendo da opção desejada.";
    cout << "\n8- Os treinamentos tem limite dependendo do seu ATK e DEF(17 e 15 Respectivamente), considere isso antes de comprar algo";
    cout << "\n9- NÃO COMPRE UM ITEM ESGOTADO NA LOJA, QUE FIQUE AVISADO";
    cout << "\n10- .....Bugs\n\n";

    system("pause");
//============================================================================================================================
//===============================================COMEÇO DO JOGO===============================================================
    cout << "\n\n*************************************JOGO COMEÇOU***********************************************";
    do
    {
        menu();

        cout << "\n\n1 - Batalhar";
        cout << "\n2 - Dormir";
        cout << "\n3 - Treinar";
        cout << "\n4 - Loja";
        cout << "\n\nSelecione: ";
        cin >> seletor;

        switch(seletor)
        {
        case 1:
            batalhar();
            break;
        case 2:
            dormir();
            break;
        case 3:
            treino();
            break;
        case 4:
            loja();
            seletor_loja = 0;
            break;
        }
    }
    while(venceuJogo == false);
    cout << "\n\n=================================OBRIGADO POR JOGAR==================================\n\n";
    cout << "\n\n\n**********************Parabéns, você completou o jogo**********************\n\n\n";
    if(dayCount <= 15)
    {
        cout << "Você completou o jogo em " << dayCount << ". Que macumba você fez para vencer o jogo tão rápido?\n";
    }
    else if(dayCount > 15 && dayCount <= 25)
    {
        cout << "Você completou o jogo em " << dayCount << ". Você completou zerou o jogo até que rápido, Parabéns\n";
    }
    else if (dayCount > 25 && dayCount <= 35)
    {
        cout << "Você completou o jogo em " << dayCount << ". Sem mensagem especial para você ;-;\n";
    }
    else if (dayCount > 35)
    {
        cout << "Você completou o jogo em " << dayCount << ". CARALHO TU DEMOROU PARA ZERA EM?!?!?\n";
    }

    system("pause");
    return 0;
    //============================================FIM=============================================
}
//=======================================================
//=======================FUNÇÕES=========================
//FUNÇÃO PARA ESCREVER ALGO DEPENDENDO DO NOME DIGITADO
int refNome()
{
    //HAVOKINHO
    if(nome == "Havokinho")
    {
        cout << "\n\nOk seu calango, seu nome é "<< nome << ". Você e um garoto que quer entrar para o exercito e precisa treinar para isso.\n\n";
    }
    //FELYPE
    else if(nome == "Zolfric" || nome == "Felype")
    {
        cout << "\n\nOk Felypopis, Brinks, seu nome é "<< nome << ". Você e um garoto que quer entrar para o exercito e precisa treinar para isso.\n\n";
    }
    //HAVOKK
    else if(nome == "Havokk" || nome == "HavokkMorands" || nome == "BaianinhoLegends" || nome == "SoloQPatrickVrau" || nome == "Bruno")
    {
        cout << "\n\nOk Pikachu Treteiro, Brinks, seu nome é "<< nome << ". Você e um garoto que quer entrar para o exercito e precisa treinar para isso.\n\n";
    }
    //HISSIS
    else if(nome == "Hissis" || nome == "Thunder" || nome == "Glognir" || nome == "SoloQPatrickVrau")
    {
        cout << "\n\nEae Hissis, vai ter paradoxo aqui, O seu nome é "<< nome << ". Você e um garoto que quer entrar para o exercito e precisa treinar para isso.\n\n";
    }
    //RUANN
    else if(nome == "Kannon" || nome == "Ruann" || nome == "kannon")
    {
        cout << "\n\nEae irmãozinho, como vai a vida?. Seu nome é " << nome << ". Você é um garoto que quer entrar para o exercito e precisa treinar para isso.\n\n";
    }
    //YURI
    else if(nome == "Yuri" || nome == "Hyuzaki" || nome == "HyuzakiKronus" || nome == "Hyuzakikronus")
    {
        cout << "\n\nOlá Yurileba, tudo bem?. Seu nome é " << nome << ". Você é um garoto que quer entrar para o exercito e precisa treinar para isso.\n\n";
    }
    else
    {
        cout << "\n\nSeu nome é " << nome << ". Você é um garoto que quer entrar para o exercito e precisa treinar para isso.\n\n";
    }
}
//FUNÇÕES DE GANHOS DE BATALHA=====

int gainPo()
{
    //PO Funkeiro
    if(seletor2 == 1)
    {
        cout << "\nVocê ganhou " << funk_po << " de PO\n";
        po += funk_po;
        seletor2 = 0;
        //PO Vitima
    }
    else if(seletor2 == 2)
    {
        cout << "\nVocê ganhou " << vit_po << " de PO\n";
        po += vit_po;
        seletor2 = 0;
    }
    system("pause");
    return 0;
}
int expNivel()
{
    if(fugiu == 0)
    {

        //EXP DO FUNKEIRO
        if(seletor2 == 1)
        {
            cout << "Você ganhou " << exp_funk << " de EXP";
            exp += exp_funk;
            //EXP DA VITIMIA
        }
        else if(seletor2 == 2)
        {
            cout << "Você ganhou " << exp_vit << " de EXP";
            exp += exp_vit;
        }

    }
    //=====MENU=======
    if(nv == 1)
    {
        return 150;

    }
    else if(nv == 2)
    {
        return 900;

    }
    else if(nv == 3)
    {
        return 999999;
    }
    system("pause");
}
int upNivel()
{
    //UPOU PARA NV 2
    if(nv == 1 && exp >= 150)
    {
        cout << "\n-----------------------------*****************VOCÊ SUBIU DE NIVEL**************--------------------------------\n";
        system("pause");
        cout << "\n**Vida - 50 > 100**";
        cout << "\nATK - " << atk << " > " << atk + 5;
        cout << "\nDEF - " << def << " > " << def + 5;
        cout << "\n**TP RESETADO**\n";
        // STATUS
        vida = 100;
        exp -= 150;
        atk += 5;
        def += 5;
        TP = 5;
        nv++;
        //UPOU PARA NV 3
    }
    else if(nv == 2 && exp >= 900)
    {
        cout << "\n----------------------*****************VOCÊ SUBIU DE NIVEL**************--------------------------------\n";
        system("pause");
        cout << "\nVida - 100 > 200";
        cout << "\nATK - " << atk << " > " << atk + 7;
        cout << "\nDEF - " << def << " > " << def + 7;
        cout << "\n**TP RESETADO**\n";
        // STATUS
        vida = 200;
        exp -= 900;
        atk += 7;
        def += 7;
        TP = 5;
        nv++;
    }
    //BUG DE TP FICAR MAIOR QUE 5 QUANDO UPAR. EX: 6/5 - 10/5 (NÂO TESTADO)
    if(TP > 5)
    {
        TP = 5;
    }
    return 0;
}
//=====================================================
string arma()
{
    if(faca_count == 0)
    {
        return "Mãos";
    }
    else if(faca_count == 1)
    {
        return "Faca Tetanosa";
    }
}
string armadura()
{
    if(cortina_count == 0)
    {
        return "Peito";
    }
    else if(cortina_count == 1)
    {
        return "Cortina";
    }
}
//=====================================================
int menu()
{
    cout << "\n==========" << nome <<" - NV " << nv << " | EXP: " << exp << " / " << expNivel() << "==========";
    cout << "\n======================" << "Dia: " << dayCount << "=======================";

    cout << "\nVIDA: " << vida << "     PO: " << po << "          TP: " << TP << "/5";
    cout << "\nATK: " << atk << "       Arma: " << arma();
    cout << "\nDEF: " << def << "       Armadura: " << armadura();


    cout << "\n===================================================";
//===========RESETAR O FUGIR===============
    if (fugiu == 1)
    {
        fugiu = 0;
    }
//========================================
//============SISTEMA DE ARMAS E ARMADURAS==================
    return 0;
}
int loja()
{
    cout << "\n\n=-==-==-==-==-==-==-LOJA-==-==-==-==-==-==-=";
    cout << "\nO que você quer comprar?\n";
    //==============EXIBIÇÃO DOS ITENS==================
    if(faca_count == 0)
    {
        cout << "\n1- Faca Tetanosa - 20 PO";
    }
    else
    {
        cout << "\nESGOTADO";
    }

    if(cortina_count == 0)
    {
        cout << "\n2- Cortina - 30 PO";
    }
    else
    {
        cout << "\nESGOTADO";
    }
    //================================================

    cout << "\n3- Sair\n";

    cout << "Selecione: ";
    cin >> seletor_loja;

    if(po < 20 && seletor_loja == 1)
    {
        cout << "\nO Vendedor olha para você com uma cara de desgosto e fala:";
        cout << "\n-Você não tem dinheiro. sEu pObRe";
        cout << "\nE te chuta para fora da loja\n";
        system("pause");
    }
    else if(po < 30 && seletor_loja == 2)
    {
        cout << "\nO Vendedor olha para você com uma cara de desgosto e fala:";
        cout << "\n-Você não tem dinheiro. sEu pObRe";
        cout << "\nE te chuta para fora da loja\n";
        system("pause");
    }

    if(seletor_loja == 1 && po >= 20)
    {
        cout << "\n*Você comprou uma Faca Tetanosa*\n";
        po -= 20;
        faca_count++;
        atk += 10;
        system("pause");
    }
    else if(seletor_loja == 2 && po >= 30)
    {
        cout << "\n*Você comprou uma Cortina*\n";
        po -= 30;
        cortina_count++;
        def += 7;
        system("pause");
    }

    return 0;
}
int dormir()
{
    cout << "\nDormindo... ***HP RESTAURADO***";
    switch(nv)
    {
    case 1:
        vida--;
        do
        {
            vida++;
        }
        while(vida < 50);
        break;
    case 2:
        vida--;
        do
        {
            vida++;
        }
        while(vida < 100);
        break;
    case 3:
        vida--;
        do
        {
            vida++;
        }
        while(vida < 300);
        break;
    }
    //ADICIONA UM AO CONTADOR DE DIAS
    dayCount++;

    return 0;
}
int fugir()
{
    cout << "\nVocê está tentando fugir...\n";
    system("pause");

    fugiu = 1;

    return 0;
}
int habilidades()
{
    cout << "\n==HABILIDADES==\n";
    switch(nv)
    {
    case 1:
        cout << "\n1- Cabeçada\n";
        break;
    case 2:
        cout << "\n1- Cabeçada";
        cout << "\n2- Encoxada de Mossoró\n";
        break;
    case 3:
        cout << "\n1 - Cabeçada";
        cout << "\n2 - Encoxada de Mossoró";
        cout << "\n****HABILIDADES PROIBIDAS****\n";
        cout << "\n3 - Grito - Estilo Fely-Piton: DISGRAÇA!!!\n";
        break;
    }
    cout << "\nSelecione: ";
    cin >> seletor_bat_hab;

}
int treino()
{
    cout << "\n---------Qual treino você quer fazer?----------\n";

    cout << "\n1 - Arrancar bancos de praças e arremessa-las o mais longe possível";
    cout << "\n2 - Resistir a golpes de Chutambô";

    cout << "\n\nSelecione: ";
    cin >> seletor_treino;

    switch(seletor_treino)
    {
    //========OPÇÃO 1=========
    case 1:
        cout << "\nVocê vai até a praça, arranca do chão uma dos bancos e arremessa-o em alguns bêbados lá perto.";
        vida-= 10;
        if(atk >= 17 && TP > 0 && vida > 0)
        {
            cout << "\nVocê percebe que esse treino não vai render mais nada a você\n";
            vida+= 10;
            system("pause");

        }
        else if(TP <= 0)
        {
            cout << "\n**Você não tem TP suficiente**\n";
            vida+= 10;
            system("pause");

        }
        else if(atk <= 17 && TP > 0 && vida > 0)
        {
            cout << "\nVocê se cansa, mas vale apena. ***ATK AUMENTADO***\n";
            atk++;
            TP--;
            system("pause");

        }
        else if(vida <= 0)
        {
            cout << "\nVocê estava muito cansado e acaba errando o alvo, os bêbados começam a correr atrás de você e te espancam até a morte :D\n";
            system("pause");

            cout << "\n\n=======YOU DIED=======\n\n";
            system("pause");
            exit(0);

        }
        cout << "\nVocê volta para casa\n";

        break;
    //=======OPÇÃO 2========
    case 2:
        cout << "\nVocê vai até um vale onde mora o Mestre José Gerusa e começa a treinar Chutambô.";
        vida-= 10;
        if(def >= 15 && TP > 0 && vida > 0)
        {
            cout << "\nVocê percebe que esse treino não vai render mais nada a você\n";
            vida+= 10;
            system("pause");

        }
        else if(TP <= 0)
        {
            cout << "\n**Você não tem TP suficiente**\n";
            vida+= 10;
            system("pause");

        }
        else if(def <= 15 && TP > 0 && vida > 0)
        {
            cout << "\nVocê leva alguns golpes do mestre, mas continua de pé. ***DEF AUMENTADA***\n";
            def++;
            TP--;
            system("pause");

        }
        else if(vida <= 0)
        {
            cout << "\nVocê estava exausto, percebendo sua postura, o mestre agarra sua cabeça e desativa todos os 5 sentidos do seu corpo.\n";
            system("pause");

            cout << "\n\n=======YOU DIED=======\n\n";
            system("pause");
            exit(0);


        }
        cout << "\nVocê volta para casa\n";

        break;
    }
}
int batalhar()
{
    cout << "\nOnde você quer ir?";
    cout << "\n1 - Taberna Bonde do Tigrão";
    cout << "\n2 - Centro dos Cheiradores de Farinha";
    if(nv >= 2)
    {
        cout << "\n\n**BOSS**\n\n";
        cout << "Dono do Tráfico de Farinha: ";
        cout << "\n3 - Glognir, A Lança Flamejante\n";
    }

    cout << "\n\nSelecione: ";
    cin >> seletor2;

    batalha();

    return 0;
}
int batalha()
{
    //===================================================================================================
    //===========================================FUNKEIRO================================================
    if(seletor2 == 1)
    {
        cout << "\n**Você vai para a taberna e acaba encontrando um Funkeiro**\n";
        system("pause");

        cout << "\n===========" << funk_nome << " VS " << nome << "===========\n";

        do
        {
            cout << "=======================SUA VEZ===========================\n";
            //=============================INTERFACE=================================
            cout << funk_nome << "/ Vida: " << funk_vida;
            cout << "\n";
            cout << nome << "/ Vida: " << vida;
            //=========OPÇÕES==============
            cout << "\n\n1 - Atacar";
            cout << "\n2 - Habilidades";
            cout << "\n3 - Fugir";
            cout << "\n\nSelecione: ";
            cin >> seletor_bat;

            if(seletor_bat == 2)
            {
                habilidades();
            }
            else if(seletor_bat == 3)
            {
                fugir();
            }
            //=======================================================================
            cout << "=======================Battle turn================================";
            //=============================SELECIONOU ATACAR=================================
            if(seletor_bat == 1)
            {
                cout << "\n*Você causou " << atk - funk_def << " de dano ao Funkeiro*\n";
                funk_vida -= atk - funk_def;
                system("pause");
                //=============================ESCOLHEU HABILIADE=============================================
            }
            else if(seletor_bat == 2)
            {

                if(seletor_bat_hab == 1 && nv <= 3)
                {
                    cout << "\nVocê avança para cima do inimigo e grita *VOU TE DAR CABEÇADA* e faz o mesmo, causando " << atk * 2 << " de dano e perdendo/ganhando " << 8 - def << " de vida.\n";
                    vida -= 8 - def;
                    funk_vida -= (atk * 2) - funk_def;
                    system("pause");
                }
                else if(seletor_bat_hab == 2 && nv > 1)
                {
                    cout << "\nVocê fica na posição do Chutambô, pula para trás do inimigo e da uma encoxada com tanta força que ele é jogado para frente, causando " << atk * 3 + def << " de dano.\n";
                    funk_vida -= (atk * 3 + def) - funk_def;
                    system("pause");
                }
                else if(seletor_bat_hab == 3 && nv > 2)
                {
                    cout << "\nVocê deixa o espírito do Filoso Piton se apossar do seu corpo e grita *DISGRAÇAAAA*, causando " << atk * 66 << " de dano Verdadeiro/Mágico/Físico.\n";
                    funk_vida -= (atk * 66) - funk_def;
                    system("pause");
                }
                //=========================================================================================================================
            }
            //=============VEZ DO FUNKEIRO=================
            if(funk_vida > 0)
            {
                cout << "\n*Funkeiro começa a cantar funk e faz seus ouvidos sangrarem, causando " << funk_atk - def << " de dano.*\n\n" ;
                vida -= funk_atk - def;
            }
            if(vida <= 0)
            {
                cout << "\n\n=======YOU DIED=======\n\n";
                system("pause");
                exit(0);
            }
            if(vida > 0 && fugiu == 1)
            {
                cout << "\nVocê fugiu\n";
            }
        }
        while(funk_vida > 0 && vida > 0 && fugiu == 0);
    }
//==================================VITIMA DO HISSIS========================================================================================
//==========================================================================================================================================
    else if(seletor2 == 2)
    {
        cout << "\n**Você vai até o centro da cidade e um Cheirador de Farinha tenta te roubar.**\n";
        system("pause");

        cout << "\n=============" << vit_nome << " VS " << nome << "==============\n";

        do
        {
            cout << "=============================SUA VEZ=============================\n";

            cout << vit_nome << "/ Vida: " << vit_vida;
            cout << "\n";
            cout << nome << "/ Vida: " << vida;
            //=========OPÇÕES==============
            //ATACAR O OPONENTE
            cout << "\n\n1 - Atacar";
            cout << "\n2 - Habilidades";
            cout << "\n3 - Fugir";
            cout << "\n\nSelecione: ";
            cin >> seletor_bat;

            if(seletor_bat == 2)
            {
                habilidades();
            }
            else if(seletor_bat == 3)
            {
                fugir();
            }
            cout << "=======================Battle turn================================";
            //============SELECIONOU ATACAR=================
            if(seletor_bat == 1)
            {
                cout << "\n*Você causou " << atk - vit_def << " de dano a Vitima do Hissis*\n";
                vit_vida -= atk - vit_def;
                //============SELECIONOU A HABILIDADE=================
            }
            else if(seletor_bat == 2)
            {

                if(seletor_bat_hab == 1 && nv <= 3)
                {
                    cout << "\nVocê avança para cima do inimigo e grita *VOU TE DAR CABEÇADA* e faz o mesmo, causando " << atk * 2 << " de dano e perdendo/ganhando " << 8 - def << " de vida.\n";
                    vida -= 8 - def;
                    vit_vida -= (atk * 2) - vit_def;
                    system("pause");
                }
                else if(seletor_bat_hab == 2 && nv > 1)
                {
                    cout << "\nVocê fica na posição do Chutambô, pula para trás do inimigo e da uma encoxada com tanta força que ele é jogado para frente, causando " << atk * 3 + def << " de dano.\n";
                    vit_vida -= (atk * 3 + def) - vit_def;
                    system("pause");
                }
                else if(seletor_bat_hab == 3 && nv > 2)
                {
                    cout << "\nVocê deixa o espírito do Filoso Piton se apossar do seu corpo e grita *DISGRAÇAAAA*, causando " << atk * 66 << " de dano Verdadeiro/Mágico/Físico.\n";
                    vit_vida -= (atk * 66) - vit_def;
                    system("pause");
                }

            }

            //RESET DO ATQ CONT
            if(vit_atqCont == 3)
            {
                vit_atqCont = 1;
            }
            //===ATAQUE NORMAL===
            if(vit_vida > 0 && vit_atqCont == 1)
            {
                cout << "\n*Vitima do Hissis cheira uma carreira de farinha e ti ataca, causando " << vit_atk - def << " de dano\n";
                vida -= vit_atk - def;
                vit_atqCont++;
            }
            //====BUFF DE ATAQUE====
            else if(vit_vida > 0 && vit_atqCont == 2)
            {
                cout << "\n*Vitima do Hissis usa uma droga chamada *top 10 escovas*, aumentando seu Atk\n" ;
                vit_atk += 3;
                vit_atqCont++;
            }

            if(vida <= 0)
            {
                cout << "\n\n=======YOU DIED=======\n\n";
                system("pause");
                exit(0);
            }
            if(vida > 0 && fugiu == 1)
            {
                cout << "\nVocê fugiu\n";
            }
        }
        while(vit_vida > 0 && vida > 0 && fugiu == 0);
    }
//==================================BOSS : HISSIS===========================================================================================
//==========================================================================================================================================
    else if(seletor2 == 3)
    {
        boss();
    }
//===========================================================================================================================================
//==============================================FIM BATALHA======================================================================================
    if((fugiu == 0 && funk_vida <= 0) ||  (fugiu == 0 && vit_vida <= 0))
    {
        cout << "\n===========Você venceu a batalha===========\n";
        //Personagem Recebe EXP
        expNivel();
        //Verifica se o personagem Upou de NV
        upNivel();
        //Personagem Recebe PO
        gainPo();
    }
    //===================================
    cout << "\n*******************************************************************************************************************\n";
    cout << "Você voltou para casa\n";
    //===================================
    seletor_bat = 0;
    seletor_bat_hab = 0;
    seletor2 = 0;
    funk_vida = 15;
    vit_vida = 40;

    return 0;
}
int boss()
{
    cout << "\n\n\n\n\n\n\n\n\n\n***************BOSS*******************";
        cout << "\n**Você vai até o centro da cidade, você já enfrentou muitos inimigos...**\n";
        system("pause");
        cout << "\nMas você sabe que eles todos eram peixes pequenos comparados aquele ser...\n";
        system("pause");
        cout << "\nVocê sabe onde ele se esconde, e vai até lá.\n";
        system("pause");
        cout << "\nDescendo pelo esgoto da cidade, você chega até uma porta com uma placa, nela está escrita...\n";
        system("pause");
        cout << "\n***Witches, Wizards e Felypes afastem-se***\n";

        cout << "\n\nAbrir a porta? \n\n";
        cout << "1- Abrir";
        cout << "\n2- Não Abrir\n";
        cout << "\nMake your Choice: ";
        cin >> bossHissis;


        if(bossHissis == 2)
        {
            cout << "\nSe fodeu meu parceiro, aqui não tem volta.\n";
            cout << "\n5- Em batalhas contra BOSS você não pode fugir.";
            cout << "\n3- Não existe opção de voltar ainda, ou seja, escolha fazer algo se você estiver certo que é oque você quer.\n";
            system("pause");
            cout << "\nE antes que você fale *As regras não tão falando isso*, vtnc xd\n";
        }

            cout << "\nVocê abre a porta.";
            cout << "\n\n*Som de porta abrindo*\n\n";
            cout << "\n\nLogo que você entra você encontra 1 dos capangas do Glognir\n";
            system("pause");
            cout << "\nEle avança para cima de você.\n";
            system("pause");
        //==================================VITIMA DO HISSIS============================================
        //==============================================================================================
        cout << "\n=============" << vit_nome << " VS " << nome << "==============\n";

        do
        {
            cout << "=============================SUA VEZ=============================\n";

            cout << vit_nome << "/ Vida: " << vit_vida;
            cout << "\n";
            cout << nome << "/ Vida: " << vida;
            //=========OPÇÕES==============
            //ATACAR O OPONENTE
            cout << "\n\n1 - Atacar";
            cout << "\n2 - Habilidades";
            cout << "\n\nSelecione: ";
            cin >> seletor_bat;

            if(seletor_bat == 2)
            {
                habilidades();
            }
            cout << "=======================Battle turn================================";
            //============SELECIONOU ATACAR=================
            if(seletor_bat == 1)
            {
                cout << "\n*Você causou " << atk - vit_def << " de dano a Vitima do Hissis*\n";
                vit_vida -= atk - vit_def;
                //============SELECIONOU A HABILIDADE=================
            }
            else if(seletor_bat == 2)
            {

                if(seletor_bat_hab == 1 && nv <= 3)
                {
                    cout << "\nVocê avança para cima do inimigo e grita *VOU TE DAR CABEÇADA* e faz o mesmo, causando " << atk * 2 << " de dano e perdendo/ganhando " << 8 - def << " de vida.\n";
                    vida -= 8 - def;
                    vit_vida -= (atk * 2) - vit_def;
                    system("pause");
                }
                else if(seletor_bat_hab == 2 && nv > 1)
                {
                    cout << "\nVocê fica na posição do Chutambô, pula para trás do inimigo e da uma encoxada com tanta força que ele é jogado para frente, causando " << atk * 3 + def << " de dano.\n";
                    vit_vida -= (atk * 3 + def) - vit_def;
                    system("pause");
                }
                else if(seletor_bat_hab == 3 && nv > 2)
                {
                    cout << "\nVocê deixa o espírito do Filoso Piton se apossar do seu corpo e grita *DISGRAÇAAAA*, causando " << atk * 66 << " de dano Verdadeiro/Mágico/Físico.\n";
                    vit_vida -= (atk * 66) - vit_def;
                    system("pause");
                }

            }

            //RESET DO ATQ CONT
            if(vit_atqCont == 3)
            {
                vit_atqCont = 1;
            }
            //===ATAQUE NORMAL===
            if(vit_vida > 0 && vit_atqCont == 1)
            {
                cout << "\n*Vitima do Hissis cheira uma carreira de farinha e ti ataca, causando " << vit_atk - def << " de dano\n";
                vida -= vit_atk - def;
                vit_atqCont++;
            }
            //====BUFF DE ATAQUE====
            else if(vit_vida > 0 && vit_atqCont == 2)
            {
                cout << "\n*Vitima do Hissis usa uma droga chamada *top 10 escovas*, aumentando seu Atk\n" ;
                vit_atk += 3;
                vit_atqCont++;
            }

            if(vida <= 0)
            {
                cout << "\n\n=======YOU DIED=======\n\n";
                system("pause");
                exit(0);
            }
            if(vida > 0 && fugiu == 1)
            {
                cout << "\nVocê fugiu\n";
            }
        }
        while(vit_vida > 0 && vida > 0 && fugiu == 0);
        cout << "\n\n================================================VOCÊ VENCEU========================================================\n\n";
        //==============================================VITIMA DERROTADA=========================================================
        //==================================================CUTSCENE=============================================================
        cout << "\n\nVocê derrota o campanga que foi para cima de você, mas você sabe que ainda não conseguiu oque queria.\n";
        cout << "\nE então corre mais a dentro da caverna.\n";
        system("pause");
        cout << "\nVocê corre, corre e corre, até encontrar uma porta, e então com a força do ódio, você da um chutão nela.\n";
        system("pause");
        cout << "\nE então você vê um homem.... ou uma criança?\n";
        system("pause");
        cout << "\nEle tem aproximadamente 0.83m de altura e parece um Shevii da Guatemala.\n";
        system("pause");
        cout << "\nEle olha para você e fala:\n";
        cout << "\n-coé lixo, vem x1, vou te destruir.\n\n";
        system("pause");
        cout << "\nLogo após falar isso, ele levanta da poutrona que estava sentado, e puxa algo de trás dela\n";
        system("pause");
        cout << "\nVocê vê, que oque ele pegou foi uma lança, tão grande, que te faz refletir.";
        cout << "\nVocê não sabe qual é a melhor pergunta.\n";
        system("pause");
        cout << "\n*Como ele escondeu aquela lança lá trás E como um ser tão pequeno pode levantar algo tão grande*\n";
        system("pause");
        cout << "\nAntes que conseguisse obter a resposta, o anão vai para cima de você\n\n";
        system("pause");

        cout << "\n=============" << hissis_nome << " VS " << nome << "==============\n";
        //===========================================================================================================================
        //==============================================HISSIS BATTLE================================================================
        do{

            cout << "\n=============================SUA VEZ=============================\n";

            cout << hissis_nome << "/ Vida: " << hissis_vida;
            cout << "\n";
            cout << nome << "/ Vida: " << vida;
            //=========OPÇÕES==============
            //ATACAR O OPONENTE
            cout << "\n\n1 - Atacar";
            cout << "\n2 - Habilidades";
            cout << "\n\nSelecione: ";
            cin >> seletor_bat;

            if(seletor_bat == 2)
            {
                habilidades();
            }
            cout << "\n=======================Battle turn================================";
                //============SELECIONOU ATACAR=================
            if(seletor_bat == 1)
            {
                cout << "\n*Você causou " << atk - hissis_def << " de dano ao Glognir*\n";
                hissis_vida -= atk - hissis_def;
                //============SELECIONOU A HABILIDADE=================
            }
            else if(seletor_bat == 2)
            {

                if(seletor_bat_hab == 1 && nv <= 3)
                {
                    cout << "\nVocê avança para cima do inimigo e grita *VOU TE DAR CABEÇADA* e faz o mesmo, causando " << atk * 2 << " de dano e perdendo/ganhando " << 8 - def << " de vida.\n";
                    vida -= 8 - def;
                    hissis_vida -= (atk * 2) - hissis_def;
                    system("pause");
                }
                else if(seletor_bat_hab == 2 && nv > 1)
                {
                    cout << "\nVocê fica na posição do Chutambô, pula para trás do inimigo e da uma encoxada com tanta força que ele é jogado para frente, causando " << (atk * 3 + def) - hissis_def << "de dano.\n";
                    hissis_vida -= (atk * 3 + def) - hissis_def;
                    system("pause");
                }
                else if(seletor_bat_hab == 3 && nv > 2)
                {
                    cout << "\nVocê deixa o espírito do Filósofo Piton se apossar do seu corpo e grita *DISGRAÇAAAA*, causando " << atk * 6 - hissis_def << " de dano Verdadeiro/Mágico/Físico.\n";
                    cout << "\nGlognir olha para você e fala: *Um golpe vindo desse desgraçado não tem muito efeito em mim*| Formula: Original(atk * 66), Atual(atk * 6)\n\n";
                    hissis_vida -= (atk * 6) - hissis_def;
                    system("pause");
                }

            }
            //=====================================HISSIS TURN=====================================================================
            //=====================================================================================================================
            //ATQ COUNT============
            if(hissis_atqCount == 5)
            {
                hissis_atqCount = 1;
            }
            //=====================
            if(hissis_vida < 350 && hissis_furia == 0)
                {
                    cout << "\nGlognir olha para você e fala: \n-Bora pegar pesado agora?\n";
                    system("pause");
                    cout << "\nA lança de Glognir começa a pegar fogo\n";
                    system("pause");

                    hissis_furia = 1;
                    hissis_atqCount = 1;
                }
            //================================================================SEM FÚRIA===================================================================
            else if(hissis_vida >= 350 && hissis_furia == 0)
            {

                if(hissis_vida > 0 && hissis_atqCount == 1)
                {
                    cout << "\nGlognir avança na sua direção e disfere um golpe que faz o local estremecer, causando " << hissis_atk - def << " de dano.\n";
                    vida -= hissis_atk - def;
                    hissis_atqCount++;
                }
                else if(hissis_vida > 0 && hissis_atqCount == 2)
                {
                    cout << "\nGlognir gira sua lança e realiza outro corte em seu corpo, causando " << hissis_atk - def << " de dano.\n";
                    vida -= hissis_atk - def;
                    hissis_atqCount++;
                }
                else if(hissis_vida > 0 && hissis_atqCount == 3)
                {
                    cout << "\nGlognir fica em uma posição estranha, e mantem sua lança atrás do seu corpo.\n";
                    hissis_atqCount++;
                }
                else if(hissis_vida > 0 && hissis_atqCount == 4)
                {
                    cout << "\nGlognir rasga um saco com sua lança e usa uma droga chamada *top 10 churrasqueiras*, aumentando seu ATK e DEF em 3+";
                    hissis_atk += 3;
                    hissis_def += 3;
                    hissis_atqCount++;
                }

            }
            //============================CORRE QUE O TOURO TA PUTO==================================================
            else if(hissis_vida < 350 && hissis_furia == 1)
            {
                if(hissis_atqCount == 1 && hissis_vida > 0)
                {
                    cout << "\nGlognir começa a girar sua lança\n";
                    hissis_atqCount++;
                }
                else if(hissis_atqCount == 2 && hissis_vida > 0)
                {
                    cout << "\nGlognir arremessa um furacão de chamas na sua direção, causando " << (hissis_atk * 3) - def << " de dano";
                    vida -= (hissis_atk * 3) - def;
                    hissis_atqCount++;
                }
                else if(hissis_atqCount == 3 && hissis_vida > 0)
                {
                    cout << "\nGlognir joga sua lança em você, causando " << (hissis_atk + 12) - def << " de dano e diminuindo sua DEF em -3";
                    vida -= (hissis_atk + 12) - def;
                    hissis_atqCount++;
                }
                else if(hissis_atqCount == 4 && hissis_vida > 0)
                {
                    cout << "\nGlognir grita: \n-SE TÁ FUDIDO MEU PARCEIRO, BRINCOU COM A PESSOA ERRADA\n";
                    cout << "Saca do bolso oque parece ser uma bala, e a come.\n";
                    system("pause");
                    cout << "*\n\nGlognir ATK Triplicado\n\n";
                    system("pause");
                    hissis_atqCount++;
                }
            }
            //=======================================================================================================

        }while(vida > 0 && hissis_vida > 0);
        if(vida <= 0)
            {
                cout << "\n\n=======YOU DIED=======\n\n";
                system("pause");
                exit(0);
            }
        else if(hissis_vida <= 0)
        {
            cout << "\n\nVocê conseguiu derrotar o Glognir\n\n";
            system("pause");
            cout << "\nApós isso, você sabe que finalmente vai conseguir entrar no exército depois desse feito.\n";
            cout << "\nVocê vai até o corpo morto de Glognir e arranca sua cabeça minúscula, e a leva para o capitão do exercito\n";
            system("pause");
            cout << "\nE consegue entrar no exercito\n";
            system("pause");
            cout << "    \n";
            system("pause");
            cout << "ah?\n";
            system("pause");
            cout << "que?\n";
            system("pause");
            cout << "cabou.\n";
        }
        venceuJogo = true;
}
