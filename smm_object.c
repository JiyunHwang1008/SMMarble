//
//  smm_node.c
//  SMMarble
//
//  Created by Juyeop Kim on 2023/11/05.
//

#include "smm_common.h"
#include "smm_object.h"
#include <string.h>

#define MAX_NODENR      100
#define MAX_NODETYPE    7
#define MAX_GRADE       9



static char smmobj_nodeName [MAX_NODETYPE] [MAX_CHARNAME] ={
       "lecture",
       "restaurant",
       "laboratory",
       "home",
       "gotoLab",
       "foodChance",
       "festival"
};
   
static int smmobj_nodeNr=0;   

//structure type definition
typedef struct{
	char name[MAX_CHARNAME];
	int type;
	int credit;
	int energy;
} smmobj_board_t;


//structure instance array definition 
static smmobj_board_t smmobj_board[MAX_NODENR];
 
//object generation
int smmObj_genNode(char* name, int type, int credit, int energy)
{
	strcpy(smmobj_board[smmobj_nodeNr].name, name);
    smmobj_board[smmobj_nodeNr].type = type;
    smmobj_board[smmobj_nodeNr].credit = credit;
    smmobj_board[smmobj_nodeNr].energy = energy;
    
    smmobj_nodeNr++;
    
    return (smmobj_nodeNr);
}



//member retrieving
char* smmobj_getNodeName(int node_nr)
{
	return (smmobj_board[node_nr].name);
}

int smmobj_getNodeType(int node_nr)
{
	return (smmobj_board[node_nr].type);
}

int smmobj_getNodeCredit(int node_nr)
{
	return (smmobj_board[node_nr].credit);
}

int smmobj_getNodeEnergy(int node_nr)
{
	return (smmobj_board[node_nr].energy);
}

char* smmobj_getTypeName(int node_type)
{
	return (smmobj_nodeName[node_type]);
}


#if 0
char* smmObj_getGradeName(smmGrade_e grade)
{
    return smmGradeName[grade];
}
#endif

