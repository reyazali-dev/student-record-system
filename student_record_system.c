/*
@Author: Reyaz Ali
Program: Student Record Management System in C.
This program supports add,delete,search,update,load,save functions by using linked list and basic file operations.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
	int form_no;
	char name[25];
	char fathers_name[25];
	char mothers_name[25];
	char dob[12];
	char address[25];
	char contact[12];
	struct student *next;
};

struct student *HEAD=NULL,*TAIL=NULL;
int count=0;
void add_student(char name[],char fathers_name[],char mothers_name[],char dob[],char address[],char contact[]){
	struct student *temp = (struct student *)malloc(sizeof(struct student));
	if(temp==NULL){
		perror("No Enough Memory!");
		return;
	}
	struct student *ptr;
	int x = 1;
	for(ptr=HEAD;ptr!=NULL;ptr=ptr->next){
		if(strcmp(ptr->name,name)==0&&strcmp(ptr->fathers_name,fathers_name)==0&&strcmp(ptr->mothers_name,mothers_name)==0&&strcmp(ptr->dob,dob)==0){
			x = 0;
			break;
		}
	}
	if(x==0){
		printf("\nStudent Already Exists.");
		return;
	}
	
    count++;
	temp->form_no=count;
	strcpy(temp->name,name);
	strcpy(temp->fathers_name,fathers_name);
	strcpy(temp->mothers_name,mothers_name);
	strcpy(temp->dob,dob);
	strcpy(temp->address,address);
    strcpy(temp->contact,contact);
	temp->next=NULL;
	
	if(HEAD==NULL){
		HEAD=TAIL=temp;
		printf("\nStudent Inserted Sucessfully.");
		return;
	}
	TAIL->next=temp;
	TAIL=temp;
	printf("\nStudent Inserted Sucessfully.");
}

void delete(int id){
	if(HEAD==NULL){
		printf("\nNo Records Found!");
		return;
	}
	struct student *ptr = HEAD;
	int found=0;
	while(ptr!=NULL){
		if(ptr->form_no==id){
			found = 1;
			break;
		}
		ptr = ptr->next;
	}
	if(found==0){
		printf("\nStudent Not Found!");
		return;
	}
	if(ptr==HEAD){
		HEAD=HEAD->next;
		free(ptr);
		printf("\nStudent Deleted Sucessfully.");
		return;
	}
	if(ptr==TAIL){
		struct student *temp=TAIL;
		ptr = HEAD;
		while(ptr->next!=TAIL)
		ptr = ptr->next;
		ptr->next=NULL;
		TAIL = ptr;
		free(temp);
		printf("\nStudent Deleted Sucessfully.");
		return;
	}
	
	struct student *p=HEAD,*temp=ptr;
	while(p->next!=ptr)
	p = p->next;
	p->next=temp->next;
	free(ptr);
	printf("\nStudent Deleted Sucessfully.");
	
}


void view_records(void) {
    if (HEAD==NULL) {
        printf("\nNo Record Found!");
        return;
    }
    struct student *ptr = HEAD;
    printf("\n%-25s %-25s %-25s %-25s %-25s %-25s %-25s","Form No.","Name","Father's Name","Mother's Name","DOB","Address","Contact");
    printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    while (ptr!=NULL) {
        printf("\n%-25d %-25s %-25s %-25s %-25s %-25s %-25s",ptr->form_no,ptr->name,ptr->fathers_name,ptr->mothers_name,ptr->dob,ptr->address,ptr->contact);
        ptr = ptr->next;
    }
}


void search(int form_no){
	int found=0;
	struct student *ptr = HEAD;
	while(ptr!=NULL){
		if(ptr->form_no==form_no){
			found = 1;
			break;
		}
		ptr = ptr->next;
	}
	if(found!=0){
		printf("\nStudent Found!\n\n");
			printf("Form No : %d\n\nName: %s\n\nFather's Name: %s\n\nMother's Name: %s\n\nDOB: %s\n\nAddress: %s\n\nContact: %s\n",ptr->form_no,ptr->name,ptr->fathers_name,ptr->mothers_name,ptr->dob,ptr->address,ptr->contact);
			return;
	}
		printf("\nStudent Not Found!");
}

void update(int id){
	int found=0;
    struct student *ptr = HEAD;
	while(ptr!=NULL){
		if(ptr->form_no==id){
			found = 1;
			break;
		}
		ptr = ptr->next;
	}
	if(found==0){
		printf("\nStudent Not Found!");
		return;
	}
	printf("\nStudent Found!\n\n");
	printf("Form No : %d\n\nName: %s\n\nFather's Name: %s\n\nMother's Name: %s\n\nDOB: %s\n\nAddress: %s\n\nContact: %s\n",ptr->form_no,ptr->name,ptr->fathers_name,ptr->mothers_name,ptr->dob,ptr->address,ptr->contact);
	printf("\nPress 1 to Update Name.");
	printf("\nPress 2 to Update Father's Name.");
	printf("\nPress 3 to Update Mother's Name.");
	printf("\nPress 4 to Update DOB.");
	printf("\nPress 5 to Update Address.");
	printf("\nPress 6 to Update Contact Number.\n");
	int choice;
	scanf("%d",&choice);
	getchar();
	switch(choice){
		case 1:
			printf("\nEnter New Name: ");
			char name[25];
			fgets(name,sizeof(name),stdin);
			name[strcspn(name,"\n")]='\0';
			strcpy(ptr->name,name);
			printf("\nStudent Updated Sucessfully.");
			break;
		case 2:
			printf("\nEnter the Father's Name: ");
			char fathers_name[25];
			fgets(fathers_name,sizeof(fathers_name),stdin);
			fathers_name[strcspn(fathers_name,"\n")]='\0';
			strcpy(ptr->fathers_name,fathers_name);
			printf("\nStudent Updated Sucessfully.");
			break;
			
		case 3:
			printf("\nEnter Mother's Name: ");
			char mothers_name[25];
			fgets(mothers_name,sizeof(mothers_name),stdin);
			mothers_name[strcspn(mothers_name,"\n")]='\0';
			strcpy(ptr->mothers_name,mothers_name);
			printf("\nStudent Updated Sucessfully.");
			break;
			
		case 4:
			printf("\nEnter New DOB: ");
			char dob[12];
			fgets(dob,sizeof(dob),stdin);
			dob[strcspn(dob,"\n")]='\0';
			strcpy(ptr->dob,dob);
			printf("\nStudent Updated Sucessfully.");
			break;
			
		case 5:
			printf("\nEnter New Address: ");
			char address[25];
			fgets(address,sizeof(address),stdin);
			address[strcspn(address,"\n")]='\0';
			strcpy(ptr->address,address);
			printf("\nStudent Updated Sucessfully.");
			break;
			
		case 6:
			printf("\nEnter New Contact: ");
			char contact[12];
			fgets(contact,sizeof(contact),stdin);
			contact[strcspn(contact,"\n")]='\0';
			strcpy(ptr->contact,contact);
			printf("\nStudent Updated Sucessfully.");
			break;
			
		default:
			printf("\nInvalid Choice.");
	}
	
}

int save_to_file(void){
	FILE *fp;
	fp = fopen("students.txt","w");
	if(fp==NULL){
		perror("Cannot Open students.txt");
		return 0;
	}
	fprintf(fp,"%-24s %-24s %-24s %-24s %-24s %-24s %-24s","Form No.","Name","Father's Name","Mother's Name","DOB","Address","Contact");
    struct student *ptr;
    for(ptr=HEAD;ptr!=NULL;ptr=ptr->next){
    	fprintf(fp,"\n%d|%s|%s|%s|%s|%s|%s",ptr->form_no,ptr->name,ptr->fathers_name,ptr->mothers_name,ptr->dob,ptr->address,ptr->contact);
      
	}
	if(ferror(fp)||fclose(fp)!=0){
		perror("Error while writing students.txt");
		return 0;
	}
	printf("\nRecord Saved Sucessfully.");
	return 1;
}

void load_from_file(void){
	
	FILE *fp = fopen("students.txt","r");
	if(fp==NULL){
		perror("File Not Found!");
		return;
	}
	char line[300];
	while(fgets(line,sizeof(line),fp)){
		struct student *temp = malloc(sizeof(struct student));
		struct student *p;
		if(temp==NULL){
			printf("\nMemory Not Allocated.");
			break;
		}
		if(sscanf(line,"%d|%25[^|]|%25[^|]|%25[^|]|%25[^|]|%25[^|]|%25[^|]|",&temp->form_no,temp->name,temp->fathers_name,temp->mothers_name,temp->dob,temp->address,temp->contact) !=7){
			free(temp);
			continue;
		}
		for(p=HEAD;p!=NULL;p=p->next){
			if(p->form_no==temp->form_no)
			break;
		}
		    if(p!=NULL){
		    	free(temp);
		    	continue;
			}
			temp->next=NULL;
			if(HEAD==NULL){
				HEAD=TAIL=temp;
			}
			else{
				TAIL->next=temp;
				TAIL=temp;
			}
			if(temp->form_no>count)
			count = temp->form_no;
	}
		fclose(fp);
}

int main(void) {
	FILE *fp=fopen("students.txt","a");
	if(fp!=NULL)
	fclose(fp);
	load_from_file();
	printf("\n");
    printf("=========================");
    printf("\nStudent Record Management\n");
    printf("=========================");
while (1) {
    int choice;
    printf("\n");
    printf("\nPress 1 to Add a New Student.");
    printf("\nPress 2 to View All Records.");
    printf("\nPress 3 to Delete Student.");
    printf("\nPress 4 to Search a Student.");
    printf("\nPress 5 to Update Student.");
    printf("\nPress 6 to Save Records to File.");
    printf("\nPress 7 to Exit.\n");
    scanf("%d",&choice);
    getchar();
    switch (choice) {
        case 1:
            printf("\nStudent Details:\n");
            char name[25],fathers_name[25],mothers_name[25],dob[12],address[25],contact[12];
            printf("\nEnter Student's Name: ");
            fgets(name,sizeof(name),stdin);
            name[strcspn(name,"\n")]='\0';
            printf("\nEnter Father's Name: ");
            fgets(fathers_name,sizeof(fathers_name),stdin);
            fathers_name[strcspn(fathers_name,"\n")]='\0';
            printf("\nEnter Mother's Name: ");
            fgets(mothers_name,sizeof(mothers_name),stdin);
            mothers_name[strcspn(mothers_name,"\n")]='\0';
            printf("\nEnter Date of Birth (DD-MM-YYYY): ");
            fgets(dob,sizeof(dob),stdin);
            dob[strcspn(dob,"\n")]='\0';
            printf("\nEnter Address: ");
            fgets(address,sizeof(address),stdin);
            address[strcspn(address,"\n")]='\0';
            printf("\nEnter Contact Number: ");
            fgets(contact,sizeof(contact),stdin);
            contact[strcspn(contact,"\n")]='\0';
            add_student(name,fathers_name,mothers_name,dob,address,contact);
            break;
        case 2:
            view_records();
            break;
            
        case 3:
        	printf("\nEnter the Form No. or Student ID: ");
        	int frm;
        	scanf("%d",&frm);
        	delete(frm);
        	break;
        case 4:
        	printf("\nEnter the Form No. or Student ID: ");
        	int id;
        	scanf("%d",&id);
        	search(id);
        	break; 
        	
        case 5:
        	printf("\nEnter the Form No. or Student ID: ");
        	int a;
        	scanf("%d",&a);
        	update(a);
        	break;
        	
        case 6:
        	save_to_file();
        	break;
        
        case 7:
        	exit(1);
        default:
            printf("\nInvalid Choice!");
        

    }
}
    return 0;
}
