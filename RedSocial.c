#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "RedSocial.h"
#include "LinkedList.h"

ePost* Post_new()
{
    ePost* newPost;
    newPost = (ePost*) malloc(sizeof(ePost));
    if(newPost != NULL)
    {
        newPost->id = 0;
        strcpy(newPost->user, "");
        newPost->likes = 0;
        newPost->dislikes = 0;
        newPost->followers = 0;
    }
    return newPost;
}
ePost* Post_newParam(char* idStr,char* userStr, char* likesStr,char* dislikeStr,char* followersStr)
{
    ePost* newPost;
    newPost = NULL;
    newPost = Post_new();

    if(newPost != NULL)
    {
        Post_setId(newPost,atoi(idStr));
        Post_setUser(newPost,userStr);
        Post_setLikes(newPost,atoi(likesStr));
        Post_setDislikes(newPost,atoi(dislikeStr));
        Post_setFollowers(newPost,atoi(followersStr));
    }
    return newPost;
}

int Post_setId(ePost* this, int id)
{
    int isOk = 0;
    if(this != NULL && id >0)
    {
        this->id = id;
        isOk = 1;
    }
    return isOk;
}
int Post_setUser(ePost* this, char* user)
{
    int isOk = 0;

    if(this != NULL && user != NULL && strlen(user) > 0 && strlen(user) < 50)
    {
        strcpy(this->user, user);
        isOk = 1;
    }
    return isOk;
}
int Post_setLikes(ePost* this, int likes)
{
    int isOk = 0;
    if(this != NULL && likes >0)
    {
        this->likes = likes;
        isOk = 1;
    }
    return isOk;
}
int Post_setDislikes(ePost* this, int dislikes)
{
    int isOk = 0;
    if(this != NULL && dislikes >0)
    {
        this->dislikes = dislikes;
        isOk = 1;
    }
    return isOk;
}
int Post_setFollowers(ePost* this, int followers)
{
    int isOk = 0;
    if(this != NULL && followers >0)
    {
        this->followers = followers;
        isOk = 1;
    }
    return isOk;
}

int Post_getId(ePost* this, int* id)
{
    int isOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        isOk = 1;
    }
    return isOk;
}
int Post_getUser(ePost* this, char* user)
{
    int isOk = 0;
    if(this != NULL && user != NULL)
    {
        strcpy(user, this->user);
        isOk = 1;
    }
    return isOk;
}
int Post_getLikes(ePost* this, int* likes)
{
    int isOk = 0;
    if(this != NULL && likes != NULL)
    {
        *likes = this->likes;
        isOk = 1;
    }
    return isOk;
}
int Post_getDislikes(ePost* this, int* dislikes)
{
    int isOk = 0;
    if(this != NULL && dislikes != NULL)
    {
        *dislikes = this->dislikes;
        isOk = 1;
    }
    return isOk;
}
int Post_getFollowers(ePost* this, int* followers)
{
    int isOk = 0;
    if(this != NULL && followers != NULL)
    {
        *followers = this->followers;
        isOk = 1;
    }
    return isOk;
}

void Post_Delete(ePost* this)
{
    if(this != NULL)
    {
        free(this);
    }
}
int Post_listRow(ePost* this)
{
    int isOk = 0;
    int id;
    char user[50];
    int likes;
    int dislikes;
    int followers;

    if(Post_getId(this, &id) &&
       Post_getUser(this, user)&&
       Post_getLikes(this, &likes)&&
       Post_getDislikes(this, &dislikes)&&
       Post_getFollowers(this, &followers))
    {
        printf("%3d   %-15s     %5d       %5d        %5d \n", id, user, likes, dislikes,followers);

        isOk = 1;
    }
    return isOk;
}
int Post_mapStatLikes(void* post)
{
    int isOk = 0;
    int min = 600;
    int max = 5000;
    int likes;

    ePost* auxPost;

    if(post != NULL)
    {

        auxPost = (ePost*) post;
        likes = (rand()%(max - min +1) + min);
        Post_setLikes(auxPost, likes);
        isOk = 1;
    }
    return isOk;
}
int Post_mapStatDisLikes(void* post)
{
    int isOk = 0;
    int min = 300;
    int max = 3500;
    int dislikes;

    ePost* auxPost;

    if(post != NULL)
    {

        auxPost = (ePost*) post;
        dislikes = (rand()%(max - min +1) + min);
        Post_setDislikes(auxPost, dislikes);
        isOk = 1;
    }
    return isOk;
}
int Post_mapStatFollowers(void* post)
{
    int isOk = 0;
    int min = 10000;
    int max = 20000;
    int followers;

    ePost* auxPost;

    if(post != NULL)
    {

        auxPost = (ePost*) post;
        followers = (rand()%(max - min +1) + min);
        Post_setFollowers(auxPost, followers);
        isOk = 1;
    }
    return isOk;
}
int Post_filterLikes(void* post)
{
    int isOk = 0;
    ePost* auxPost = NULL;
    if(post != NULL)
    {
        auxPost = (ePost*) post;
        if(auxPost->likes > 4000)
        {
            isOk = 1;
        }
    }
    return isOk;
}
int Post_filterDislikes(void* post)
{
    int isOk = 0;
    ePost* auxPost = NULL;
    if(post != NULL)
    {
        auxPost = (ePost*) post;
        if(auxPost->dislikes > auxPost->likes)
        {
            isOk = 1;
        }
    }
    return isOk;
}
int Post_SortFollowers(void* a, void*b)
{
    int isOk = 0;

    if(a != NULL && b != NULL)
	{
		ePost* aux1 = (ePost*)a;
		ePost* aux2 = (ePost*)b;

		if(aux1->followers == aux2->followers)
		{
			isOk = 0;
		}
		else if(aux1->followers > aux2->followers)
		{
			isOk = 1;
		}
		else
		{
			isOk = -1;
		}
	}
	return isOk;
}
