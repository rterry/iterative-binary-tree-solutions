#define Nelts(a)            (sizeof(a) / sizeof((a)[0]))

struct node 
{
	int data;
	struct node *parent;
	struct node *left;
	struct node *right;
	short int visited;
};

void Append(struct node **headRef, int data);
int getLength(struct node *headRef);
int Max_Depth(struct node *headRef);
int Min_Value(struct node *headRef);
void Print_Tree(struct node *headRef);
void Print_Post_Order(struct node *headRef, int length, int depth);
void Print_Paths(struct node *headRef, int depth);
void Mirror_Tree(struct node *headRef);
void Double_Tree(struct node *headRef);
void ElementSearch(struct node *headRef, int content, int *count);
void MakeNode(struct node **headRef, int data);
int Same_Tree(struct node *head1, struct node *head2, int length, int length2, int depth, int depth2);
void Is_Search_Tree(struct node *headRef);
void ISBSTTESTER(struct node *headRef, int HIHOLDER, int LOHOLDER);
void GrabElem(struct node *headRef, int length, int depth, int *ptr);
void NonSearchableTree(struct node **headRef, int data);//evens are searchable and odds just pushed
void freeElements(struct node **headRef);
int yesno(char *prompt);
void read_int(char *prompt, int *choice);
void enter(char *prompt);
