#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#endif // CONTROLLER_H_INCLUDED


int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_saveAsText(char* path , LinkedList* pArrayList);
int controller_listPost(LinkedList* pArrayList);
int controller_mapStats(LinkedList* pArrayList);
