typedef struct NODE {
    char name[20];
    char surname[20];
    char department[20];
    void* year;
    void* number;
    struct NODE* next;
    struct NODE* prev;
}node;

node *head,*tail;

struct node* createNode(const char* name, const char* surname , const char* department ,void* number , void* year) {
    node* student = (node*) malloc(sizeof(node));

    strcpy(student->name, name);
    strcpy(student->surname, surname);
    strcpy(student->department, department);
    student->number = number;
    student->year = year;

    return student;
}

void addNode(const char* name, const char* surname , const char* deparment , void* number , void* year){

    node* student = createNode(name, surname ,deparment, number ,year);
    if (head == NULL) {//if list is empty
        head = student;
        tail = student;
        head->next = NULL;
        tail->next = NULL;
        head->prev = NULL;
        tail->prev = NULL;
    }
    else {
        node* iter = head;

        while (iter != NULL && *((long long *)(iter->number))<*((long long *)number) ){
            iter = iter->next;
        }

        if (iter == head){//adding top of the list

            student->next = head;
            head->prev = student;
            head = student;
            head->prev = NULL;

        }
        else if (iter == NULL) {//adding end of the list

            tail->next = student;
            student->prev = tail;

            tail = student;
            tail->next = NULL;
            free(iter);

        }
        else {//adding somewhere in the middle of list
            iter->prev->next=student;
            student->prev = iter->prev;
            student->next = iter;
            iter->prev = student;

        }
    }

}


void deleteNode(void* key) {
    node* iter = head;
    if (head == NULL) {
        printf("This list is empty.\n");
    }
    else {

        while (iter != NULL && *((long long *)(iter->number)) != *((long long*)key) ) {
            iter = iter->next;
        }

        if (iter == NULL) {
            printf("%The student with number %d could not find!\n", *((long long*)key));
        }

        else if (iter == head && iter == tail) {//there is only one element in the list
            free(iter);
            head = NULL;
            tail = NULL;

        }
        else if (iter == head) {//delete the first element
            head = head->next;
            head->prev = NULL;
            free(iter);

        }
        else if(iter == tail) {//delete the last element
            tail = tail->prev;
            tail->next = NULL;
            free(iter);

        }
        else {//delete element somewhere in the middle of list
            iter->prev->next = iter->next;
            iter->next->prev = iter->prev;
            free(iter);

        }
        printf("The student successfully deleted.\n");
    }
}


void searchNode(void* key){

    node *iter=head;

    while(iter!=NULL && *((long long *)(iter->number)) != *((long long*)key)){
            iter=iter->next;
       }

    if(iter == NULL){
        printf("The searched student could not find!\n");
    }
    else{
        printf("The searched student's information:\nName:%s\nSurname:%s\nDepartment:%s\nNumber:%ld\nYear:%d\n",iter->name,iter->surname,iter->department,(*(long long *)iter->number),(*(int *)iter->year));

    }

}

void destroyList(){

    node* deletePtr;
    if (head == NULL) {
        printf("This list is empty!");
    }

    else {
        node* iter = head;

        while(iter!=NULL){
            deletePtr=iter;
            iter=iter->next;
            free(deletePtr);

        }
    }
    while(head!=NULL)
        head=head->next;

    if(head==NULL)
        printf("The list was destroyed successfully.\n");
    else
        printf("The list could not be destroyed!\n");
}

void printList() {
    node* iter = head;

    if(iter == NULL){
        printf("This list is empty!\n");
    }

    else {

        while (iter != NULL) {
            printf("Name:%s\nSurname:%s\nDepartment:%s\nNumber:%lld\nYear:%d\n\n",iter->name,iter->surname,  \
               iter->department,*((long long *)(iter->number)),*((int *)(iter->year)));

            iter = iter->next;
        }
    }
}

