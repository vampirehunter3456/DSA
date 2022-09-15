#include<iostream>
using namespace std;

class circular_queue
{
    private:
        int rear=-1,front=-1,x,length;
    
    public:
        void len(int y){
            length=y;
        }

        //inserting
        void insert(int *p){
            if((rear+1)%length==front){
                cout<<"queue is full"<<endl;      // checking weather queue is full
            }
            else{
                if (front==-1){
                    front++;        //after inserting updating the front
                }
                cout<<"Enter value=";
                rear++;
                cin>>*(p+rear);
                if(rear==length){
                    rear=rear%length;    //if rear increases from length of array then upade the value to begining
                }
            }
        }


        void del (int *p)
        {
            if(front==-1){
                cout<<"stack is empty"<<endl;
                return;
            }
            if(front==rear){
                x=*(p+front);   // if we have only one element then upadte the value of front to -1 after deletion
                front=-1;
                rear=-1;
            }
            else{
                x=*(p+front);   // storing the value needed to be returned
                front++;
                if(front==length){
                    front=0;    //if front was at last setting it to 0 after deletion
                }
            }
        }


        int ret(){      // returning the deleted value
            return x;
        }

        void is_full(){         // checking weather the queue is full
            if((rear+1)%length==front){
                cout<<"queue is full"<<endl;
            }
            else{
                cout<<"queue has space"<<endl;
            }
        }

        void is_empty(){
            if(front==-1){
                cout<<"queue os empty"<<endl;
                return;
            }
            cout<<"queue is being used"<<endl;
        }

        void print(){   // printing value of front and rear
            cout<<"front="<<front<<endl;
            cout<<"rear="<<rear<<endl;
        }
};

int main()
{
    int arr[10],z;
    circular_queue c;
    c.len(10);
    c.is_empty();
    for(int i=0;i<10;i++)
    {
        c.insert(arr);
        c.print();
    }
    for(int i=0;i<10;i++)
    {
        c.del(arr);
        z=c.ret();
        c.print();
        cout<<"deleted element="<<z<<endl;
    }
    c.print();
    return 0;
}