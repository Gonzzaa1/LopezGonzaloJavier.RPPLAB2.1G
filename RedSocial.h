#ifndef REDSOCIAL_H_INCLUDED
#define REDSOCIAL_H_INCLUDED

typedef struct
{
    int id;
    char user[50];
    int likes;
    int dislikes;
    int followers;

}ePost;

#endif // REDSOCIAL_H_INCLUDED

ePost* Post_new();
ePost* Post_newParam(char* idStr,char* userStr, char* likesStr,char* dislikeStr,char* followersStr);

//Setters
int Post_setId(ePost* this, int id);
int Post_setUser(ePost* this, char* user);
int Post_setLikes(ePost* this, int likes);
int Post_setDislikes(ePost* this, int dislikes);
int Post_setFollowers(ePost* this, int followers);
//Getters
int Post_getId(ePost* this, int* id);
int Post_getUser(ePost* this, char* user);
int Post_getLikes(ePost* this, int* likes);
int Post_getDislikes(ePost* this, int* dislikes);
int Post_getFollowers(ePost* this, int* followers);

void Post_Delete(ePost* this);

int Post_listRow(ePost* this);

int Post_mapStatLikes(void* post);
int Post_mapStatDisLikes(void* post);
int Post_mapStatFollowers(void* post);

int Post_filterLikes(void* post);
int Post_filterDislikes(void* post);

int Post_SortFollowers(void* a, void*b);

int Post_Popular(ePost* this);


