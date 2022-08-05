#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "RedSocial.h"

int parser_PostFromText(FILE* pFile , LinkedList* pArrayList)
{
    int isOk = 0;

    char id[10];
    char user[50];
    char likes[50];
    char dislikes[50];
    char followers[50];

    int cant;

    ePost* auxPost;
    auxPost = NULL;

    if(pFile != NULL && pArrayList != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, user, likes, dislikes, followers);

        do
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, user, likes, dislikes, followers);
            if(cant == 5)
            {
                auxPost = Post_newParam(id, user, likes, dislikes, followers);

                if(auxPost != NULL)
                {
                    ll_add(pArrayList, auxPost);
                    auxPost = NULL;
                    isOk = 1;
                }
            }
            else
            {
                printf("ERROR AL CARGAR ARCHIVO");
                break;
            }
        }while(!feof(pFile));
        fclose(pFile);
    }
    return isOk;
}
