#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;





//                                   AICI INCEP PIESELE NECESARE PENTRU REPARATII

// AVEM O CLASA TATA NUMITA Piesa IN CARE E CONSTRUIT COSTUL LUCRARII CU FIECARE PIESA IN SURUBURI, BANI SI ORE DE MUNCA



class Piesa
{   int suruburi;
    int cost;
    int minute;
    string nume="Piesa";
public:
    string get_nume(){ return nume; };
    void set_nume(string s){ nume = s; };
    void set_suruburi(int x){suruburi = x;};
    void set_cost(int x){ cost = x;};
    void set_minute(int x){ minute = x;};
    int get_suruburi(){ return suruburi; };
    int get_cost(){return cost; };
    int get_minute(){return minute; };
};

        //In fiecare constructor de piesa vom apela constructorul facut pentru clasa Piesa. In plus, sunt setate costurile de suruburi, ore si bani
        //si se seteaza numele piesei respective.

class PlacutaFrana: public Piesa
{ public:
    PlacutaFrana(): Piesa(){set_nume("Placuta Frana"); set_suruburi(6); set_cost(200); set_minute (30);};
};

class DiscFrana: public Piesa
{ public:
    DiscFrana(): Piesa(){set_nume("Disc Frana"); set_suruburi(8); set_cost(300); set_minute (50);};
};

class LantNou: public Piesa
{ public:
    LantNou(): Piesa(){set_nume("Lant Nou"); set_suruburi(5); set_cost(40); set_minute (10);};
};

class LantReparat: public Piesa
{ public:
    LantReparat(): Piesa(){set_nume("Lant Reparat"); set_suruburi(8); set_cost(30); set_minute (20);};
};

class UleiMotor: public Piesa
{ public:
    UleiMotor(): Piesa(){set_nume("Ulei de Motor"); set_suruburi(5); set_cost(80); set_minute (5);};
};

class Carburator: public Piesa
{ public:
    Carburator(): Piesa(){set_nume("Carburator"); set_suruburi(26); set_cost(500); set_minute (90);};
};

class BlocMotor: public Piesa
{ public:
    BlocMotor(): Piesa(){set_nume("Bloc Motor"); set_suruburi(100); set_cost(1200); set_minute (150);};
};

class Garnituri: public Piesa
{ public:
    Garnituri(): Piesa(){set_nume("Garnituri Motor"); set_suruburi(5); set_cost(30); set_minute (15);};
};

class Pistoane: public Piesa
{ public:
    Pistoane(): Piesa(){set_nume("Pistoane"); set_suruburi(25); set_cost(250); set_minute (30);};
};

class Ghidon: public Piesa
{ public:
    Ghidon(): Piesa(){set_nume("Ghidon"); set_suruburi(20); set_cost(250); set_minute (25);};
};

class Roata: public Piesa
{ public:
    Roata(): Piesa(){set_nume("Roata"); set_suruburi(8); set_cost(200); set_minute (8);};
};

class Chiuloasa: public Piesa
{ public:
    Chiuloasa(): Piesa(){set_nume("Chiuloasa"); set_suruburi(15); set_cost(600); set_minute (80);};
};

class Curatare: public Piesa
{ public:
    Curatare(): Piesa(){set_nume("Curatare"); set_suruburi(10); set_cost(80); set_minute (45);};
};

class Aripa: public Piesa
{ public:
    Aripa(): Piesa(){set_nume("Aripa"); set_suruburi(20); set_cost(120); set_minute (25);};
};

class Bara: public Piesa
{ public:
    Bara(): Piesa(){set_nume("Bara"); set_suruburi(20); set_cost(280); set_minute (25);};
};

class Capota: public Piesa
{ public:
    Capota(): Piesa(){set_nume("Capota"); set_suruburi(40); set_cost(600); set_minute (40);};
};

class Chit: public Piesa
{ public:
    Chit(): Piesa(){set_nume("Chit pentru Rugina"); set_suruburi(5); set_cost(300); set_minute (170);};
};





//                                          AICI INCEP PROBLEMELE SAU AVARIILE

//Avem o clasa problema ai carei clase mostenitoare vor fi problemel posibile ale unui vehicul.
//Fiecare problema va avea o lista de piese necesare pentru a fi rezolvata
//Problemele au o valoare numita activa, care este 0 by default. Aceasta variabila prezinta starea problemei.
//Daca activ va fi diferit de 0, va insemna ca partea masinii ce poate avea aceasta problema va fi avariata

class Problema
{
    int activ = 0;
    string avr = "Avarie";
    int len = 0;
    Piesa piesenecesare[3];
public:
    int get_activ(){return activ;};
    string get_avr(){return avr;};
    void set_activ(int x){activ = x;};
    void set_avr(string s){avr = s;};
    int getRandom();
    void set_len(int x){ len = x; };
    int get_len(){ return len; };

    void set_piesenecesare(Piesa *x, int n);
    Piesa * get_piesenecesare(){return piesenecesare;};
};

void Problema::set_piesenecesare(Piesa *x, int n)
{
    {
    int i;
    for(i=0;i<n;i++)
        piesenecesare[i]=x[i];
}
}

//Cand construim fiecare problema, se va apela constructorul pentru clasa piesa, cu adaosul adaugarii unei liste concrete de piese necesare,
// a unui nume al problemei si a marimii listei de piese necesare.
//Pentru defectiunea capitala nu vom schimba decat numele acesteia, astfel incat sa putem identifica daca vehiculul este in imposibilitate de reparatie.

class Capitala : public Problema
{
public:
    Capitala() : Problema(){set_avr("Defectiunea capitala -  vehiculul nu poate fi reparat");};
};

class PlacutaUzata : public Problema
{   PlacutaFrana p;
    Piesa piese[1] = {p};
public:
    Piesa * get_piese(){return piese;};
    PlacutaUzata() : Problema() {set_len(1); set_piesenecesare(get_piese(), 1); set_avr("Placuta de frana este tocita"); };
};


class DiscUzat : public Problema
{   DiscFrana d;
    Piesa piese[1] = {d};
public:
    Piesa * get_piese(){return piese;};
    DiscUzat() : Problema() {set_len(1); set_piesenecesare(get_piese(),1); set_avr("Disc de frana uzat"); };
};

class LantTocit : public Problema
{   LantReparat d;
    Piesa piese[1] = {d};
public:
    Piesa * get_piese(){return piese;};
    LantTocit() : Problema() {set_len(1); set_piesenecesare(get_piese(),1); set_avr("Lant tocit"); };
};

class LantLipsa : public Problema
{   LantNou d;
    Piesa piese[1] = {d};
public:
    Piesa * get_piese(){return piese;};
    LantLipsa() : Problema() {set_len(1); set_piesenecesare(get_piese(),1); set_avr("Lant lipsa"); };
};

class NivelUleiScazut : public Problema
{   UleiMotor d;
    Piesa piese[1] = {d};
public:
    Piesa * get_piese(){return piese;};
    NivelUleiScazut() : Problema() {set_len(1); set_piesenecesare(get_piese(),1); set_avr("Nivelul de ulei este scazut"); };
};

class CarburatorMurdar : public Problema
{   Carburator d;
    Piesa piese[1] = {d};
public:
    Piesa * get_piese(){return piese;};
    CarburatorMurdar() : Problema() {set_len(1); set_piesenecesare(get_piese(),1);set_avr("Carburatorul este murdar."); };
};

class MotorTopit : public Problema
{
    UleiMotor u;
    BlocMotor b;
    Garnituri g;
    Pistoane p;
    Piesa piese[4] = {b,g,p,u};
public:
    Piesa * get_piese(){return piese;};
    MotorTopit() : Problema() {set_len(4); set_piesenecesare(get_piese(),4); set_avr("Motorul este topit"); };
};

class GhidonStramb : public Problema
{   Ghidon d;
    Piesa piese[1] = {d};
public:
    Piesa * get_piese(){return piese;};
    GhidonStramb() : Problema() {set_len(1); set_piesenecesare(get_piese(),1); set_avr("Ghidonul este stramb"); };
};

class RoataStramba : public Problema
{   Roata d;
    Piesa piese[1] = {d};
public:
    Piesa * get_piese(){return piese;};
    RoataStramba() : Problema() {set_len(1); set_piesenecesare(get_piese(),1); set_avr("Roata este stramba"); };
};

class ArdeUlei : public Problema
{   Chiuloasa d;
    UleiMotor u;
    Piesa piese[2] = {d , u};
public:
    Piesa * get_piese(){return piese;};
    ArdeUlei() : Problema() {set_len(2); set_piesenecesare(get_piese(),2);set_avr("Vehiculul are ulei"); };
};

class Pre2000 : public Problema
{   Curatare d;
    Piesa piese[1] = {d};
public:
    Piesa * get_piese(){return piese;};
    Pre2000() : Problema() {set_len(1); set_piesenecesare(get_piese(),1); set_avr("Vehiculul a fost fabricat pana in anul 2000"); };
};

class Coroziune : public Problema
{   Chit d;
    Piesa piese[1] = {d};
public:
    Piesa * get_piese(){return piese;};
    Coroziune() : Problema() {set_len(1); set_piesenecesare(get_piese(),1);set_avr("Vehiculul prezinta coroziuni de rugina"); };
};

class AripaStramba : public Problema
{   Aripa d;
    Piesa piese[1] = {d};
public:
    Piesa * get_piese(){return piese;};
    AripaStramba() : Problema() {set_len(1); set_piesenecesare(get_piese(),1); set_avr("Aripa este stramba"); };
};

class BaraStramba : public Problema
{   Bara d;
    Piesa piese[1] = {d};
public:
    Piesa * get_piese(){return piese;};
    BaraStramba() : Problema() {set_len(1); set_piesenecesare(get_piese(),1); set_avr("Bara este stramba");};
};

class CapotaStramba : public Problema
{   Capota d;
    Piesa piese[1] = {d};
public:
    Piesa * get_piese(){return piese;};
    CapotaStramba() : Problema() {set_len(1); set_piesenecesare(get_piese(),1); set_avr("Capota este stramba"); };
};









//                                              AICI INCEP VEHICULELE

//Fiecare vehicul are o lista de probleme posibile per parte a masinii, ce vor fi cuplate cu numele partii respective a masinii

class Vehicul
{  string name = "Vehicul";
    int len = 0;
    Problema posibile[26];
    string carpart[26];
public:
    void diagnostic(){ cout<<"Vehiculul nu are avarii"; };
    void set_name(string s) { name = s; };
    string get_name(){return name;};
    void set_len(int x){ len = x;};
    int get_len(){return len;};
    Problema * get_avarii(){return posibile;};
    void set_avarii(Problema *x, int n);
    void set_carpart(string * x, int n);
    string * get_carpart(){return carpart; };
};

void Vehicul::set_avarii(Problema *x, int n)
{
     int i;
        for(i=0;i<n;i++)
            posibile[i]=x[i];
}

void Vehicul::set_carpart(string * x, int n)
{
    int i;
    for(i=0;i<n;i++)
            carpart[i]=x[i];
}

//Cele 3 vehicule isi seteaza mai jos piesele acestora.

class Motocicleta:public Vehicul
{   PlacutaUzata placutafata;
    PlacutaUzata placutaspate;
    DiscUzat discfata;
    DiscUzat discspate;
    NivelUleiScazut uleiscazut;
    MotorTopit motor;
    GhidonStramb ghidon;
    RoataStramba roatafata;
    RoataStramba roataspate;
    ArdeUlei ardere;
    Pre2000 anterior2000;
    Capitala capital;

    Problema posibil[12] = {placutafata , placutaspate, discfata, discspate, uleiscazut, motor, ghidon, roatafata, roataspate, ardere, anterior2000, capital};
    string partimoto[12] = {"Placuta de frana fata" , "Placuta frana spate" , "Disc frana fata" , "Disc fana spate" , "Nivelul de ulei" , "Motor"
                            , "Ghidon" , "Roata fata" , "Roata spate" , "Ardere ulei" ,
                            "Motocicleta a fost fabricata pana in 2000" , "Defectiune capitala - Motocicleta nu va putea fi reparata"};


public:
    Motocicleta():Vehicul(){set_name("Motocicleta"); set_len(12); set_avarii(get_posibil(),12); set_carpart(partimoto, 12); };
    Problema * get_posibil(){return posibil;};

};




class Bicicleta:public Vehicul
{
    LantTocit tocit;
    LantLipsa lipsa;
    GhidonStramb ghidon;
    RoataStramba roatafata;
    RoataStramba roataspate;
    Capitala capital;
    Problema posibil[6] = {tocit, lipsa, ghidon, roatafata, roataspate, capital};
    string piesebicicleta[6] = {"Lant - tocit" , "Lantul - lipsa" , "Ghidonul" , "Roata fata" , "Roata spate"
                                , "Defectiunea capitala - bicicleta nu va putea fi reparata"};

public:
    Bicicleta():Vehicul(){set_name("Bicicleta"); set_len(6); set_avarii(get_posibil(),6); set_carpart(piesebicicleta, 6); };
    Problema * get_posibil(){return posibil;};
};


class Autovehicul:public Vehicul
{
    PlacutaUzata placutastangafata;
    PlacutaUzata placutadreaptafata;
    PlacutaUzata placutastangaspate;
    PlacutaUzata placutadreaptaspate;
    DiscUzat discstangafata;
    DiscUzat discstangaspate;
    DiscUzat discdreaptaspate;
    DiscUzat discdreaptafata;
    NivelUleiScazut ulei;
    CarburatorMurdar carb;
    MotorTopit motor;
    RoataStramba roatastangafata;
    RoataStramba roatastangaspate;
    RoataStramba roatadreaptafata;
    RoataStramba roatadreaptaspate;
    ArdeUlei arde;
    Pre2000 pana2000;
    Coroziune rugina;
    AripaStramba aripastangafata;
    AripaStramba aripastangaspate;
    AripaStramba aripadreaptafata;
    AripaStramba aripadreaptaspate;
    BaraStramba barafata;
    BaraStramba baraspate;
    CapotaStramba capota;
    Capitala capital;

    Problema posibil[26] = {placutastangafata , placutadreaptafata, placutastangaspate, placutadreaptaspate, discstangafata
                            , discstangaspate, discdreaptaspate, discdreaptafata, ulei, carb, motor, roatastangafata, roatastangaspate
                            , roatadreaptafata, roatadreaptaspate, arde, pana2000, rugina, aripastangafata, aripastangaspate
                            , aripadreaptafata, aripadreaptaspate, barafata, baraspate, capota , capital};
    string partimasina[26] = {"Placuta de frana stanga fata" , "Placuta de frana dreapta fata" , "Placuta de frana stanga spate" , "Placuta de frana dreapta spate"
                            , "Disc de frana stanga fata" , "Disc de frana stanga spate" , "Disc de frana dreapta spate" , "Disc de frana dreapta fata"
                            , "Uleiul de motor" , "Carburator" , "Motor" , "Roata stanga fata"
                            , "Roata stanga spate" , "Roata dreapta fata" , "Roata dreapta spate", "Ardere ulei"
                            , "Vehiculul este fabricat pana in 2000" , "Caroserie - Rugina" , "Aripa stanga fata"
                            , "Aripa stanga spate", "Aripa dreapta fata" , "Aripa dreapta spate", "Bara fata" , "Bara spate" , "Capota" , "Defectiuena capitala - Autovehiculul nu va putea fi reparat"};

public:
    Autovehicul():Vehicul(){set_name("Autovehicul"); set_len(26); set_avarii(get_posibil(),26); set_carpart(partimasina, 26);};
    Problema * get_posibil(){return posibil;};
};



//Aici incep functiile de traumatizare si diagnosticare a masinii

void deviz(Vehicul m)
{
    int i,j,tsuruburi = 0, tbani = 0, tore = 0;
    cout<<"                              Deviz";
    cout<<endl<<"Vehiculul este: ";
    cout<<m.get_name()<<endl<<endl;
    Problema p;
    if(m.get_avarii()[m.get_len()-1].get_activ() != 0)
    cout<<"Vehiculul are avaria capitala - nu poate fi reparat.";
    else
    {
    cout<<"Problemele acestui vehicul sunt: "<<endl<<endl;
    for (i=0;i<m.get_len();i++)
        {   if(m.get_avarii()[i].get_activ() != 0)
            {
                cout<<m.get_carpart()[i]<<endl;
                cout<<m.get_avarii()[i].get_avr()<<endl;
                cout<<"   "<<"Problema are nevoie de urmatoarele pentru a fi rezolvata: "<<endl;
                p=m.get_avarii()[i];
                for (j=0;j<p.get_len();j++)
                {
                    cout<<"   "<<p.get_piesenecesare()[j].get_nume()<<endl;
                    cout<<"   "<<p.get_piesenecesare()[j].get_cost()<<" Lei"<<endl;
                    cout<<"   "<<p.get_piesenecesare()[j].get_minute()<<" Minute"<<endl;
                    cout<<"   "<<p.get_piesenecesare()[j].get_suruburi()<<" Suruburi"<<endl;

                    tore += p.get_piesenecesare()[j].get_minute();
                    tbani += p.get_piesenecesare()[j].get_cost();
                    tsuruburi += p.get_piesenecesare()[j].get_suruburi();
                }
                cout<<endl;
            }
        }
        if (tbani == 0)
            cout<<"Vehiculul nu prezinta avarii.";
        else
        {
            cout<<endl<<"Pentru ca vehiculul sa fie reparat, vor fi nevoie de urmatoarele:"<<endl;
            cout<<tsuruburi<<" suruburi"<<endl;
            cout<<tbani<<" Lei"<<endl;
            cout<<tore/60<<" ore si "<<tore%60<<" minute.";
        }

    }
}



void traumatizare(Vehicul &V)
{
    int i,j;
    for (i=0;i<V.get_len();i++)
    { j = 2;
        cout<<V.get_carpart()[i]<<endl;
        if(V.get_avarii()[i].get_activ() == 0)
            cout<<"Nu prezinta avarii.   ";
        else
            cout<<"Prezinta avarii   ";
        cout<<"Doriti sa schimbati starea acestei parti? 1 - DA; 0 - NU";
        while (j < 0 || j > 1)
        {
            cin>>j;
        }
        if (j == 1)
            V.get_avarii()[i].set_activ( (V.get_avarii()[i].get_activ() + 1) % 2 );
    }
}


//Declarati un vehicul (Bicicleta, Motocicleta, Autovehicul) in main
//Treceti-l printr-un proces de traumatizare pentru a avea avarii (apelati traumatizare(vehicul))
//Conectati-l la tester pentru a primi un deviz de reparatii (apelati deviz(vehicul))
int main()
{   Bicicleta b;
    traumatizare(b);
    deviz(b);
}
