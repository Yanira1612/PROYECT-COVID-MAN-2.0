#include "Casa.h"
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
    this->casa=load_bitmap("casita.bmp",NULL);
  }
  else if(tipo%3==0){
    this->casa=load_bitmap("casa1.bmp",NULL);
  }
  else{
    this->casa=load_bitmap("casa2.bmp",NULL);
  }
}

