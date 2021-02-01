#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef int *BitSet;

void display(const char *name,const BitSet s);


//Implement these functions
BitSet newBitSet();
void add(BitSet s,int elem);
void removeIt(BitSet s,int elem);
int isAnElement(const BitSet s,int elem);

void destroy(BitSet *s);
void clear(BitSet s);
int isEmpty(const BitSet s);

BitSet getUnion(const BitSet s1,const BitSet s2);
BitSet getIntersection(const BitSet s1,const BitSet s2);
BitSet getDifference(const BitSet s1,const BitSet s2);
int isSubset(const BitSet s1,const BitSet s2);
int areDisjoint(const BitSet s1,const BitSet s2);


int main(){
	int test=0, n1,n2,elem;
	BitSet u_result=NULL, i_result=NULL, d_result=NULL;
	BitSet s1 = newBitSet();
	BitSet s2 = newBitSet();
	
	
	// for the first set
	scanf("%d",&n1);
	for (int i=0; i < n1; i++) {
		scanf("%d",&elem);
		add(s1,elem);
	}
	
	// for the second set
	scanf("%d",&n2);
	for (int i=0; i < n2; i++) {
		scanf("%d",&elem);
		add(s2,elem);
	}
	
	// will determine which code to run in the switch part
	scanf("%d",&test);
	display("s1",s1);
	display("s2",s2);
	add(s1,9); add(s1,20);
	removeIt(s2,0); removeIt(s2,30);
	display("s1",s1);
	display("s2",s2);
	
	switch (test) {
		// subset
		case 7: printf("isSubset(s1,s2)? %s\n",isSubset(s1,s2)?"yes":"no");
		
		// disjoint	
		case 6: printf("areDisjoint(s1,s2)? %s\n",areDisjoint(s1,s2)?"yes":"no");
		
		//difference
		case 5: d_result = getDifference(s1,s2);
				display("difference",d_result);
		
		//intersection
		case 4: i_result = getIntersection(s1,s2);
				display("intersection",i_result);		
		//union
		case 3: u_result = getUnion(s1,s2);
				display("union",u_result);
			
		//isEmpty, clear
		case 2: printf("isEmpty(s1)? %s\n",isEmpty(s1)?"yes":"no");
				printf("isEmpty(s2)? %s\n",isEmpty(s2)?"yes":"no");
				clear(s1); clear(s2);
				printf("isEmpty(s1)? %s\n",isEmpty(s1)?"yes":"no");
				printf("isEmpty(s2)? %s\n",isEmpty(s2)?"yes":"no");
						
		//add, removeIt
		case 1:	break;				
	}
	
	
	if (s1!=NULL) destroy(&s1);
	if (s2!=NULL) destroy(&s2);
	if (u_result!=NULL) destroy(&u_result);
	if (i_result) destroy(&i_result);
	if (d_result) destroy(&d_result);
	return 0;
}

void display(const char *name,const BitSet s){
	printf("%s = { ",name);
	for (int i=0; i < MAX; i++){
		if (s[i])
			printf("%d ",i);
	}	
	printf("}\n");	
}

BitSet newBitSet()
{
    BitSet set;
    int i;
    set = (BitSet)malloc(sizeof(int) * MAX);
    for (i = 0; i < MAX; i++)
        set[i] = 0;
    return set;
}

void add(BitSet s, int elem)
{
    if(elem < 10 && elem > -1)
        s[elem] = 1;
}

void removeIt(BitSet s, int elem)
{
    if(elem < 10 && elem > -1)
        s[elem] = 0;
}

int isAnElement(const BitSet s, int elem)
{
    if (s[elem] == 0)
        return 0;
    return 1;
}

void destroy(BitSet *s)
{
    free(*s);
    *s = NULL;
}

void clear(BitSet s)
{
    int i;
    for (i = 0; i < MAX; i++) s[i] = 0;
}

int isEmpty(const BitSet s)
{
    int i;
    for (i = 0; i < MAX; i++)
        if (s[i] == 1)
            return 0;
    return 1;
}

BitSet getUnion(const BitSet s1, const BitSet s2)
{
    BitSet setUnion = newBitSet();
    int i;

    for (i = 0; i < MAX; i++)
        if (s1[i] == 1 || s2[i] == 1)
            setUnion[i] = 1;
    return setUnion;
}

BitSet getIntersection(const BitSet s1, const BitSet s2)
{
    BitSet setIntersection = newBitSet();
    int i;

    for (i = 0; i < MAX; i++)
        if (s1[i] == 1 && s2[i] == 1)
            setIntersection[i] = 1;
    return setIntersection;
}

BitSet getDifference(const BitSet s1, const BitSet s2)
{
    BitSet diff = newBitSet();
    int i;
    for (i = 0; i < MAX; i++)
        if (s1[i] != s2[i] && s1[i] == 1)
            diff[i] = 1;
    return diff;
}

int isSubset(const BitSet s1, const BitSet s2)
{
    int i, j, ctrs1 = 0, ctrs2 = 0;

    for (i = 0; i < MAX; i++)
    {
        if (s1[i] == 1)
            ctrs1++;
        if(s1[i] == 1 && s1[i] == s2[i])
            ctrs2++;
    }

    return ctrs1 == ctrs2;
}

int areDisjoint(const BitSet s1, const BitSet s2)
{
    int i;
    for (i = 0; i < MAX; i++)
        if (s1[i] == 1 && s1[i] == s2[i])
            return 0;
    return 1;
}
