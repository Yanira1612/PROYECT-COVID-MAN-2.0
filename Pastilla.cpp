#include "Pastilla.h"
Pastilla::~Pastilla(){

}
Pastilla::Pastilla(){
   this->pastilla=load_bitmap("pastilla.bmp",NULL);//
   this->ejeX=30;
   this->ejeY=30;
}
int Pastilla::getEjeX(){
   return ejeX;
}
int Pastilla::getEjeY(){
   return ejeY;
}
BITMAP* Pastilla::getPastilla(){
   return pastilla;
}
