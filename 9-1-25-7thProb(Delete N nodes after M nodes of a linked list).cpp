class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        Node* temp1= head;
        Node* temp2=head;
        int i=0,j=0,curCount=1;
        while(temp2->next!=NULL && temp2!=NULL && temp1!=NULL){
            if(curCount==m){
                int k=0;
                while(k<n && temp2->next!=NULL){
                    temp2=temp2->next;
                    k++;
                }
                
                    if(temp2->next!=NULL){
                temp1->next=temp2->next;
                temp1=temp1->next;
                temp2=temp1;
                    }
                    else{
                        temp1->next=NULL;
                    }
                
                curCount=1;
            }
            else{
                temp1=temp1->next;
                temp2=temp1;
                curCount++;
            }
        }
        return head;
    }
};
