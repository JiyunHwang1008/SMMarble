//  smm_object.c
//  smm_node.c
//  SMMarble
//
//  Created by Juyeop Kim on 2023/11/05.
//

#include "smm_common.h"
#include "smm_object.h"
#include "smm_database.h"
#include <string.h>
#include <stdlib.h>      


#define MAX_NODENR      100
#define MAX_NODETYPE    7




#define GRADE_APLUS         0
#define GRADE_A0            1
#define GRADE_AMINUS        2
#define GRADE_BPLUS         3
#define GRADE_B0            4
#define GRADE_BMINUS        5
#define GRADE_CPLUS         6
#define GRADE_C0            7
#define GRADE_CMINUS        8
#define GRADE_DPLUS         9
#define GRADE_D0            10
#define GRADE_DMINUS        11
#define GRADE_F             12

static char smmObj_nodeTypeName [7] [MAX_CHARNAME] ={
       "lecture",
       "restaurant",
       "laboratory",
       "home",
       "gotoLab",
       "foodChance",
       "festival"
};

static char smmObj_gradeName [SMMNODE_MAX_GRADE] [MAX_CHARNAME] ={
       "A+",
       "A0",
       "A-",
       "B+",
       "B0",
       "B-",
       "C+",
       "C0",
       "C-",
       "D+",
       "D0",
       "D-",
       "F"
};
   
  

//structure type definition
typedef struct{
	char name[MAX_CHARNAME];
	int objType;
	int type;
	int credit;
	int energy;
	int grade;
} smmObj_object_t;

 
//object generation
void* smmObj_genObject(char* name, int objType, int type, int credit, int energy, int grade)
{
	smmObj_object_t* ptr =
	(smmObj_object_t*)malloc(sizeof(smmObj_object_t));
	
	if (ptr != NULL) {
	
	strcpy(ptr->name, name);
    ptr->objType = objType;
    ptr->type = type;
    ptr->credit = credit;
    ptr->energy = energy;
    ptr->grade = grade;
    
    }
    
    
    
    return ( (void*)ptr);
}



//member retrieving
char* smmObj_getObjectName(int node_nr)
{
	void* ptr = smmdb_getData(LISTNO_NODE, node_nr);
	if(ptr == NULL) return NULL;
	return ((smmObj_object_t*)ptr)->name;
}

int smmObj_getNodeType(int node_nr)
{
	void* ptr = smmdb_getData(LISTNO_NODE, node_nr);
	if(ptr == NULL) return -1;
	return ((smmObj_object_t*)ptr)->type;
}

int smmObj_getNodeCredit(int node_nr)
{
	void* ptr = smmdb_getData(LISTNO_NODE, node_nr);
	if(ptr == NULL) return 0;
	return ((smmObj_object_t*)ptr)->credit;
}

int smmObj_getObjectEnergy(void *ptr)
{
	if(ptr == NULL) return 0;
	return ((smmObj_object_t*)ptr)->energy;
	/*smmObj_object_t* objPtr = (smmObj_object_t*)ptr;
	return (objPtr->energy);*/
	
}

int smmObj_getNodeEnergy(int node_nr)
{
    void* ptr = smmdb_getData(LISTNO_NODE, node_nr);
	if(ptr == NULL) return 0;
	return ((smmObj_object_t*)ptr)->energy;
}

char* smmObj_getTypeName(int node_type)
{
	if(node_type < 0 || node_type >= MAX_NODETYPE) return "Unknown";
	return smmObj_nodeTypeName[node_type];
}


#if 0
char* smmObj_getGradeName(int grade)
{
    return smmObj_gradeName[grade];
}
#endif

char* smmObj_getGradeName(int grade)
{
	 if (grade < 0 || grade >= SMMNODE_MAX_GRADE) return "Unknown";
	return smmObj_gradeName[grade];
}

int smmObj_getObjectGrade(void *ptr){
	if(ptr == NULL) return 0;
	return ((smmObj_object_t*)ptr)->grade;
}

char* smmObj_getObjectNamePtr(void* ptr){
	if(ptr == NULL) return NULL;
	return ((smmObj_object_t*)ptr)->name;
}
//@@
