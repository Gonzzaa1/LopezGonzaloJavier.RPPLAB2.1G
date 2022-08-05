#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "RedSocial.h"
#include "Menus.h"
#include "Controller.h"


int main()
{
    srand(time(NULL));

    char salir = 'n';
    int flag = 0;

    LinkedList* listPost = ll_newLinkedList();

    if(listPost == NULL)
    {
        printf("No se pudo conseguir memoria.\n");
        exit(1);
    }

    do
    {
        switch(menu())
        {
            case 1:
                if(flag)
                {
                    printf("Ya se cargo el archivo\n");
                }
                else
                {
                    if(controller_loadFromText("posts.csv",listPost))
                    {
                        flag = 1;
                        printf("Archivo Cargado Correctamente.\n");
                    }
                    else
                    {
                        printf("No se pudo cargar el archivo.\n");
                    }
                }
                system("pause");
                break;
            case 2:
                controller_listPost(listPost);
                system("pause");
            break;
            case 3:
                controller_mapStats(listPost);
                system("pause");
            break;
            case 4:
                listPost = ll_filter(listPost,Post_filterLikes);
                controller_listPost(listPost);
                controller_saveAsText("postFilterLikes.csv" , listPost);
                system("pause");
            break;
            case 5:
                listPost = ll_filter(listPost,Post_filterDislikes);
                controller_listPost(listPost);
                controller_saveAsText("postFilterDislikes.csv" , listPost);
                system("pause");
            break;
            case 6:
                ll_sort(listPost,Post_SortFollowers,0);
                controller_listPost(listPost);
                system("pause");
            break;
            case 7:
            break;
            case 8:
                salir = 's';
            break;
        }
    }while(salir == 'n');

    return 0;
}
