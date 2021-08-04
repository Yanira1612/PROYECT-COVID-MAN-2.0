#include "Comida.h"
class Pastilla : public Comida{
   private:
   BITMAP *pastilla=NULL;//Variable de la imagen del muro;
   int ejeX;
   int ejeY;
   public:
   Pastilla();
   ~Pastilla();
   int getEjeX();
   int getEjeY();
   BITMAP* getPastilla();
};
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

