#include "Vacuna.h"
Vacuna::~Vacuna(){

}
Vacuna::Vacuna(){
   this->vacuna=load_bitmap("vacuna.bmp",NULL);//
   this->ejeX=30;
   this->ejeY=30;
}
int Vacuna::getEjeX(){
   return ejeX;
}
int Vacuna::getEjeY(){
   return ejeY;
}
BITMAP* Vacuna::getVacuna(){
   return vacuna;
}
