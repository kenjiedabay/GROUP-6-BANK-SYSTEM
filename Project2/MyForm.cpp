#include "MyForm2h.h"
#include "homeform.h"
#include "depositform.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main() {
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project2::homeform form;


	Application::Run(% form);


}