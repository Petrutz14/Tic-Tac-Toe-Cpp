#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;
ofstream out("log.txt",ios::app);

int a[4][4]={};
int p=1,poz,i,j,how=0,ok=1,xs=0,ys=0;

//Draws the board
void draw(int a[4][4],int i,int j){
    for(i=1;i<=3;i++){
        for(j=1;j<=3;j++){
            if(a[i][j]==1){
                cout<<"x";
                if(j!=3){cout<<" ";}
            }
            else if(a[i][j]==2){
                cout<<"o";
                if(j!=3){cout<<" ";}
            }
            else{
                cout<<"-";
                if(j!=3){cout<<" ";}
            }
        }
        cout<<endl;
    }
}

//Determines the x and y(i and j) of the X/O
void comp(int poz,int&i,int&j){
    if(poz<=3){
        i=1;j=poz;
    }
    else if(poz>3 && poz<=6){
        i=2;j=poz-3;
    }
    else if(poz>6 && poz<=9){
        i=3;j=poz-6;
    }
}


//Checks if X/O has won
void check(int a[4][4],int&p,int ce){
    if(a[1][1]==ce){
        if(a[1][2]==ce && a[1][3]==ce){p=ce+2;}
        if(a[2][1]==ce && a[3][1]==ce){p=ce+2;}
        if(a[2][2]==ce && a[3][3]==ce){p=ce+2;}
    }
    if(a[1][2]==ce){
        if(a[2][2]==ce && a[3][2]==ce){p=ce+2;}
    }
    if(a[1][3]==ce){
        if(a[2][2]==ce && a[3][1]==ce){p=ce+2;}
        if(a[2][3]==ce && a[3][3]==ce){p=ce+2;}
    }
    if(a[2][1]==ce){
        if(a[2][2]==ce && a[2][3]==ce){p=ce+2;}
    }
    if(a[3][1]==ce){
        if(a[3][2]==ce && a[3][3]==ce){p=ce+2;}
    }
}

void start(){
cout<<"Welcome To Tic-Tac-Toe!"<<endl;
    Sleep(2500);
    system("cls");
    cout<<"How To Play:"<<endl;
    Sleep(1000);
    cout<<"1.Each player will input the position of their ticks."<<endl;
    Sleep(3000);
    cout<<"2.X starts first."<<endl;
    Sleep(3000);
    cout<<"3.First player to get 3 in a row wins."<<endl;
    Sleep(3000);
    cout<<"4.If neither player succeds,the game ends in a draw."<<endl;
    Sleep(3000);
    system("cls");
    cout<<"These are the positions:"<<endl;
    Sleep(1000);
    cout<<"1 2 3"<<endl;
    cout<<"4 5 6"<<endl;
    cout<<"7 8 9";
    Sleep(4000);
    system("cls");
}

void fdraw(int a[4][4],int i,int j,int xs,int ys){
    for(i=1;i<=3;i++){
        for(j=1;j<=3;j++){
            if(a[i][j]==1){
                out<<"x";
                if(j!=3){out<<" ";}
            }
            else if(a[i][j]==2){
                out<<"o";
                if(j!=3){out<<" ";}
            }
            else{
                out<<"-";
                if(j!=3){out<<" ";}
            }
        }
        out<<endl;
    }
    out<<"("<<xs<<"-"<<ys<<");"<<endl<<endl;
}



