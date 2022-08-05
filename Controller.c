#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "RedSocial.h"
#include "Parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayList)
{
	int isOk = 0;

	if(path != NULL && pArrayList != NULL)
	{
		FILE* file = fopen(path,"r");

		if(file == NULL)
		{
			printf("NO SE PUDO ABRIR EL ARCHIVO\n");

		}
		else
		{
			parser_PostFromText(file, pArrayList);
			printf("CARGA EXITOSA \n");
			isOk = 1;
		}

		fclose(file);
	}
    return isOk;
}
int controller_saveAsText(char* path , LinkedList* pArrayList)
{
    int isOk = 0;

    int id;
    char user[50];
    int likes;
    int dislikes;
    int followers;

    ePost* auxPost;
    FILE* file;

    if(pArrayList != NULL && path != NULL)
    {
        file = fopen(path, "w");
        if(file != NULL)
        {
            int tam = ll_len(pArrayList);
            fprintf(file,"id,user,likes,dislikes,followers\n");
            for(int i = 0; i < tam; i++)
            {
                auxPost = (ePost*) ll_get(pArrayList,i);
                if(Post_getId(auxPost, &id)&&
                   Post_getUser(auxPost, user)&&
                   Post_getLikes(auxPost, &likes)&&
                   Post_getDislikes(auxPost, &dislikes)&&
                   Post_getFollowers(auxPost, &followers))
                {
                    fprintf(file,"%d,%s,%d,%d,%d\n",id,user,likes,dislikes,followers);
                    isOk = 1;
                }
            }
        }
        fclose(file);
    }
    return isOk;
}
int controller_listPost(LinkedList* pArrayList)
{
    int isOk = 0;
    int flag = 1;
    int tam = ll_len(pArrayList);
    ePost* auxPost;

    if(pArrayList != NULL)
    {
        printf("----------------------------------------------------------\n"
               "  ID   USER               LIKES      DISLIKES    FOLLOWERS\n"
               "----------------------------------------------------------\n");

        for(int i = 0; i < tam; i++)
        {
            auxPost = (ePost*)ll_get(pArrayList,i);
            Post_listRow(auxPost);
            flag = 0;

        }

        if(flag)
        {
            printf("\nNo hay Posts en la lista.\n");
        }
        isOk = 1;
    }
    return isOk;
}
int controller_mapStats(LinkedList* pArrayList)
{
    int isOk = 0;

    pArrayList = ll_map(pArrayList, Post_mapStatLikes);
    pArrayList = ll_map(pArrayList, Post_mapStatDisLikes);
    pArrayList = ll_map(pArrayList, Post_mapStatFollowers);

    if(pArrayList != NULL)
    {
        controller_listPost(pArrayList);
        isOk = 1;
    }

    return isOk;
}
int controller_Popular(LinkedList* this)
{
    int isOk = 0;
    ePost* auxPost = NULL;
    int tam = ll_len(this);
    char user[50];
    int popular;
    int flag = 1;

    if(this != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            auxPost = (ePost*)ll_get(this, i);
            if(flag || auxPost->likes > auxPost->likes)
            {
                popular =  auxPost->likes;
                strcpy(user,auxPost->user);
                flag = 0;
            }
        }
        printf("user  %s  tiene el post con mas likes %d\n\n",user, popular);
    }

    return isOk;
}
