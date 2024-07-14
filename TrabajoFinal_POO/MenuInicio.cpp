#include "MenuInicio.h"
#include<time.h>
using namespace TrabajoFinalPOO;
void main() {
	srand(time(0));
	Application::EnableVisualStyles();
	Application::Run(gcnew MenuInicio());
}
