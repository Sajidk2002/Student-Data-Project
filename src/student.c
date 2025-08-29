#include<stdio.h>
#include"header.h"
#include<string.h>
int c=0,ch,roll,del_roll,n=0,i,n1,flag2=0;
float marks;
char name[20];
int delete[20];
int flag=0;
void main(){
    SRM *headptr=0;
    char op;
    while(1){
        printf("enter option\n");
        printf("a/A)add_node  b/B)delete_node  c/C)print_node d/D) modify_node e/E) save_file  f/F) read_file g/G)sort_data i/I)delete_all R/r)reverse s)save and exit\n");
        scanf(" %c",&op);
        switch(op){
            case 'A':
            case 'a':add_node(&headptr);break;
            case 'B':
            case 'b':delete_node(&headptr);break;
            case 'C':
            case 'c':print_node(headptr);break;
            case 'D':
            case 'd':modify_node(headptr);break;
        
            case 'e':save_file(headptr);break;
            case 'f':
            case 'F':read_file(&headptr);break;
            case 'g':
            case 'G':sort_data(headptr);break;
            case 'i':
            case 'I':delete_all(&headptr);break;
            case 'r':
            case 'R':reverse(&headptr);break;
            case 's':save_exit(headptr);break;
            case 'E':exit(0);
            default:printf("wrong choice\n");
        }

    }
}


void add_node(SRM **ptr) {
    SRM *new, *last;
    new = malloc(sizeof(SRM));
    
    if (flag) {
        for (int i = 0; i < n; i++) {
            new->rollno = delete[i]; 
            printf("Enter details to add for roll no %d:\n", new->rollno);
            scanf(" %s %f", new->name, &new->marks);

            if ((*ptr == NULL) || (new->rollno < (*ptr)->rollno)) {
                new->next = *ptr;
                *ptr = new;
            } else {
                last = *ptr;
                while ((last->next != NULL) && (new->rollno > last->next->rollno)) {
                    last = last->next;
                }
                new->next = last->next;
                last->next = new;
            }
             new = malloc(sizeof(SRM)); 
        }
        flag = 0; 
    } else { 
        new->rollno = ++c; 
        printf("Enter details to add for roll no %d:\n", new->rollno);
        scanf(" %s %f", new->name, &new->marks);

        if ((*ptr == NULL) || (new->rollno < (*ptr)->rollno)) {
            new->next = *ptr;
            *ptr = new;
        } else {
            if(flag2==1){
                 new->next = *ptr;
                *ptr = new;
            }
            else if(flag==2||c!=0){
            last = *ptr;
            while ((last->next != NULL) && (new->rollno > last->next->rollno)) {
                last = last->next;
            }
            new->next = last->next;
            last->next = new;
            
            }
           
        }
    }
    if(flag2==1)
    sort_data2(*ptr);
    else if(flag2==2)
    sort_data1(*ptr);
}



void delete_node(SRM **ptr) {
    flag = 1; 
    printf("R/r) Enter roll no to delete  N/n) Enter name to delete\n");
    scanf(" %c", &ch);

    if (ch == 'r' || ch == 'R') {
        if (*ptr == NULL) {
            printf("No nodes to delete\n");
            return;
        }

        printf("How many records do you want to delete?\n");
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            printf("Enter roll no to delete:\n");
            int roll;
            scanf("%d", &roll);
            delete[i] = roll; 

            SRM *del = *ptr, *prev = NULL;
            while (del != NULL) {
                if (del->rollno == roll) {
                    if (del == *ptr) {
                        *ptr = del->next;
                    } else {
                        prev->next = del->next;
                    }
                    free(del);
                    printf("Record with roll no %d deleted\n", roll);
                    break;
                }
                prev = del;
                del = del->next;
            }
        }
    }

    else if(ch=='n'||ch=='N'){
        printf("enter the name\n");
        scanf("%s",name);
        SRM *ext=*ptr;
        printf("records are\n");
        while(ext){
            if(strcmp(ext->name,name)==0)
            printf("%d %s %f\n",ext->rollno,ext->name,ext->marks);
            ext=ext->next;
        }
        SRM *del,*prev;
        
        printf("How many records do you want to delete?\n");
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            printf("Enter roll no to delete:\n");
            int roll;
            scanf("%d", &roll);
            delete[i] = roll; // Store the deleted roll number

            SRM *del = *ptr, *prev = NULL;
            while (del != NULL) {
                if (del->rollno == roll) {
                    if (del == *ptr) {
                        *ptr = del->next;
                    } else {
                        prev->next = del->next;
                    }
                    free(del);
                    printf("Record with roll no %d deleted\n", roll);
                    break;
                }
                prev = del;
                del = del->next;
            }
        }
    }
    else
    printf("enter correct choice\n");
   
}

void print_node(SRM *ptr){
    if(ptr==0){
        printf("no records\n");
        return;
    }
    while(ptr){
        printf("%d %s %.2f\n",ptr->rollno,ptr->name,ptr->marks);
        ptr=ptr->next;
    }
}

void modify_node(SRM *ptr){
    int found=0,c1=0;
    printf("enter records to be modified\n");
    printf("a)name b)marks\n");
    scanf(" %c",&ch);
    if(ch=='a'){
        printf("enter name to be modify\n");
        scanf("%s",name);
        SRM *ext=ptr;
        while(ext){
            if(strcmp(ext->name,name)==0)
		c1++;
            ext=ext->next;
        }
	if(c1>1){
		 SRM *ext1=ptr;
 		while(ext1){
            	if(strcmp(ext1->name,name)==0)
		printf("%d %s %f\n",ext1->rollno,ext1->name,ext1->marks);
            	ext1=ext1->next;
        	}
       		 printf("enter roll no\n");
       		 scanf("%d",&roll);
       		 while(ptr){
        		if(ptr->rollno==roll){
		   		 found=1;
		       		 printf("recored is present\n");
		       		 printf("enter details to modify\n");
		           		SRM *new;
		            		new=malloc(sizeof(SRM));
                    		scanf("%s",new->name);
           			strcpy(ptr->name,new->name);
          			  free(new);
           			 printf("record updated\n");
           
        		}
           		 ptr=ptr->next;
       	 	}
        
	}
	else{
		 while(ptr){
        		if(strcmp(ptr->name,name)==0){
		   		 found=1;
		       		 printf("recored is present\n");
		       		 printf("enter details to modify\n");
		           		SRM *new;
		            		new=malloc(sizeof(SRM));
                    		scanf("%s",new->name);
           			strcpy(ptr->name,new->name);
          			  free(new);
           			 printf("record updated\n");
           
        		}
           		 ptr=ptr->next;
       	 	}
        
	}
		
	
    }
    else if (ch=='b'){
         printf("enter marks to be modify\n");
        scanf("%f",&marks);
        SRM *ext=ptr;
        while(ext){
            if(ext->marks==marks)
		c1++;
            ext=ext->next;
        }
	if(c1>1){
		 SRM *ext1=ptr;
 		while(ext1){
            	if(ext1->marks==marks)
		printf("%d %s %f\n",ext1->rollno,ext1->name,ext1->marks);
            	ext1=ext1->next;
        	}
       		 printf("enter roll no\n");
       		 scanf("%d",&roll);
       		 while(ptr){
        		if(ptr->rollno==roll){
		   		 found=1;
		       		 printf("recored is present\n");
		       		 printf("enter details to modify\n");
		           		SRM *new;
		            		new=malloc(sizeof(SRM));
                    		scanf("%f",&new->marks);
				ptr->marks=new->marks;
           			//strcpy(ptr->name,new->name);
          			  free(new);
           			 printf("record updated\n");
           
       			}		
           			 ptr=ptr->next;
       		 }
       
	}
	else{
			while(ptr){
        		if(ptr->marks==marks){
		   		 found=1;
		       		 printf("recored is present\n");
		       		 printf("enter details to modify\n");
		           		SRM *new;
		            		new=malloc(sizeof(SRM));
                    		scanf("%f",&new->marks);
           			ptr->marks=new->marks;
          			  free(new);
           			 printf("record updated\n");
           
        		}
           		 ptr=ptr->next;
       	 	}
	
    }
}
}

    

    void save_file(SRM *ptr){
            if(ptr==0){
                printf("no records founf\n");
                return;
            }
            FILE *fp=fopen("student.txt","w");
            while(ptr){
                fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
                ptr=ptr->next;
            }
            fclose(fp);
            printf("data saved in a file\n");
    }

 void read_file(SRM **ptr) {
    SRM *new, *last;
    FILE *fp = fopen("student.txt", "r");
    if (!fp) {
        printf("Data not present\n");
        return;
    }
    while (*ptr) {
        SRM *temp = *ptr;
        *ptr = (*ptr)->next;
        free(temp);
    }
    while (1) {
        new = malloc(sizeof(SRM));
        if (fscanf(fp, "%d %s %f", &new->rollno, new->name, &new->marks) == -1) {
            free(new);
            break;
        }
        new->next = 0;

        if (*ptr == NULL) {
            *ptr = new; 
        } else {
            last = *ptr;
            while (last->next)
                last = last->next; 
            last->next = new;     
        }
    }

    fclose(fp);
    SRM *prt = *ptr;
    printf("List after reading from file:\n");
    while (prt) {
        printf("%d %s %.2f\n", prt->rollno, prt->name, prt->marks);
        prt = prt->next;
    }
}

int count_node(SRM *ptr){
    int c=0;
    while(ptr){
        c++;
        ptr=ptr->next;
    }
    return c;
}

void sort_data(SRM *ptr){
    printf("N/n)sort with name P/p)sort with marks\n");
    scanf(" %c",&ch);
    if(ch=='N' || ch=='n'){
    if(ptr==0){
        printf("no records\n");
        return;
    }
    SRM *p1=ptr,*p2,temp;
    int i,j,c=count_node(ptr);
    for(i=0;i<c-1;i++){
        p2=p1->next;
        for(j=0;j<c-i-1;j++){
            if(strcmp(p1->name,p2->name)>0){
                temp.rollno=p1->rollno;
                strcpy(temp.name,p1->name);
                temp.marks=p1->marks;

                p1->rollno=p2->rollno;
                strcpy(p1->name,p2->name);
                p1->marks=p2->marks;

                p2->rollno=temp.rollno;
                strcpy(p2->name,temp.name);
                p2->marks=temp.marks;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
    }

    else if(ch=='p' || ch=='P'){
    if(ptr==0){
        printf("no records\n");
        return;
    }
    SRM *p1=ptr,*p2,temp;
    int i,j,c=count_node(ptr);
    for(i=0;i<c-1;i++){
        p2=p1->next;
        for(j=0;j<c-i-1;j++){
            if(p1->marks> p2->marks){
                temp.rollno=p1->rollno;
                strcpy(temp.name,p1->name);
                temp.marks=p1->marks;

                p1->rollno=p2->rollno;
                strcpy(p1->name,p2->name);
                p1->marks=p2->marks;

                p2->rollno=temp.rollno;
                strcpy(p2->name,temp.name);
                p2->marks=temp.marks;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
    }
}

void delete_all(SRM **ptr){
    if(*ptr == 0){
        printf("no record found\n");
        return;
    }
    SRM *del = *ptr;
    int count = 1;
    while(del){
        *ptr = del->next;
        free(del);
        printf("deleted node %d\n", count++);
        del = *ptr;
    }
    printf("all nodes are deleted\n");
    *ptr = NULL;
    c = 0; 
}



void reverse(SRM **ptr){
    flag2++;
    if(flag2>2)
    flag2=1;
    if(*ptr==0){
        printf("no record found\n");
        return;
    }
    int c=count_node(*ptr);
    SRM **p,*temp=*ptr;
    if(c>1){
        p=malloc(sizeof(SRM *)*c);
        int i=0;
        while(temp){
            p[i++]=temp;
            temp=temp->next;
        }
        for(i=1;i<c;i++)
            p[i]->next=p[i-1];
            p[0]->next=0;
            *ptr=p[c-1];
        
    }
    printf("reverse is successfull\n");

}
void save_exit(SRM *ptr){
    printf("s)save and exit e)exit without saving\n");
    scanf(" %c",&ch);
    if(ch=='s'){
        save_file(ptr);
        return;
    }
    else
    exit(0);
}

void sort_data1(SRM *ptr){
 if(ptr==0){
        printf("no records\n");
        return;
    }
    SRM *p1=ptr,*p2,temp;
    int i,j,c=count_node(ptr);
    for(i=0;i<c-1;i++){
        p2=p1->next;
        for(j=0;j<c-i-1;j++){
            if(p1->rollno> p2->rollno){
                temp.rollno=p1->rollno;
                strcpy(temp.name,p1->name);
                temp.marks=p1->marks;

                p1->rollno=p2->rollno;
                strcpy(p1->name,p2->name);
                p1->marks=p2->marks;

                p2->rollno=temp.rollno;
                strcpy(p2->name,temp.name);
                p2->marks=temp.marks;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
}
void sort_data2(SRM *ptr){
 if(ptr==0){
        printf("no records\n");
        return;
    }
    SRM *p1=ptr,*p2,temp;
    int i,j,c=count_node(ptr);
    for(i=0;i<c-1;i++){
        p2=p1->next;
        for(j=0;j<c-i-1;j++){
            if(p1->rollno< p2->rollno){
                temp.rollno=p1->rollno;
                strcpy(temp.name,p1->name);
                temp.marks=p1->marks;

                p1->rollno=p2->rollno;
                strcpy(p1->name,p2->name);
                p1->marks=p2->marks;

                p2->rollno=temp.rollno;
                strcpy(p2->name,temp.name);
                p2->marks=temp.marks;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
}