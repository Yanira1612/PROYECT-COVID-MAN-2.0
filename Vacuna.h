
#include "Pastilla.h"
class Vacuna : public Comida{
   private:
   BITMAP *vacuna=nullptr;//Variable de la imagen del muro;
   int ejeX;
   int ejeY;
   public:
   Vacuna();
   ~Vacuna();
   int getEjeX();
   int getEjeY();
   BITMAP* getVacuna();
};
Vacuna::~Vacuna(){

}
Vacuna::Vacuna(){
   this->vacuna=load_bitmap("vacuna.bmp",nullptr);//
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
