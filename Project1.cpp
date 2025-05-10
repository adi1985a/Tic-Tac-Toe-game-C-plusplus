//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);

                 //Application->ShowMainForm=false;
                 //Powyzsza komenda sprawi, ze program wlaczy sie w trayu od razu, lewy dolny róg windowsa, mozemy to takze zrobic zmieniajac ustawienia w form1 - properties - windowstate
                 //Dodatkowo jesli usuniemy ikone na prawo od ikony zegarka to program bedzie dzialal niewidocznie w trayu
                 //Mozemy go wylaczyc dopiero w menadzerze zadan w procesach
                 //..tak wlasnie dzialaja maleware'y

                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
