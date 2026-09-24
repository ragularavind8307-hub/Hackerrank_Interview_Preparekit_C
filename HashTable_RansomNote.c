void checkMagazine(int magazine_count,char** magazine,int note_count,char** note)
{
#define SIZE 100003
    typedef struct Node{
        char *word;
        int count;
        struct Node *next;
    }Node;

    Node *table[SIZE]={NULL};

    for(int i=0;i<magazine_count;i++)
    {
        unsigned int h=0;
        char *p=magazine[i];

        while(*p)
            h=h*31+*p++;

        int index=h%SIZE;
        Node *temp=table[index];

        while(temp!=NULL)
        {
            if(strcmp(temp->word,magazine[i])==0)
            {
                temp->count++;
                break;
            }
            temp=temp->next;
        }

        if(temp==NULL)
        {
            Node *newNode=malloc(sizeof(Node));
            newNode->word=magazine[i];
            newNode->count=1;
            newNode->next=table[index];
            table[index]=newNode;
        }
    }

    for(int i=0;i<note_count;i++)
    {
        unsigned int h=0;
        char *p=note[i];

        while(*p)
            h=h*31+*p++;

        int index=h%SIZE;
        Node *temp=table[index];

        while(temp!=NULL&&strcmp(temp->word,note[i])!=0)
            temp=temp->next;

        if(temp==NULL||temp->count==0)
        {
            printf("No\n");
            return;
        }

        temp->count--;
    }

    printf("Yes\n");
}
