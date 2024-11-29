/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include "rotaryAngleSensor.h"

Application::Application()
{
  // Code
  ; 
}
  
Application::~Application()
{
  // Code
  ;
}  

void Application::init(void)
{
  // Code
}


void Application::run(void)
{
  // Code 
  rotaryAngleSensor* r = new rotaryAngleSensor();
  r->run(); 
}
