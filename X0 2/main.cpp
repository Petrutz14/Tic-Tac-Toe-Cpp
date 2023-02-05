#include <bits/stdc++.h>
#include <Windows.h>
#include "functions.h"
using namespace std;

int main()
{
    start();
    while(ok==1){
        if(p==1){
        ///X's Turn
            draw(a,i,j);
            cout<<"X's turn:";
            cin>>poz;

            //Input verification
            if(poz<3 || poz>9){
                while(poz>9 || poz<1){
                    cout<<endl<<"Inexistent position!"<<endl;
                    cout<<"X's turn:";
                    cin>>poz;
                }
            }
            comp(poz,i,j);
            while(a[i][j]!=0){
                cout<<endl<<"Position occupied!"<<endl;
                cout<<"X's turn:";
                cin>>poz;
                comp(poz,i,j);
            }

            //Checks for a draw
            how++;
            if(how==9){
                a[i][j]=1;
                p=5;
                check(a,p,1);
                system("cls");
            }
            else{
                a[i][j]=1;
                p=2;
                check(a,p,1);
                system("cls");
            }
        }


        else if(p==2){
            ///O's Turn
            draw(a,i,j);
            cout<<"O's turn:";
            cin>>poz;

            //Input verification
            if(poz<3 || poz>9){
                while(poz>9 || poz<1){
                    cout<<endl<<"Inexistent position!"<<endl;
                    cout<<"O's turn:";
                    cin>>poz;
                }
            }
            comp(poz,i,j);
            while(a[i][j]!=0){
                cout<<endl<<"Position occupied!"<<endl;
                cout<<"O's turn:";
                cin>>poz;
                comp(poz,i,j);
            }

            //Checks for a draw
            how++;
            if(how==9){
                a[i][j]=2;
                p=5;
                check(a,p,2);
                system("cls");
            }
            else{
                a[i][j]=2;
                p=1;
                check(a,p,2);
                system("cls");
            }
        }
        else if(p==3){
            //X Win
            draw(a,i,j);
            cout<<endl<<"Congratulations X!You won!";
            xs++;
            fdraw(a,i,j,xs,ys);
            Sleep(2500);
            p=6;
        }
        else if(p==4){
            //O Win
            draw(a,i,j);
            cout<<endl<<"Congratulations O!You won!";
            ys++;
            fdraw(a,i,j,xs,ys);
            Sleep(2500);
            p=6;
        }
        else if(p==5){
            draw(a,i,j);
            cout<<endl<<"Such a shame!It's a draw!";

            xs++;ys++;
            fdraw(a,i,j,xs,ys);
            Sleep(2500);
            p=6;
        }
        else if(p==6){
            //Play Prompt
            cout<<endl<<endl<<"Would you like to play again?(y/n)"<<endl;
            char car;
            cin>>car;
            if(car!='y' && car!='n'){
                while(car!='y' || car!='n'){
                    cout<<endl<<"Invalid option!"<<endl;
                    cout<<"Would you like to play again?(y/n)"<<endl;
                    cin>>car;}
            }
            if(car=='y'){
                p=1;how=0;poz=0;
                for(i=1;i<=3;i++){
                    for(j=1;j<=3;j++){
                        a[i][j]=0;
                    }
                }
                system("cls");
            }
            else if(car=='n'){
                ok=0;
                system("cls");
                cout<<endl<<"Goodbye!All games are saved in log.txt!";
                Sleep(4000);
            }
        }
    }



    return 0;
}


