#include "Obstaculos.h"
#include <allegro.h>
class Casa : public Obstaculos{
   private:
   BITMAP *casa=nullptr;//Variable de la imagen del muro;
   const char** tipoCasa;
   int ejeX;
   int ejeY;
   int tipo;
   public:
   Casa();
   ~Casa();
   int getEjeX();
   int getEjeY();
   void setTipo(int);
   void definirCasa();
   BITMAP* getCasa();
};
Casa::~Casa(){
   delete []tipoCasa;
}
Casa::Casa(){
   //this->casa=load_bitmap("casita.bmp",nullptr);//
   tipoCasa=new const char*[3];
   tipoCasa[0]="casita.bmp";
   tipoCasa[1]="casa1.bmp";
   tipoCasa[2]="casa2.bmp";
   this->ejeX=30;
   this->ejeY=30;
}
int Casa::getEjeX(){
   return ejeX;
}
int Casa::getEjeY(){
   return ejeY;
}
BITMAP* Casa::getCasa(){
   return casa;
}
void Casa::setTipo(int tipo){
   this->tipo=tipo;
}
void Casa::definirCasa(){
  if(tipo%2==0){
    this->casa=load_bitmap("casita.bmp",nullptr);
  }
  else if(tipo%3==0){
    this->casa=load_bitmap("casa1.bmp",nullptr);
  }
  else{
    this->casa=load_bitmap("casa2.bmp",nullptr);
  }
}
