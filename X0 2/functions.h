#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;
ofstream out("rezultate.txt");
int t[4][4],turn=1,poz,it,jt,men,castig=-2,tries=0,wx=0,wo=0,temp=-1;

//Pune -1 in fiecare patratica
void start(int t[4][4]){
    system("cls");
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            t[i][j]=-1;
        }
    }
}

//Deseneaza tabla
void draw(int t[4][4]){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(t[i][j]==1){
                if(j==3){cout<<"X"<<endl;Sleep(100);}
                else{cout<<"X ";Sleep(50);}
            }
            else if(t[i][j]==0){
                if(j==3){cout<<"O"<<endl;Sleep(100);}
                else{cout<<"O ";Sleep(50);}
            }
            else if(t[i][j]==-1){
                if(j==3){cout<<"-"<<endl;Sleep(100);}
                else{cout<<"- ";Sleep(50);}
            }
        }
        cout<<endl;
    }
}
//Calculeaza pozitie pt X/O
void pozcalc(int&poz,int&it,int&jt){

    if(poz<=3){
        it=1;jt=poz;
    }
    else if(poz>3 && poz<=6){
        it=2;jt=poz-3;
    }
    else if(poz>6 && poz<=9){
        it=3;jt=poz-6;
    }
}
//Verifica existenta pozitiei
void checkex(int&poz,int&it,int&jt){

    while(poz<1 || poz>9){
        system("cls");
        cout<<"Pozitie inexistenta"<<endl;Sleep(1500);
        system("cls");
        draw(t);
        cout<<"Introduceti pozitia:";
        cin>>poz;
    }
    pozcalc(poz,it,jt);

}
//Verifica daca pozitia este ocupata
void checkoc(int t[4][4],int&it,int&jt,int&poz){
    pozcalc(poz,it,jt);
    while(t[it][jt]!=-1){
        system("cls");
        cout<<"Pozitie ocupata"<<endl;Sleep(1500);
        system("cls");
        draw(t);
        cout<<"Introduceti pozitia:";
        cin>>poz;
        pozcalc(poz,it,jt);
    }
}
//Introduce valori in tabla
void intro(int&turn,int it,int jt,int t[4][4]){
    if(turn==1){
        t[it][jt]=1;
        turn=0;
        tries++;
    }
    else{
        t[it][jt]=0;
        turn=1;
        tries++;
    }
}
//Verifica starea jocului
void win(int t[4][4],int sim,int turn,int&castig){
    if(t[2][2]==sim){
        if(t[1][1]==sim && t[3][3]==sim){castig=sim;}
        if(t[1][3]==sim && t[3][1]==sim){castig=sim;}
        if(t[1][2]==sim && t[3][2]==sim){castig=sim;}
        if(t[2][1]==sim && t[2][3]==sim){castig=sim;}
    }
    if(t[1][1]==sim){
        if(t[1][2]==sim && t[1][3]==sim){castig=sim;}
        if(t[2][1]==sim && t[3][1]==sim){castig=sim;}
    }
    if(t[3][3]==sim){
        if(t[1][3]==sim && t[2][3]==sim){castig=sim;}
        if(t[3][1]==sim && t[3][2]==sim){castig=sim;}
    }
}

//Castig X
void winx(int&castig,int&wx,int&wo,int&temp){
    if(castig==1){
        system("cls");
        cout<<"Felicitari,X!Ati castigat!"<<endl<<endl;Sleep(2000);
        wx++;
        out<<"Scor:"<<wx<<"-"<<wo<<"(Castig X)"<<endl;
        cout<<"Scor:"<<wx<<"-"<<wo<<endl<<endl;Sleep(500);
        cout<<"1.Revansa"<<endl<<endl;Sleep(100);
        cout<<"2.Iesire"<<endl<<endl;Sleep(100);
        cout<<"Introduceti optiunea:";
        cin>>temp;
        while(temp<1 || temp>2){
            system("cls");
            cout<<"Optiune incorecta";Sleep(2000);
            system("cls");
            cout<<"Scor:"<<wx<<"-"<<wo<<endl<<endl;Sleep(500);
            cout<<"1.Revansa"<<endl<<endl;Sleep(100);
            cout<<"2.Iesire"<<endl<<endl;Sleep(100);
            cout<<"Introduceti optiunea:";
            cin>>temp;

        }
        if(temp==2){
            system("cls");
            out<<"Scor final:"<<wx<<"-"<<wo<<"(X-O)"<<endl;
            cout<<"Scor final:"<<wx<<"-"<<wo<<endl;Sleep(2000);
            system("cls");
            cout<<"Multumesc pentru atentie!";Sleep(2000);
            exit(0);
        }
    }
}

//Castig O
void wino(int&castig,int&wx,int&wo,int&temp){
    if(castig==0){
        system("cls");
        cout<<"Felicitari,O!Ati castigat!"<<endl<<endl;Sleep(2000);
        wo++;
        out<<"Scor:"<<wx<<"-"<<wo<<"(Castig O)"<<endl;
        cout<<"Scor:"<<wx<<"-"<<wo<<endl<<endl;Sleep(500);
        cout<<"1.Revansa"<<endl<<endl;Sleep(100);
        cout<<"2.Iesire"<<endl<<endl;Sleep(100);
        cout<<"Introduceti optiunea:";
        cin>>temp;
        while(temp<1 || temp>2){
            system("cls");
            cout<<"Optiune incorecta";Sleep(2000);
            system("cls");
            cout<<"Scor:"<<wx<<"-"<<wo<<endl<<endl;Sleep(500);
            cout<<"1.Revansa"<<endl<<endl;Sleep(100);
            cout<<"2.Iesire"<<endl<<endl;Sleep(100);
            cout<<"Introduceti optiunea:";
            cin>>temp;

        }
        if(temp==2){
            system("cls");
            out<<"Scor final:"<<wx<<"-"<<wo<<"(X-O)"<<endl;
            cout<<"Scor final:"<<wx<<"-"<<wo<<endl;Sleep(2000);
            system("cls");
            cout<<"Multumesc pentru atentie!";Sleep(2000);
            exit(0);
        }
    }
}

//Egalitate
void egal(int&castig,int&wx,int&wo,int&temp){
    castig=-1;
    system("cls");
    cout<<"Egaliate"<<endl<<endl;Sleep(2000);
    wx++;wo++;
    out<<"Scor:"<<wx<<"-"<<wo<<"(Egalitate)"<<endl;
    cout<<"Scor:"<<wx<<"-"<<wo<<endl<<endl;Sleep(500);
    cout<<"1.Revansa"<<endl<<endl;Sleep(100);
    cout<<"2.Iesire"<<endl<<endl;Sleep(100);
    cout<<"Introduceti optiunea:";
    cin>>temp;
    while(temp<1 || temp>2){
        system("cls");
        cout<<"Optiune incorecta";Sleep(2000);
        system("cls");
        cout<<"Scor:"<<wx<<"-"<<wo<<endl<<endl;Sleep(500);
        cout<<"1.Revansa"<<endl<<endl;Sleep(100);
        cout<<"2.Iesire"<<endl<<endl;Sleep(100);
        cout<<"Introduceti optiunea:";
        cin>>temp;

    }
    if(temp==2){
        system("cls");
        out<<"Scor final:"<<wx<<"-"<<wo<<"(X-O)"<<endl;
        cout<<"Scor final:"<<wx<<"-"<<wo<<endl;Sleep(2000);
        system("cls");
        cout<<"Multumesc pentru atentie!";Sleep(2000);
        exit(0);
    }
}

//Logica scurtata X
void logicx(int t[4][4],int&tries,int&it,int&jt,int&turn,int&castig,int&poz,int&wx,int&wo,int&temp){
    draw(t);
    cout<<"X,Introduceti pozitia:";
    cin>>poz;
    checkex(poz,it,jt);
    checkoc(t,it,jt,poz);
    intro(turn,it,jt,t);
    win(t,1,turn,castig);
    winx(castig,wx,wo,temp);
}

//logica scurtata O
void logico(int t[4][4],int&tries,int&it,int&jt,int&turn,int&castig,int&poz,int&wx,int&wo,int&temp){
    draw(t);
    cout<<"O,Introduceti pozitia:";
    cin>>poz;
    checkex(poz,it,jt);
    checkoc(t,it,jt,poz);
    intro(turn,it,jt,t);
    win(t,0,turn,castig);
    wino(castig,wx,wo,temp);
}


///---------------------------------------------------------

///X si O
void joc(int t[4][4],int&tries,int&it,int&jt,int&turn,int&castig,int&poz,int&wx,int&wo,int&temp){
    start(t);
    while(true){
        //Egalitate
        if(tries==9){
            egal(castig,wx,wo,temp);
            if(temp==1){
                turn=1;tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        //X
        else if(turn==1){
            logicx(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            if(temp==1){
                turn=1;tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        //O
        else{
            logico(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            if(temp==1){
                turn=1;tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        system("cls");
    }
}

///O si X
void joc_o_x(int t[4][4],int&tries,int&it,int&jt,int&turn,int&castig,int&poz,int&wx,int&wo,int&temp){
    turn=0;
    start(t);
    while(true){
        //Egalitate
        if(tries==9){
            egal(castig,wx,wo,temp);
            if(temp==1){
                turn=0;tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc_o_x(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        //X
        else if(turn==1){
            logicx(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            if(temp==1){
                turn=0;tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc_o_x(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        //O
        else{
            logico(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            if(temp==1){
                turn=0;tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc_o_x(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        system("cls");
    }
}

//Castig Anti X O
void win_anti(int t[4][4],int sim,int turn,int&castig){
    if(t[2][2]==sim){
        if(t[1][1]==sim && t[3][3]==sim){castig=!sim;}
        if(t[1][3]==sim && t[3][1]==sim){castig=!sim;}
        if(t[1][2]==sim && t[3][2]==sim){castig=!sim;}
        if(t[2][1]==sim && t[2][3]==sim){castig=!sim;}
    }
    if(t[1][1]==sim){
        if(t[1][2]==sim && t[1][3]==sim){castig=!sim;}
        if(t[2][1]==sim && t[3][1]==sim){castig=!sim;}
    }
    if(t[3][3]==sim){
        if(t[1][3]==sim && t[2][3]==sim){castig=!sim;}
        if(t[3][1]==sim && t[3][2]==sim){castig=!sim;}
    }
}

///Anti X si O
void joc_anti_xo(int t[4][4],int&tries,int&it,int&jt,int&turn,int&castig,int&poz,int&wx,int&wo,int&temp){
    start(t);
    while(true){
        //Egalitate
        if(tries==9){
            egal(castig,wx,wo,temp);
            if(temp==1){
                turn=1;tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc_anti_xo(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        //X
        else if(turn==1){
            draw(t);
            cout<<"X,Introduceti pozitia:";
            cin>>poz;
            checkex(poz,it,jt);
            checkoc(t,it,jt,poz);
            intro(turn,it,jt,t);
            win_anti(t,1,turn,castig);
            winx(castig,wx,wo,temp);
            wino(castig,wx,wo,temp);
            if(temp==1){
                turn=1;tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc_anti_xo(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        //O
        else{
            draw(t);
            cout<<"O,Introduceti pozitia:";
            cin>>poz;
            checkex(poz,it,jt);
            checkoc(t,it,jt,poz);
            intro(turn,it,jt,t);
            win_anti(t,0,turn,castig);
            wino(castig,wx,wo,temp);
            winx(castig,wx,wo,temp);
            if(temp==1){
                turn=1;tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc_anti_xo(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        system("cls");
    }
}

///Tura Intamplatoare
void joc_rand(int t[4][4],int&tries,int&it,int&jt,int&turn,int&castig,int&poz,int&wx,int&wo,int&temp){
    start(t);
    srand(time(NULL));
    while(true){
        //Egalitate
        if(tries==9){
            egal(castig,wx,wo,temp);
            if(temp==1){
                turn=rand()%10+1;turn=turn<=5?1:0;
                tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc_rand(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        //X
        else if(turn==1){
            draw(t);
            cout<<"X,Introduceti pozitia:";
            cin>>poz;
            checkex(poz,it,jt);
            checkoc(t,it,jt,poz);
            intro(turn,it,jt,t);
            turn=rand()%10+1;turn=turn<=5?1:0;
            win(t,1,turn,castig);
            winx(castig,wx,wo,temp);
            if(temp==1){
                turn=rand()%10+1;turn=turn<=5?1:0;
                tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc_rand(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        //O
        else{
            draw(t);
            cout<<"O,Introduceti pozitia:";
            cin>>poz;
            checkex(poz,it,jt);
            checkoc(t,it,jt,poz);
            intro(turn,it,jt,t);
            turn=rand()%10+1;turn=turn<=5?1:0;
            win(t,0,turn,castig);
            wino(castig,wx,wo,temp);
            if(temp==1){
                turn=rand()%10+1;turn=turn<=5?1:0;
                tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc_rand(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        system("cls");
    }
}

//Deseneaza tabla pt Liniute
void draw_xx(int t[4][4]){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(t[i][j]==1){
                if(j==3){cout<<"X"<<endl;Sleep(100);}
                else{cout<<"X ";Sleep(50);}
            }
            else if(t[i][j]==0){
                if(j==3){cout<<"/"<<endl;Sleep(100);}
                else{cout<<"/ ";Sleep(50);}
            }
            else if(t[i][j]==-1){
                if(j==3){cout<<"-"<<endl;Sleep(100);}
                else{cout<<"- ";Sleep(50);}
            }
        }
        cout<<endl;
    }
}

//Verifica daca e ocupat pt Liniute
void checkoc_xx(int t[4][4],int&it,int&jt,int&poz){
    pozcalc(poz,it,jt);
    while(t[it][jt]==1){
        system("cls");
        cout<<"Pozitie ocupata"<<endl;Sleep(1500);
        system("cls");
        draw_xx(t);
        cout<<"Introduceti pozitia:";
        cin>>poz;
        pozcalc(poz,it,jt);
    }
}

//Introduce valori in tabla pt Liniute
void intro_xx(int&turn,int it,int jt,int t[4][4]){
    if(turn==1){
        if(t[it][jt]==-1){t[it][jt]=0;}
        else if(t[it][jt]==0){t[it][jt]=1;}
        turn=0;
        tries++;
    }
    else{
        if(t[it][jt]==-1){t[it][jt]=0;}
        else if(t[it][jt]==0){t[it][jt]=1;}
        turn=1;
        tries++;
    }
}

void winp(int&castig,int&wx,int&wo,int&temp,string p,int z){
    if(castig==z){
        system("cls");
        cout<<"Felicitari,"<<p<<"!Ati castigat!"<<endl<<endl;Sleep(2000);
        z==1?wx++:wo++;
        out<<"Scor:"<<wx<<"-"<<wo<<"(Castig "<<p<<")"<<endl;
        cout<<"Scor:"<<wx<<"-"<<wo<<endl<<endl;Sleep(500);
        cout<<"1.Revansa"<<endl<<endl;Sleep(100);
        cout<<"2.Iesire"<<endl<<endl;Sleep(100);
        cout<<"Introduceti optiunea:";
        cin>>temp;
        while(temp<1 || temp>2){
            system("cls");
            cout<<"Optiune incorecta";Sleep(2000);
            system("cls");
            cout<<"Scor:"<<wx<<"-"<<wo<<endl<<endl;Sleep(500);
            cout<<"1.Revansa"<<endl<<endl;Sleep(100);
            cout<<"2.Iesire"<<endl<<endl;Sleep(100);
            cout<<"Introduceti optiunea:";
            cin>>temp;

        }
        if(temp==2){
            system("cls");
            out<<"Scor final:"<<wx<<"-"<<wo<<"(J1-J2)"<<endl;
            cout<<"Scor final:"<<wx<<"-"<<wo<<endl;Sleep(2000);
            system("cls");
            cout<<"Multumesc pentru atentie!";Sleep(2000);
            exit(0);
        }
    }
}

///Liniute
void joc_xx_lin(int t[4][4],int&tries,int&it,int&jt,int&turn,int&castig,int&poz,int&wx,int&wo,int&temp){
    start(t);
    while(true){
        //Egalitate
        if(tries==18){
            egal(castig,wx,wo,temp);
            if(temp==1){
                turn=1;tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc_xx_lin(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        //J1
        else if(turn==1){
            draw_xx(t);
            cout<<"Jucator 1,Introduceti pozitia:";
            cin>>poz;
            checkex(poz,it,jt);
            checkoc_xx(t,it,jt,poz);
            intro_xx(turn,it,jt,t);
            win(t,1,turn,castig);
            winp(castig,wx,wo,temp,"Jucator 1",1);

            if(temp==1){
                turn=1;tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc_xx_lin(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        //J2
        else{
            draw_xx(t);
            cout<<"Jucator 2,Introduceti pozitia:";
            cin>>poz;
            checkex(poz,it,jt);
            checkoc_xx(t,it,jt,poz);
            intro_xx(turn,it,jt,t);
            win_anti(t,1,turn,castig);
            winp(castig,wx,wo,temp,"Jucator 2",0);
            if(temp==1){
                turn=1;tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc_xx_lin(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        system("cls");
    }
}


//Introduce date pt X si X
void intro_xx2(int&turn,int it,int jt,int t[4][4]){
    if(turn==1){
        t[it][jt]=1;
        turn=0;
        tries++;
    }
    else{
        t[it][jt]=1;
        turn=1;
        tries++;
    }
}

///X si X
void joc_xx(int t[4][4],int&tries,int&it,int&jt,int&turn,int&castig,int&poz,int&wx,int&wo,int&temp){
start(t);
    while(true){
        //Egalitate
        if(tries==18){
            egal(castig,wx,wo,temp);
            if(temp==1){
                turn=1;tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc_xx(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        //J1
        else if(turn==1){
            draw(t);
            cout<<"Jucator 1,Introduceti pozitia:";
            cin>>poz;
            checkex(poz,it,jt);
            checkoc(t,it,jt,poz);
            intro_xx2(turn,it,jt,t);
            win(t,1,turn,castig);
            winp(castig,wx,wo,temp,"Jucator 1",1);

            if(temp==1){
                turn=1;tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc_xx(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        //J2
        else{
            draw(t);
            cout<<"Jucator 2,Introduceti pozitia:";
            cin>>poz;
            checkex(poz,it,jt);
            checkoc(t,it,jt,poz);
            intro_xx2(turn,it,jt,t);
            win_anti(t,1,turn,castig);
            winp(castig,wx,wo,temp,"Jucator 2",0);
            if(temp==1){
                turn=1;tries=0;it=0;jt=0;castig=-2;poz=0;temp=-1;
                joc_xx(t,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
        }
        system("cls");
    }
}

///Meniu principal
void meniu(int&men,int&tries,int&it,int&jt,int&turn,int&castig,int&poz,int&wx,int&wo,int&temp){
    system("cls");
    cout<<"B";Sleep(100);
    cout<<"i";Sleep(100);
    cout<<"n";Sleep(100);
    cout<<"e";Sleep(100);
    cout<<" ";Sleep(100);
    cout<<"a";Sleep(100);
    cout<<"i";Sleep(100);
    cout<<" ";Sleep(100);
    cout<<"v";Sleep(100);
    cout<<"e";Sleep(100);
    cout<<"n";Sleep(100);
    cout<<"i";Sleep(100);
    cout<<"t";Sleep(1000);
    system("cls");
    while(true){
        cout<<"Meniu principal"<<endl<<endl;Sleep(1000);
        cout<<"1.Start joc"<<endl;Sleep(100);
        cout<<"2.Reguli"<<endl;Sleep(100);
        cout<<"3.Optiuni"<<endl<<endl;Sleep(100);
        cout<<"4.Iesire"<<endl<<endl;Sleep(500);
        cout<<"Introduceti optiunea:";
        cin>>men;

        while(men<1 || men>4){
            system("cls");
            cout<<"Optiune invalida"<<endl;Sleep(1000);
            system("cls");
            cout<<"Bine ai venit la X si O!"<<endl<<endl;Sleep(2000);
            cout<<"1.Start joc"<<endl;Sleep(100);
            cout<<"2.Reguli"<<endl;Sleep(100);
            cout<<"3.Optiuni"<<endl<<endl;Sleep(100);
            cout<<"4.Iesire"<<endl<<endl;Sleep(500);
            cout<<"Introduceti optiunea:";
            cin>>men;
        }
        if(men==1){
            int mod;
            system("cls");
            cout<<"Alegeti modul de joc:"<<endl<<endl;Sleep(1000);
            cout<<"1.X si O"<<endl;Sleep(100);
            cout<<"2.O si X"<<endl;Sleep(100);
            cout<<"3.Anti X si O"<<endl;Sleep(100);
            cout<<"4.Tura Intamplatoare"<<endl;Sleep(100);
            cout<<"5.Liniute"<<endl;Sleep(100);
            cout<<"6.X si X"<<endl<<endl;Sleep(500);
            cout<<"Introduceti optiunea:";
            cin>>mod;
            while(mod<1 || mod>6){
                system("cls");
                cout<<"Optiune invalida"<<endl;Sleep(1000);
                system("cls");
                cout<<"Alegeti modul de joc:"<<endl<<endl;Sleep(500);
                cout<<"1.X si O"<<endl;Sleep(100);
                cout<<"2.O si X"<<endl;Sleep(100);
                cout<<"3.Anti X si O"<<endl;Sleep(100);
                cout<<"4.Tura Intamplatoare"<<endl;Sleep(100);
                cout<<"5.Liniute"<<endl;Sleep(100);
                cout<<"6.X si X"<<endl<<endl;Sleep(500);
                cout<<"Introduceti optiunea:";
                cin>>mod;
            }
            if(mod==1){joc(t,tries,it,jt,turn,castig,poz,wx,wo,temp);}
            else if(mod==2){joc_o_x(t,tries,it,jt,turn,castig,poz,wx,wo,temp);}
            else if(mod==3){joc_anti_xo(t,tries,it,jt,turn,castig,poz,wx,wo,temp);}
            else if(mod==4){joc_rand(t,tries,it,jt,turn,castig,poz,wx,wo,temp);}
            else if(mod==5){joc_xx_lin(t,tries,it,jt,turn,castig,poz,wx,wo,temp);}
            else if(mod==6){joc_xx(t,tries,it,jt,turn,castig,poz,wx,wo,temp);}
        }
        else if(men==2){
            system("cls");
            cout<<"Reguli"<<endl<<endl;Sleep(500);
            cout<<"1.Reguli X si O clasic"<<endl;Sleep(100);
            cout<<"2.Reguli O si X clasic"<<endl;Sleep(100);
            cout<<"3.Reguli Anti X si O"<<endl;Sleep(100);
            cout<<"4.Reguli Tura Intamplatoare"<<endl;Sleep(100);
            cout<<"5.Reguli Liniute"<<endl;Sleep(100);
            cout<<"6.Reguli X si X"<<endl;Sleep(100);
            cout<<endl;
            cout<<"7.Revenire meniu principal"<<endl;Sleep(100);
            cout<<"8.Iesire"<<endl<<endl;Sleep(500);
            int reg;
            cout<<"Introduceti optiunea:";
            cin>>reg;
            while(reg<1 || reg>8){
                system("cls");
                cout<<"Optiune invalida";Sleep(1000);
                system("cls");
                cout<<"Reguli"<<endl<<endl;Sleep(500);
                cout<<"1.Reguli X si O clasic"<<endl;Sleep(100);
                cout<<"2.Reguli O si X clasic"<<endl;Sleep(100);
                cout<<"3.Reguli Anti X si O"<<endl;Sleep(100);
                cout<<"4.Reguli Tura Intamplatoare"<<endl;Sleep(100);
                cout<<"5.Reguli Liniute"<<endl;Sleep(100);
                cout<<"6.Reguli X si X"<<endl;Sleep(100);
                cout<<endl;
                cout<<"7.Revenire meniu principal"<<endl;Sleep(100);
                cout<<"8.Iesire"<<endl<<endl;Sleep(500);
                cout<<"Introduceti optiunea:";
                cin>>reg;
            }
            if(reg==1){
                system("cls");
                cout<<"X si O"<<endl<<endl;Sleep(500);
                cout<<"Scopul jocului e ca unul dintre jucatori sa faca 3 simboluri consecutive fie:"<<endl;Sleep(2000);
                cout<<"-orizontal"<<endl<<endl;Sleep(500);
                cout<<"X X X"<<endl;Sleep(100);
                cout<<"- - -"<<endl;Sleep(200);
                cout<<"- - -"<<endl<<endl;Sleep(100);
                cout<<"-vertical"<<endl<<endl;Sleep(500);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"X - -"<<endl<<endl;Sleep(100);
                cout<<"-diagonal"<<endl<<endl;Sleep(500);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"- X -"<<endl;Sleep(100);
                cout<<"- - X"<<endl<<endl;Sleep(100);
                cout<<"Totalitatea patratelor acoperite fara o formatie rezulta intr-o egalitate"<<endl;Sleep(2000);
                cout<<endl;
                cout<<"Notatia tablei:"<<endl;Sleep(1000);
                cout<<"1 2 3"<<endl;Sleep(100);
                cout<<"4 5 6"<<endl;Sleep(100);
                cout<<"7 8 9"<<endl;Sleep(500);
                cout<<endl;
                cout<<"X incepe primul"<<endl<<endl;Sleep(500);
                cout<<"Totalitatea rezultatelor sunt memorate in documentul rezultate.txt"<<endl;Sleep(3000);
                meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
            else if(reg==2){
                system("cls");
                cout<<"O si X"<<endl<<endl;Sleep(500);
                cout<<"Scopul jocului e ca unul dintre jucatori sa faca 3 simboluri consecutive fie:"<<endl;Sleep(2000);
                cout<<"-orizontal"<<endl<<endl;Sleep(500);
                cout<<"X X X"<<endl;Sleep(100);
                cout<<"- - -"<<endl;Sleep(100);
                cout<<"- - -"<<endl<<endl;Sleep(100);
                cout<<"-vertical"<<endl<<endl;Sleep(500);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"X - -"<<endl<<endl;Sleep(100);
                cout<<"-diagonal"<<endl<<endl;Sleep(500);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"- X -"<<endl;Sleep(100);
                cout<<"- - X"<<endl<<endl;Sleep(100);
                cout<<"Totalitatea patratelor acoperite fara o formatie rezulta intr-o egalitate"<<endl;Sleep(2000);
                cout<<endl;
                cout<<"Notatia tablei:"<<endl;Sleep(1000);
                cout<<"1 2 3"<<endl;Sleep(100);
                cout<<"4 5 6"<<endl;Sleep(100);
                cout<<"7 8 9"<<endl;Sleep(500);
                cout<<endl;
                cout<<"O incepe primul"<<endl<<endl;Sleep(500);
                cout<<"Totalitatea rezultatelor sunt memorate in documentul rezultate.txt"<<endl;Sleep(3000);
                meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
            else if(reg==3){
                system("cls");
                cout<<"Anti X si O"<<endl<<endl;Sleep(500);
                cout<<"Scopul jocului e ca unul dintre jucatori sa nu faca 3 simboluri consecutive fie:"<<endl;Sleep(2000);
                cout<<"-orizontal"<<endl<<endl;Sleep(500);
                cout<<"X X X"<<endl;Sleep(100);
                cout<<"- - -"<<endl;Sleep(100);
                cout<<"- - -"<<endl<<endl;Sleep(100);
                cout<<"-vertical"<<endl<<endl;Sleep(500);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"X - -"<<endl<<endl;Sleep(100);
                cout<<"-diagonal"<<endl<<endl;Sleep(500);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"- X -"<<endl;Sleep(100);
                cout<<"- - X"<<endl<<endl;Sleep(100);
                cout<<"Totalitatea patratelor acoperite fara o formatie rezulta intr-o egalitate"<<endl;Sleep(2000);
                cout<<endl;
                cout<<"Notatia tablei:"<<endl;Sleep(1000);
                cout<<"1 2 3"<<endl;Sleep(100);
                cout<<"4 5 6"<<endl;Sleep(100);
                cout<<"7 8 9"<<endl;Sleep(500);
                cout<<endl;
                cout<<"X incepe primul"<<endl<<endl;Sleep(500);
                cout<<"Totalitatea rezultatelor sunt memorate in documentul rezultate.txt"<<endl;Sleep(3000);
                meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
            else if(reg==4){
                system("cls");
                cout<<"Tura Intamplatoare"<<endl<<endl;Sleep(500);
                cout<<"Scopul jocului e ca unul dintre jucatori sa faca 3 simboluri consecutive fie:"<<endl;Sleep(2000);
                cout<<"-orizontal"<<endl<<endl;Sleep(500);
                cout<<"X X X"<<endl;Sleep(100);
                cout<<"- - -"<<endl;Sleep(100);
                cout<<"- - -"<<endl<<endl;Sleep(100);
                cout<<"-vertical"<<endl<<endl;Sleep(500);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"X - -"<<endl<<endl;Sleep(100);
                cout<<"-diagonal"<<endl<<endl;Sleep(500);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"- X -"<<endl;Sleep(100);
                cout<<"- - X"<<endl<<endl;Sleep(100);
                cout<<"Totalitatea patratelor acoperite fara o formatie rezulta intr-o egalitate"<<endl;Sleep(2000);
                cout<<endl;
                cout<<"Notatia tablei:"<<endl;Sleep(1000);
                cout<<"1 2 3"<<endl;Sleep(100);
                cout<<"4 5 6"<<endl;Sleep(100);
                cout<<"7 8 9"<<endl;Sleep(500);
                cout<<endl;
                cout<<"Randul fiecarui jucator este aleatoriu"<<endl<<endl;Sleep(1500);
                cout<<"Totalitatea rezultatelor sunt memorate in documentul rezultate.txt"<<endl;Sleep(3000);
                meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
            else if(reg==5){
                system("cls");
                cout<<"Liniute"<<endl<<endl;Sleep(500);
                cout<<"Scopul jocului e ca unul dintre jucatori sa nu faca 3 simboluri consecutive fie:"<<endl;Sleep(2000);
                cout<<"-orizontal"<<endl<<endl;Sleep(500);
                cout<<"X X X"<<endl;Sleep(100);
                cout<<"- - -"<<endl;Sleep(100);
                cout<<"- - -"<<endl<<endl;Sleep(100);
                cout<<"-vertical"<<endl<<endl;Sleep(500);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"X - -"<<endl<<endl;Sleep(100);
                cout<<"-diagonal"<<endl<<endl;Sleep(500);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"- X -"<<endl;Sleep(100);
                cout<<"- - X"<<endl<<endl;Sleep(100);
                cout<<"Totalitatea patratelor acoperite fara o formatie rezulta intr-o egalitate"<<endl;Sleep(2000);
                cout<<endl;
                cout<<"Notatia tablei:"<<endl;Sleep(1000);
                cout<<"1 2 3"<<endl;Sleep(100);
                cout<<"4 5 6"<<endl;Sleep(100);
                cout<<"7 8 9"<<endl;Sleep(500);
                cout<<endl;
                cout<<"Juctor 1 incepe primul"<<endl<<endl;Sleep(500);
                cout<<"Totalitatea rezultatelor sunt memorate in documentul rezultate.txt"<<endl;Sleep(3000);
                meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
            else if(reg==6){
                system("cls");
                cout<<"X si X"<<endl<<endl;Sleep(500);
                cout<<"Scopul jocului e ca unul dintre jucatori sa nu faca 3 simboluri consecutive fie:"<<endl;Sleep(2000);
                cout<<"-orizontal"<<endl<<endl;Sleep(500);
                cout<<"X X X"<<endl;Sleep(100);
                cout<<"- - -"<<endl;Sleep(100);
                cout<<"- - -"<<endl<<endl;Sleep(100);
                cout<<"-vertical"<<endl<<endl;Sleep(500);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"X - -"<<endl<<endl;Sleep(100);
                cout<<"-diagonal"<<endl<<endl;Sleep(500);
                cout<<"X - -"<<endl;Sleep(100);
                cout<<"- X -"<<endl;Sleep(100);
                cout<<"- - X"<<endl<<endl;Sleep(100);
                cout<<"Totalitatea patratelor acoperite fara o formatie rezulta intr-o egalitate"<<endl;Sleep(2000);
                cout<<endl;
                cout<<"Notatia tablei:"<<endl;Sleep(1000);
                cout<<"1 2 3"<<endl;Sleep(100);
                cout<<"4 5 6"<<endl;Sleep(100);
                cout<<"7 8 9"<<endl;Sleep(500);
                cout<<endl;
                cout<<"Juctor 1 incepe primul"<<endl<<endl;Sleep(500);
                cout<<"Totalitatea rezultatelor sunt memorate in documentul rezultate.txt"<<endl;Sleep(3000);
                meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
            else if(reg==7){
                system("cls");
                meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
            else if(reg==8){
                system("cls");
                cout<<"Multumesc pentru atentie!";Sleep(2500);
                exit(0);
            }
        }
        else if(men==3){
            system("cls");
            cout<<"Optiuni"<<endl<<endl;Sleep(500);
            cout<<"1.Culoare"<<endl<<endl;Sleep(100);
            cout<<"2.Revenire meniu principal"<<endl;Sleep(100);
            cout<<"3.Iesire"<<endl<<endl;Sleep(500);
            cout<<"Introduceti optiunea:";
            int opt;
            cin>>opt;
            while(opt<1 || opt>2){
                system("cls");
                cout<<"Optiune invalida";Sleep(1000);
                system("cls");
                cout<<"Optiuni"<<endl<<endl;Sleep(500);
                cout<<"1.Culoare"<<endl<<endl;Sleep(100);
                cout<<"2.Revenire meniu principal"<<endl;Sleep(100);
                cout<<"3.Iesire"<<endl;Sleep(500);
                cout<<"Introduceti optiunea:";
                cin>>opt;
            }
            if(opt==1){
                system("cls");
                cout<<"Pentru a va schimba culoarea textului introduceti una din urmatoarele valori:"<<endl<<endl;Sleep(2000);
                cout<<"1.Albastru"<<endl;Sleep(100);
                cout<<"2.Verde"<<endl;Sleep(100);
                cout<<"3.Aqua"<<endl;Sleep(100);
                cout<<"4.Rosu"<<endl;Sleep(100);
                cout<<"5.Mov"<<endl;Sleep(100);
                cout<<"6.Galben"<<endl;Sleep(100);
                cout<<"7.Alb"<<endl;Sleep(100);
                cout<<"8.Gri"<<endl;Sleep(100);
                cout<<"9.Albastru deschis"<<endl;Sleep(100);
                cout<<"10.Verde deschis"<<endl;Sleep(100);
                cout<<"11.Aqua deschis"<<endl;Sleep(100);
                cout<<"12.Rosu deschis"<<endl;Sleep(100);
                cout<<"13.Mov deschis"<<endl;Sleep(100);
                cout<<"14.Galben deschis"<<endl;Sleep(100);
                cout<<"15.Alb deschis"<<endl<<endl;Sleep(500);
                int col;
                cout<<"Introduceti optiunea:";
                cin>>col;
                while(col<1 || col>16){
                    system("cls");
                    cout<<"Optiune invalida";Sleep(2000);
                    system("cls");
                    cout<<"Pentru a va schimba culoarea textului introduceti una din urmatoarele valori:"<<endl<<endl;Sleep(2000);
                    cout<<"1.Albastru"<<endl;Sleep(100);
                    cout<<"2.Verde"<<endl;Sleep(100);
                    cout<<"3.Aqua"<<endl;Sleep(100);
                    cout<<"4.Rosu"<<endl;Sleep(100);
                    cout<<"5.Mov"<<endl;Sleep(100);
                    cout<<"6.Galben"<<endl;Sleep(100);
                    cout<<"7.Alb"<<endl;Sleep(100);
                    cout<<"8.Gri"<<endl;Sleep(100);
                    cout<<"9.Albastru deschis"<<endl;Sleep(100);
                    cout<<"10.Verde deschis"<<endl;Sleep(100);
                    cout<<"11.Aqua deschis"<<endl;Sleep(100);
                    cout<<"12.Rosu deschis"<<endl;Sleep(100);
                    cout<<"13.Mov deschis"<<endl;Sleep(100);
                    cout<<"14.Galben deschis"<<endl;Sleep(100);
                    cout<<"15.Alb deschis"<<endl<<endl;Sleep(500);
                    cout<<"Introduceti optiunea:";
                    cin>>col;
                }
                switch (col){
                    case 1:system("cls");system("color 01");meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);break;
                    case 2:system("cls");system("color 02");meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);break;
                    case 3:system("cls");system("color 03");meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);break;
                    case 4:system("cls");system("color 04");meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);break;
                    case 5:system("cls");system("color 05");meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);break;
                    case 6:system("cls");system("color 06");meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);break;
                    case 7:system("cls");system("color 07");meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);break;
                    case 8:system("cls");system("color 08");meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);break;
                    case 9:system("cls");system("color 09");meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);break;
                    case 10:system("cls");system("color 0a");meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);break;
                    case 11:system("cls");system("color 0b");meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);break;
                    case 12:system("cls");system("color 0c");meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);break;
                    case 13:system("cls");system("color 0d");meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);break;
                    case 14:system("cls");system("color 0e");meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);break;
                    case 15:system("cls");system("color 0f");meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);break;
                }

            }

            else if(opt==2){
                system("cls");
                meniu(men,tries,it,jt,turn,castig,poz,wx,wo,temp);
            }
            else if(opt==3){
                system("cls");
                cout<<"Multumesc pentru atentie!";Sleep(2500);
                exit(0);
            }
        }
        else if(men==4){
            system("cls");
            cout<<"Multumesc pentru atentie!";Sleep(2500);
            exit(0);
        }

    }
}
