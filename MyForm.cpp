/*
Le programme principal
Exécute la form de l'interface principal (MyForm)
*/

#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(/*array<String^>^args*/)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project2::MyForm form;
	Application::Run(%form);
}

