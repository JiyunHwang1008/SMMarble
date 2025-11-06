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

#define SMMNODE_TYPE_LECTURE           0
#define SMMNODE_TYPE_RESTAURANT        1
#define SMMNODE_TYPE_LABORATORY        2
#define SMMNODE_TYPE_HOME              3
#define SMMNODE_TYPE_GOTOLAB           4
#define SMMNODE_TYPE_FOODCHANGE        5
#define SMMNODE_TYPE_FESTIVAL          6

static char smmNodeName [] [] []
   "lecture"
   "restaurant"
   
       
       

char smm_name [MAX_CHARNAME];
int sum_type[MAX_NODENR];
int sum_credit

//object generation
void smmObj_genNode(void)
{
    
}



//member retrieving



//element to string
char* smmObj_getNodeName(smmNode_e type)
{
    return smmNodeName[type];
}

char* smmObj_getGradeName(smmGrade_e grade)
{
    return smmGradeName[grade];
}

