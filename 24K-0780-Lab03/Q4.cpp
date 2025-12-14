#include <iostream>
using namespace std;


class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data = val;
        next=NULL;
        prev=NULL;
    }
};

class list {
    node* head;
    node* tail;

    public:
        list(){
            head=tail=NULL;
        }
        node* gethead(){
            return head;
        }
        void sortlist(){
            if(head==NULL || head->next==NULL){
                return;
            }
            bool swapped;
            do{
                swapped=false;
                node* current=head;
                while(current->next!=NULL){
                    if(current->data>current->next->data){
                        swap(current->data,current->next->data);
                        swapped=true;
                    }
                    current=current->next;
                }
            }while(swapped);
        }


        void concat(list &l2){
            if(head==NULL){
                head=l2.head;
                tail=l2.tail;
                return;
            }
            if(l2.head==NULL){
                return;
            }
            tail->next=l2.head;
            l2.head->prev=tail;
            tail=l2.tail;
        }

        node* middlenode(){
            node* slow=head;
            node* fast=head;
            while(fast!=NULL&&fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
            }
            return slow;
        }

        void remove_duplicates(){
            if(head==NULL)  return;
            node* current=head;
            while(current!=NULL){
                node *temp=current;
                while(temp->next!=NULL){
                    if (current->data==temp->next->data){
                        node* nodetobedeleted=temp->next;
                        if(temp->next==tail){
                            tail=temp;
                            tail->next=NULL;
                        }else{
                            temp->next=temp->next->next;
                        }
                         delete nodetobedeleted;
                    }else{
                        temp=temp->next;
                    }
                }
                current=current->next;
            }
        }

        node* merge2sortedLists(node* h1,node*h2){
            if (h1==NULL||h2==NULL){
                return h1==NULL ? h2:h1;
            }

            if(h1->data<=h2->data){
                h1->next=merge2sortedLists(h1->next,h2);
                return h1;
            }else{
                h2->next=merge2sortedLists(h1,h2->next);
                return h2;
            }
        }

        void merge2sortedList(list &l2){
        	
            head=merge2sortedLists(head,l2.head);
            node* temp=head;
            while(temp!=NULL && temp->next!=NULL){
                temp=temp->next;
            }
            tail=temp;
        }



        void pushback(int val){
            node* newnode=new node(val);
            if(head==NULL){
                head=tail=newnode;
            }else{
                tail->next=newnode;
                newnode->prev=tail;
                tail=newnode;
            }
        }
        void display(){
            node *temp=head;
            while (temp!=NULL){
                cout<< temp->data<<"\n";
                temp=temp->next;
            }
            cout <<endl;
        }
 
};


int main() {

    list a;
    a.pushback(10);
    a.pushback(4);
    a.pushback(7);
    a.pushback(10);
    a.pushback(1);

    a.display();

    a.sortlist();
    a.display();

    a.remove_duplicates();
    a.display();

    list b;
    b.pushback(9);
    b.pushback(12);
    b.pushback(15);

    b.display();

    a.concat(b);
    a.display();

    node* midNode = a.middlenode();
    if (midNode != NULL)
        cout << midNode->data << endl;

    list x, y;
    x.pushback(2);
    x.pushback(6);
    x.pushback(14);

    y.pushback(3);
    y.pushback(8);
    y.pushback(11);

    x.display();
    y.display();

    x.merge2sortedList(y);
    x.display();
}

