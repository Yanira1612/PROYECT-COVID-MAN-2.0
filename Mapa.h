#include <allegro.h>
#include "Covid_man.h"
#include "Casa.h"
#include "Comida.h"
#include <iostream>
//buffer y el mapa tienen las mismas dimensiones
using namespace std;

class Mapa{
    private:
    //Buffer buffer;//Creamos un bitmap en la RAM
    Casa casa;//Imagen casa
    int nivel;//nivel en el que se encuentra el mapa
    int ejeX;
    int ejeY;
    int puntos=0;
    Covid_man jugador;
    Comida comida;
    public:
    Mapa(int,int,int);//(nombrefichero,nivel,ejex,ejey)
    void Mostrar();//mOSTRAMOS TODO EL COMPORTAMIENTO DEL JUEGO EN LA PANTALLA
    void dibujar_mapa();//Creamos el mapa con todos sus componentes
    void pantalla();//Creamos el buffer enciam de la ventana
    void Proceso();//mOSTRAMOS TODO EL COMPORTAMIENTO DEL JUEGO EN LA PANTALLA
    bool Win();//Nos indica si hemos ganado un determinado nivel
    void avanzarNivel();//Para avanzar a un siguiente nivel
    const char* pantallaNivel();//dEFINIMOS EL NIVEL EN EL QUE ESTA EL MAPA
    void mostrarNivelMapa();//Mostramos el nivel del mapa en pantalla
    const char* cantidadPuntos();//Nos devolvera cuantos puntos tiene el jugador
    void imprimirPuntosPantalla();//Imprimiremos los puntos en pantalla

    void setNivelMapa(int);
    int getNivelMapa();
    void setEjeX(int);
    int getEjeX();
    void setEjeY(int);
    int getEjeY();
    int getPuntos();
    void setPuntos(int);


};
Mapa::Mapa(int nivel,int ejeX,int ejeY){
   this->ejeX=ejeX;
   this->ejeY=ejeY;
   //create_bitmap() crea un bitmap en la RAM
   buffer.buffer=create_bitmap(this->ejeX,this->ejeY);//(29*30,20*30) creamos un espacio rectangular
   this->nivel=nivel;
}

void Mapa::setNivelMapa(int nivel){
   this->nivel=nivel;
}
int Mapa::getNivelMapa(){
   return this->nivel;

}
void Mapa::setPuntos(int puntos){
   this->puntos=puntos;
}
int Mapa::getPuntos(){
   return this->puntos;

}
void Mapa::setEjeX(int ejeX){
   this->ejeX=ejeX;
}
int Mapa::getEjeX(){
   return this->ejeX;

}
void Mapa::setEjeY(int ejeY){
   this->ejeY=ejeY;
}
int Mapa::getEjeY(){
   return this->ejeY;

}


void Mapa::Mostrar(){
    Mapa::Proceso();
}
void Mapa::dibujar_mapa(){//Dibujamos el mapa de acuerdo al nivel
     if(Mapa::getNivelMapa()==1){
        jugador.setNumMapa(Mapa::getNivelMapa());//Accedemos a la configuracion del atajo del mapa1
        for(int row=0;row<MAXFILAS;row++){
          for(int col=0;col<MAXCOLS;col++){
              if(mapa1[row][col]=='X'){
                 draw_sprite(buffer.buffer,casa.casa,col*casa.ejeY,row*casa.ejeX);//Imprimimos casa sobre buffer
              }
              else if(mapa1[row][col]=='o'){
                 draw_sprite(buffer.buffer,comida.comida,col*30,row*30);
                 if((jugador.getPosY())/30==row && (jugador.getPosX())/30==col){//Dividimos entre 30 para que regrese a las dimensiones que le corresponde
                    mapa1[row][col]=' ';
                    puntos++;
                 }
              }


          }
        }
     }//fin nivel1
     else if(Mapa::getNivelMapa()==2){
        jugador.setNumMapa(Mapa::getNivelMapa());//Accedemos a la configuracion del atajo del mapa2
        for(int row=0;row<MAXFILAS;row++){
          for(int col=0;col<MAXCOLS;col++){
              if(mapa2[row][col]=='X'){
                draw_sprite(buffer.buffer,casa.casa,col*casa.ejeX,row*casa.ejeY);//Imprimimos roca sobre buffer
              }
              else if(mapa2[row][col]=='o'){
                 draw_sprite(buffer.buffer,comida.comida,col*30,row*30);
                 if((jugador.getPosY())/30==row && (jugador.getPosX())/30==col){//Dividimos entre 30 para que regrese a las dimensiones que le corresponde
                    mapa2[row][col]=' ';
                    puntos++;
                 }
              }


          }
        }
     }//fin nivel2
   }
void Mapa::pantalla(){//blit() lo copia a la pantalla
    blit(buffer.buffer,screen,0,0,0,0,buffer.ejeX,buffer.ejeY);//imprimimos el buffer sobre la pantalla
    //buffer origen y screen destino
    //Copia un área rectangular del mapa de bits de origen en el mapa de bits de destino.
}//para mi
void Mapa::Proceso(){
    while(!key[KEY_ESC]){
         jugador.movimientoPacman();
         Mapa::dibujar_mapa();//creamos el buffer

         Mapa::mostrarNivelMapa();//Colocamos aqui para que no aprezca de forma parpadeante en pantalla
         Mapa::imprimirPuntosPantalla();

         jugador.dibujarPacman();

         pantalla();
         rest(70);//delay 70 ms
         jugador.morderPacman();
         pantalla();

         rest(90);
         Mapa::avanzarNivel();
    }
}
bool Mapa::Win(){//Para saber si hemos ganado
    int row,col;
    if(Mapa::getNivelMapa()==1){
      for(row=0;row<MAXFILAS;row++){
         for(col=0;col<MAXCOLS;col++){
            if(mapa1[row][col]=='o')
                return false;
         }
      }
    }
    else if(Mapa::getNivelMapa()==2){
      for(row=0;row<MAXFILAS;row++){
         for(col=0;col<MAXCOLS;col++){
            if(mapa2[row][col]=='o')
                return false;
         }
      }
    }

   return true;

}
void Mapa::avanzarNivel(){
   if(Mapa::Win()){
      Mapa::setNivelMapa(++nivel);//Para pasar al siguiente nivel
   }

}
const char* Mapa::pantallaNivel(){
   const char pantNivel[]="NIVEL0";
   const char *pantNivelPtr=pantNivel;
   if(Mapa::getNivelMapa()==1){
       pantNivelPtr="NIVEL1";
   }
   else if(Mapa::getNivelMapa()==2){
       pantNivelPtr="NIVEL2";
   }
   else if(Mapa::getNivelMapa()==3){
       pantNivelPtr="NIVEL3";
   }
   return pantNivelPtr;
}
void Mapa::mostrarNivelMapa(){
   textout_centre_ex(buffer.buffer, font,Mapa::pantallaNivel(), 30, 630, 0xFFFFFF, 0);
}
void Mapa::imprimirPuntosPantalla(){
   textout_centre_ex(buffer.buffer, font,"PUNTAJE:", 120, 630, 0xFFFFFF, 0);
   textout_centre_ex(buffer.buffer, font,Mapa::cantidadPuntos(), 90, 640, 0xFFFFFF, 0);
}
const char* Mapa::cantidadPuntos(){
   const char pantNivel[]="0";
   const char *pantNivelPtr=pantNivel;
   if(Mapa::getPuntos()==1)pantNivelPtr="1";
   else if(Mapa::getPuntos()==2)pantNivelPtr="2";
   else if(Mapa::getPuntos()==3)pantNivelPtr="3";
   else if(Mapa::getPuntos()==4)pantNivelPtr="4";
   else if(Mapa::getPuntos()==5)pantNivelPtr="5";
   else if(Mapa::getPuntos()==6)pantNivelPtr="6";
   else if(Mapa::getPuntos()==7)pantNivelPtr="7";
   else if(Mapa::getPuntos()==8)pantNivelPtr="8";
   else if(Mapa::getPuntos()==9)pantNivelPtr="9";
   else if(Mapa::getPuntos()==10)pantNivelPtr="10";
   else if(Mapa::getPuntos()==11)pantNivelPtr="11";
   else if(Mapa::getPuntos()==12)pantNivelPtr="12";
   else if(Mapa::getPuntos()==13)pantNivelPtr="13";
   else if(Mapa::getPuntos()==14)pantNivelPtr="14";
   else if(Mapa::getPuntos()==15)pantNivelPtr="15";
   else if(Mapa::getPuntos()==16)pantNivelPtr="16";
   else if(Mapa::getPuntos()==17)pantNivelPtr="17";

   return pantNivelPtr;

}
