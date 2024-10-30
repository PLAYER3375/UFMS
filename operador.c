/*

Mariana adora criar jogos peculiares para desafiar seus amigos. Desta vez, ela inventou um jogo chamado "Operador", em que ele cria expressões
básicas e cada jogador deve escolher uma expressão e preencher a lacuna com o operador correto para validá-la. Os jogadores poderão escolher
operadores de somente très tipos: adição, subtração e multiplicação.

Você deve receber as expressões e as respostas dos jogadores, e determinar os jogadores que não passarão para a outra fase do jogo.

Entrada: A entrada é composta por um inteiro T (0<=T<=100) que indica a quantidade de expressões e de jogadores. Cada caso de teste é composto por T
expressões na forma "X Y=Z", indicando que X operador Y é igual a 2, seguido de T jogadores e suas respectivas respostas na forma "N E R", sendo N é a
primeira letra do nome do jogador, E o indice da expressão escolhida (1<=E<=T) e R a resposta (+, -, *). A entrada termina quando T = 0.

Saída: Para cada caso de teste, se todos os jogadores passarem, imprima "Todos passaram!"; se nenhum jogador passar, imprima "Ninguém passoul"; caso
contrário, imprima, pela ordem de entrada e entre espaços, a letra do nome dos jogadores que erraram a resposta e, desta forma, não passarão para
a próxima fase do jogo.

Exemplo de Entrada:
3
8 4=5
2 5=5
1 3=4
S 2 +
A 3 +
C 1 *
2
1 2=-1
0 7=7
L 2 -
A 1 +
0

Exemplo de Saída:
S C
Ninguém passou!

*/

#include<stdio.h>

int main(void)
{
    int T, vetP[300], i, expre, cont;
    char pessoa, opera, erraram[100];
    scanf("%d", &T);
    while(T!=0)
    {
    /*leitura*/
        for(i=0; i<T*3; i++)
        {
            scanf("%d %d=%d", &vetP[i], &vetP[i+1], &vetP[i+2]);
            i=i+2;
        }
    /*laço de leitura e resposta, leitura funcionando, condição dando erro*/
        cont=0;
        for(i=0; i<T; i++)
        {
            scanf(" %c %d %c", &pessoa, &expre, &opera);
            expre=expre*3;
            if(opera=='+')
            {
                if(vetP[expre-1]!=vetP[expre-3]+vetP[expre-2])
                {
                    erraram[cont]=pessoa;
                    cont=cont+1;
                }
            }
            else
            {
                if(opera=='-')
                {
                    if(vetP[expre-1]!=vetP[expre-3]-vetP[expre-2])
                    {
                        erraram[cont]=pessoa;
                        cont=cont+1;
                    }
                }
                else
                {
                    if(opera=='*')
                    {
                        if(vetP[expre-1]!=vetP[expre-3]*vetP[expre-2])
                        {
                            erraram[cont]=pessoa;
                            cont=cont+1;
                        }
                    }
                }
            }
        }
        if(cont==0)
        {
            printf("Todos passaram!\n");
        }
        else
        {
            if(cont==T)
            {
                printf("Ninguém passou!\n");
            }
            else
            {
                for(i=0; i<cont; i++)
                {
                    printf("%c\n", erraram[i]);
                }
            }
        }
        scanf("%d", &T);
    }
    return 0;
}