#include<iostream>
using namespace std;

class shop{
    private:
    int itemID[100];
    int itemPrice[100];
    int counter;
    
    public:
        void initcounter(void){ counter =0; }
        void setPrice(void);
        void displayPrice(void);
     
};

void shop :: setPrice(void){
    cout<<"enter id of your item "<<counter + 11<<endl;
    cin>>itemID[counter];
    cout<<"enter the price of your item "<<endl;
    cin>>itemPrice[counter];
    counter ++;
}

void shop :: displayPrice(void){
    for (int i = 0; i < counter; i++)
    {
                cout<<"the price of item with ID"<<itemID[i]<<"is"<<itemPrice[i]<<endl;
    }
    
}

int main(){
    shop dukaan;
    dukaan.initcounter();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.displayPrice();
    return 0;
}