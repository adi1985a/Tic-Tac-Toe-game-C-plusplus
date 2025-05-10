//---------------------------------------------------------------------------
// Gra kolko i krzyzyk , bedziemy potrzebowac grafiki ktore dodamy do sciezki programu do folderu img
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
//zmienne do gry:
// - stan kazdego z 9 pol, czy jest w nim pusto,krzyk czy kolko, czy te same znaki znajduja sie w linii,
// tworzymy 9 zmiennych typu char :

char p1,p2,p3,p4,p5,p6,p7,p8,p9;
//p1...p9 pola w grze (ich zawartosc: p1='n'(nic) lub 'x' lub 'o' )

char kto; //czyja jest teraz tura ('x' lub 'o')

//do sprawdzania przy kazdej turze czy gra sie juz nie zakonczyla potrzebujemy stworzyc wlasna procedure
void sprawdz()
 {    //wygrana (3 x lub o w rzedzie) jest mozliwa w 8 kombinacjach
 // Wygrana jest jak pole p1(lub inna kombinacja wygranej) jest takie same jak p2 i p3 (rzad x lub o)
 //dodatkowy warunek to ze nie sa one puste , nie zawieraja 'n' w sobie
 if((p1==p2 && p2==p3 && p1!='n') ||
    (p4==p5 && p5==p6 && p4!='n') ||
    (p7==p8 && p8==p9 && p7!='n') ||
    (p1==p4 && p4==p7 && p1!='n') ||
    (p2==p5 && p5==p8 && p2!='n') ||
    (p3==p6 && p6==p9 && p3!='n') ||
    (p1==p5 && p5==p9 && p1!='n') ||
    (p3==p5 && p5==p7 && p3!='n'))
    {
        //jesli gra sie skonczyla bo jakis z powyzszych warunkow zostal spelniony to pokazemy messageboxa ( tekst z info kto wygral )
        // do tego potrzebujemy zmiennej char * w;

        char * w;

        //Jesli na koncu gry zdarzy sie tak ze program podmieni info Tura gracza w ostatniej turze na x znaczy to ze ostatni ruch nalezal do o czyli wygrywa kolko 
        //w przeciwnym wypadku wygrywa krzyzyk

        if  (kto=='x') w="The circle wins!" ;
        else w="The cross wins!";

        //Zeby wyswietlic wiadomosc z w teraz musimy stworzyc messageboxa :
        Application->MessageBox(w, "Game over", MB_OK);
        //w to wiadomosc kto wygral, tekst , MB_OK - to okienko potwierdzenia z wiadomoscia "ok" do odklikniecia 


    }

 }

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//funkcja on create ( przy stworzeniu)
// tego zdarzenia uzyjemy do wczytania grafik do tych 9 pol z grafika
//
void __fastcall TForm1::FormCreate(TObject *Sender)
{
Pole1->Picture->LoadFromFile("img/nic.bmp");
Pole2->Picture->LoadFromFile("img/nic.bmp");
Pole3->Picture->LoadFromFile("img/nic.bmp");
Pole4->Picture->LoadFromFile("img/nic.bmp");
Pole5->Picture->LoadFromFile("img/nic.bmp");
Pole6->Picture->LoadFromFile("img/nic.bmp");
Pole7->Picture->LoadFromFile("img/nic.bmp");
Pole8->Picture->LoadFromFile("img/nic.bmp");
Pole9->Picture->LoadFromFile("img/nic.bmp");

//teraz grafika do Tura gracza
tura->Picture->LoadFromFile("img/osmall.bmp");

//przypisujemy polom puste miejsca ('n'-nic):
p1='n'; p2='n'; p3='n';
p4='n'; p5='n'; p6='n';
p7='n'; p8='n'; p9='n';

kto='o'; // bo na poczatku zaczyna kolko

//zeby gra mogla sie zresetowac poprzez klikniecie na przycisk(od nowa)
//musimy zmienic ustawienia Enabled na prawda , zeby moc ponownie na nie kliknac zostawiajac x lub o
Pole1->Enabled=true;
Pole2->Enabled=true;
Pole3->Enabled=true;
Pole4->Enabled=true;
Pole5->Enabled=true;
Pole6->Enabled=true;
Pole7->Enabled=true;
Pole8->Enabled=true;
Pole9->Enabled=true;

//ostatim zadaniem jest zmiana w Events przycisku "Od nowa" , w OnClick wybieramy FormCreate zeby stworzyc pusta plansze do nowej gry
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pole1Click(TObject *Sender)
{
    if (p1=='n') //instrukcja wykona sie tylko wtedy jesli pole jest puste
    {
    //teraz wszystko zalezy kto klinkal (x lub o)
    if (kto=='o') // gracz kolko
    {
       Pole1->Picture->LoadFromFile("img/o.bmp");
       p1='o'; //pole 1 od teraz bedzie mialo przypisane kolko czli char 'o'
       kto='x';    //zmiana tury gracza na krzyzyk

       //musimy jeszcze podmienic na krzyzyk w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/xsmall.bmp");

    }
    else    // gracz krzyzyk
    {
       Pole1->Picture->LoadFromFile("img/x.bmp");
       p1='x'; //pole 1 od teraz bedzie mialo przypisany krzyzyk czli char 'x'
       kto='o';    //zmiana tury gracza na kolko

       //musimy jeszcze podmienic na kolko w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/osmall.bmp");
    }
     //teraz zmieniamy dostepnosc pola oraz znika reka po najechaniu na pole,
     //funkcja Enabled=false tyczy sie obu przypadkow z gory:
       Pole1->Enabled=false;

       //teraz sprawdzamy czy w jakiejs z tych dwoch tur ktos juz nie wygral (x lub o) procedur¹ void:
       sprawdz();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pole2Click(TObject *Sender)
{
//ustawiamy kursor myszki powyzej tego zdania na puste pole i klikamy ctrl + r
// w ten sposob mozemy zamienic text na inny (np ### na 2 w tym wypadku)

   if (p2=='n') //instrukcja wykona sie tylko wtedy jesli pole jest puste
//zamieniamy (p1 na p2) zeby instrukcja wykonala sie dla kazdego z 9 pol "p"
    {
    //teraz wszystko zalezy kto klinkal (x lub o)
    if (kto=='o') // gracz kolko
    {
       Pole2->Picture->LoadFromFile("img/o.bmp");
       p2='o'; //pole 2 od teraz bedzie mialo przypisane kolko czli char 'o'
       kto='x';    //zmiana tury gracza na krzyzyk

       //musimy jeszcze podmienic na krzyzyk w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/xsmall.bmp");

    }
    else    // gracz krzyzyk
    {
       Pole2->Picture->LoadFromFile("img/x.bmp");
       p2='x'; //pole 2 od teraz bedzie mialo przypisany krzyzyk czli char 'x'
       kto='o';    //zmiana tury gracza na kolko

       //musimy jeszcze podmienic na kolko w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/osmall.bmp");
    }
     //teraz zmieniamy dostepnosc pola oraz znika reka po najechaniu na pole 2,
     //funkcja Enabled=false tyczy sie obu przypadkow z gory:
       Pole2->Enabled=false;

       //teraz sprawdzamy czy w jakiejs z tych dwoch tur ktos juz nie wygral (x lub o) procedur¹ void:
       sprawdz();
    }     
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pole3Click(TObject *Sender)
{
   if (p3=='n') //instrukcja wykona sie tylko wtedy jesli pole jest puste
//zamieniamy (p1 na p3) zeby instrukcja wykonala sie dla kazdego z 9 pol "p"
    {
    //teraz wszystko zalezy kto klinkal (x lub o)
    if (kto=='o') // gracz kolko
    {
       Pole3->Picture->LoadFromFile("img/o.bmp");
       p3='o'; //pole 3 od teraz bedzie mialo przypisane kolko czli char 'o'
       kto='x';    //zmiana tury gracza na krzyzyk

       //musimy jeszcze podmienic na krzyzyk w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/xsmall.bmp");

    }
    else    // gracz krzyzyk
    {
       Pole3->Picture->LoadFromFile("img/x.bmp");
       p3='x'; //pole 3 od teraz bedzie mialo przypisany krzyzyk czli char 'x'
       kto='o';    //zmiana tury gracza na kolko

       //musimy jeszcze podmienic na kolko w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/osmall.bmp");
    }
     //teraz zmieniamy dostepnosc pola oraz znika reka po najechaniu na pole 3,
     //funkcja Enabled=false tyczy sie obu przypadkow z gory:
       Pole3->Enabled=false;

       //teraz sprawdzamy czy w jakiejs z tych dwoch tur ktos juz nie wygral (x lub o) procedur¹ void:
       sprawdz();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pole4Click(TObject *Sender)
{
if (p4=='n') //instrukcja wykona sie tylko wtedy jesli pole jest puste
//zamieniamy (p1 na p4) zeby instrukcja wykonala sie dla kazdego z 9 pol "p"
    {
    //teraz wszystko zalezy kto klinkal (x lub o)
    if (kto=='o') // gracz kolko
    {
       Pole4->Picture->LoadFromFile("img/o.bmp");
       p4='o'; //pole 4 od teraz bedzie mialo przypisane kolko czli char 'o'
       kto='x';    //zmiana tury gracza na krzyzyk

       //musimy jeszcze podmienic na krzyzyk w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/xsmall.bmp");

    }
    else    // gracz krzyzyk
    {
       Pole4->Picture->LoadFromFile("img/x.bmp");
       p4='x'; //pole 4 od teraz bedzie mialo przypisany krzyzyk czli char 'x'
       kto='o';    //zmiana tury gracza na kolko

       //musimy jeszcze podmienic na kolko w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/osmall.bmp");
    }
     //teraz zmieniamy dostepnosc pola oraz znika reka po najechaniu na pole 4,
     //funkcja Enabled=false tyczy sie obu przypadkow z gory:
       Pole4->Enabled=false;

       //teraz sprawdzamy czy w jakiejs z tych dwoch tur ktos juz nie wygral (x lub o) procedur¹ void:
       sprawdz();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pole5Click(TObject *Sender)
{
if (p5=='n') //instrukcja wykona sie tylko wtedy jesli pole jest puste
//zamieniamy (p1 na p5) zeby instrukcja wykonala sie dla kazdego z 9 pol "p"
    {
    //teraz wszystko zalezy kto klinkal (x lub o)
    if (kto=='o') // gracz kolko
    {
       Pole5->Picture->LoadFromFile("img/o.bmp");
       p5='o'; //pole 5 od teraz bedzie mialo przypisane kolko czli char 'o'
       kto='x';    //zmiana tury gracza na krzyzyk

       //musimy jeszcze podmienic na krzyzyk w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/xsmall.bmp");

    }
    else    // gracz krzyzyk
    {
       Pole5->Picture->LoadFromFile("img/x.bmp");
       p5='x'; //pole 5 od teraz bedzie mialo przypisany krzyzyk czli char 'x'
       kto='o';    //zmiana tury gracza na kolko

       //musimy jeszcze podmienic na kolko w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/osmall.bmp");
    }
     //teraz zmieniamy dostepnosc pola oraz znika reka po najechaniu na pole 5,
     //funkcja Enabled=false tyczy sie obu przypadkow z gory:
       Pole5->Enabled=false;

       //teraz sprawdzamy czy w jakiejs z tych dwoch tur ktos juz nie wygral (x lub o) procedur¹ void:
       sprawdz();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pole6Click(TObject *Sender)
{
if (p6=='n') //instrukcja wykona sie tylko wtedy jesli pole jest puste
//zamieniamy (p1 na p6) zeby instrukcja wykonala sie dla kazdego z 9 pol "p"
    {
    //teraz wszystko zalezy kto klinkal (x lub o)
    if (kto=='o') // gracz kolko
    {
       Pole6->Picture->LoadFromFile("img/o.bmp");
       p6='o'; //pole 6 od teraz bedzie mialo przypisane kolko czli char 'o'
       kto='x';    //zmiana tury gracza na krzyzyk

       //musimy jeszcze podmienic na krzyzyk w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/xsmall.bmp");

    }
    else    // gracz krzyzyk
    {
       Pole6->Picture->LoadFromFile("img/x.bmp");
       p6='x'; //pole 6 od teraz bedzie mialo przypisany krzyzyk czli char 'x'
       kto='o';    //zmiana tury gracza na kolko

       //musimy jeszcze podmienic na kolko w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/osmall.bmp");
    }
     //teraz zmieniamy dostepnosc pola oraz znika reka po najechaniu na pole 6,
     //funkcja Enabled=false tyczy sie obu przypadkow z gory:
       Pole6->Enabled=false;

       //teraz sprawdzamy czy w jakiejs z tych dwoch tur ktos juz nie wygral (x lub o) procedur¹ void:
       sprawdz();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pole7Click(TObject *Sender)
{      
 if (p7=='n') //instrukcja wykona sie tylko wtedy jesli pole jest puste
//zamieniamy (p1 na p7) zeby instrukcja wykonala sie dla kazdego z 9 pol "p"
    {
    //teraz wszystko zalezy kto klinkal (x lub o)
    if (kto=='o') // gracz kolko
    {
       Pole7->Picture->LoadFromFile("img/o.bmp");
       p7='o'; //pole 7 od teraz bedzie mialo przypisane kolko czli char 'o'
       kto='x';    //zmiana tury gracza na krzyzyk

       //musimy jeszcze podmienic na krzyzyk w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/xsmall.bmp");

    }
    else    // gracz krzyzyk
    {
       Pole7->Picture->LoadFromFile("img/x.bmp");
       p7='x'; //pole 7 od teraz bedzie mialo przypisany krzyzyk czli char 'x'
       kto='o';    //zmiana tury gracza na kolko

       //musimy jeszcze podmienic na kolko w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/osmall.bmp");
    }
     //teraz zmieniamy dostepnosc pola oraz znika reka po najechaniu na pole 7,
     //funkcja Enabled=false tyczy sie obu przypadkow z gory:
       Pole7->Enabled=false;

       //teraz sprawdzamy czy w jakiejs z tych dwoch tur ktos juz nie wygral (x lub o) procedur¹ void:
       sprawdz();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pole8Click(TObject *Sender)
{
if (p8=='n') //instrukcja wykona sie tylko wtedy jesli pole jest puste
//zamieniamy (p1 na p8) zeby instrukcja wykonala sie dla kazdego z 9 pol "p"
    {
    //teraz wszystko zalezy kto klinkal (x lub o)
    if (kto=='o') // gracz kolko
    {
       Pole8->Picture->LoadFromFile("img/o.bmp");
       p8='o'; //pole 8 od teraz bedzie mialo przypisane kolko czli char 'o'
       kto='x';    //zmiana tury gracza na krzyzyk

       //musimy jeszcze podmienic na krzyzyk w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/xsmall.bmp");

    }
    else    // gracz krzyzyk
    {
       Pole8->Picture->LoadFromFile("img/x.bmp");
       p8='x'; //pole 8 od teraz bedzie mialo przypisany krzyzyk czli char 'x'
       kto='o';    //zmiana tury gracza na kolko

       //musimy jeszcze podmienic na kolko w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/osmall.bmp");
    }
     //teraz zmieniamy dostepnosc pola oraz znika reka po najechaniu na pole 8,
     //funkcja Enabled=false tyczy sie obu przypadkow z gory:
       Pole8->Enabled=false;

       //teraz sprawdzamy czy w jakiejs z tych dwoch tur ktos juz nie wygral (x lub o) procedur¹ void:
       sprawdz();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pole9Click(TObject *Sender)
{
if (p9=='n') //instrukcja wykona sie tylko wtedy jesli pole jest puste
//zamieniamy (p1 na p9) zeby instrukcja wykonala sie dla kazdego z 9 pol "p"
    {
    //teraz wszystko zalezy kto klinkal (x lub o)
    if (kto=='o') // gracz kolko
    {
       Pole9->Picture->LoadFromFile("img/o.bmp");
       p9='o'; //pole 9 od teraz bedzie mialo przypisane kolko czli char 'o'
       kto='x';    //zmiana tury gracza na krzyzyk

       //musimy jeszcze podmienic na krzyzyk w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/xsmall.bmp");

    }
    else    // gracz krzyzyk
    {
       Pole9->Picture->LoadFromFile("img/x.bmp");
       p9='x'; //pole 9 od teraz bedzie mialo przypisany krzyzyk czli char 'x'
       kto='o';    //zmiana tury gracza na kolko

       //musimy jeszcze podmienic na kolko w obrazku kolo "Tura gracza:"
       tura->Picture->LoadFromFile("img/osmall.bmp");
    }
     //teraz zmieniamy dostepnosc pola oraz znika reka po najechaniu na pole 9,
     //funkcja Enabled=false tyczy sie obu przypadkow z gory:
       Pole9->Enabled=false;

       //teraz sprawdzamy czy w jakiejs z tych dwoch tur ktos juz nie wygral (x lub o) procedur¹ void:
       sprawdz();
    }
}
//---------------------------------------------------------------------------



