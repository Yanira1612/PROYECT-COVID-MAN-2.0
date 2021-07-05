#include <allegro.h>
#include "Covid_man.h"
#include "Casa.h"
#include "Comida.h"
#include <iostream>
//buffer y el mapa tienen las mismas dimensiones
using namespace std;

const char* CantPuntos[]={"0","1","2","3","4","5","6","7","8","9"," 10"," 11"," 12"," 13"," 14"," 15"," 16"," 17"," 18"," 19"," 20",
                          " 21"," 22"," 23"," 24"," 25"," 26"," 27"," 28"," 29"," 30","31"," 32"," 33"," 34"," 35"," 36"," 37"," 38"," 39"," 40",
                          " 41"," 42"," 43"," 44"," 45"," 46"," 47"," 48"," 49"," 50","51"," 52"," 53"," 54"," 55"," 56"," 57"," 58"," 59"," 60",
                          " 61"," 62"," 63"," 64"," 65"," 66"," 67"," 68"," 69"," 70","71"," 72"," 73"," 74"," 75"," 76"," 77"," 78"," 79"," 80",
                          " 81"," 82"," 83"," 84"," 85"," 86"," 87"," 88"," 89"," 90","91"," 92"," 93"," 94"," 95"," 96"," 97"," 98"," 99","  100",
                          "  101","  102","  103","  104","  105","  106","  107","  108","  109","  110","  111","  112","  113","  114","  115","  116","  117","  118","  119","  120",
                          "  121","  122","  123","  124","  125","  126","  127","  128","  129","  130","  131","  132","  133","  134","  135","  136","  137","  138","  139","  140",
                          "  141","  142","  143","  144","  145","  146","  147","  148","  149","  150","  151","  152","  153","  154","  155","  156","  157","  158","  159","  160",
                          "  161","  162","  163","  164","  165","  166","  167","  168","  169","  170","  171","  172","  173","  174","  175","  176","  177","  178","  179","  180",
                          "  181","  182","  183","  184","  185","  186","  187","  188","  189","  190","  191","  192","  193","  194","  195","  196","  197","  198","  199","  200",
                          "  201","  202","  203","  204","  205","  206","  207","  208","  209","  210","  201","  212","  213","  214","  215","  216","  217","  218","  219","  220"};
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
    Enfermo enemigo1;
    Enfermo enemigo2;
    Enfermo enemigo3;
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
        enemigo1.setNumMapa(Mapa::getNivelMapa());
        enemigo2.setNumMapa(Mapa::getNivelMapa());
        enemigo3.setNumMapa(Mapa::getNivelMapa());
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
        enemigo1.setNumMapa(Mapa::getNivelMapa());
        enemigo2.setNumMapa(Mapa::getNivelMapa());
        enemigo3.setNumMapa(Mapa::getNivelMapa());
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
// Jheeremy
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
         textout_centre_ex(buffer.buffer, font,"VIDAS:", 150, 630, 0xFFFFFF, 0);
         textout_centre_ex(buffer.buffer, font,"3", 120, 640, 0xFFFFFF, 0);
         //Zona de declaracion de jugadores
         enemigo1.movimientoEnemigo();
         jugador.dibujarPacman();
         if(jugador.getPosX()==enemigo1.getPosX() && jugador.getPosY()==enemigo1.getPosY()){
            jugador.setVida(jugador.getVida()-1);
           for(int i=0;i<6;i++){
              clear(jugador.getPacman());
              clear(buffer.buffer);
              Mapa::dibujar_mapa();
              blit(jugador.getMuertebmp(),jugador.getPacman(),i*33,0,0,0,33,33);
              draw_sprite(buffer.buffer,jugador.getPacman(),jugador.getPosX(),jugador.getPosY());

             pantalla();
             rest(70);
           }
         }
         //jugador.muertePacman(enemigo1.getPosX(),enemigo1.getPosY());
         //enemigo1.movimientoEnemigo();
         /*enemigo2.movimientoEnemigo();
         enemigo3.movimientoEnemigo();*/

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
   const char pantNivel[]="0";
   const char *pantNivelPtr=pantNivel;
   if(Mapa::getNivelMapa()==1){
       pantNivelPtr="1";
   }
   else if(Mapa::getNivelMapa()==2){
       pantNivelPtr="2";
   }
   else if(Mapa::getNivelMapa()==3){
       pantNivelPtr="3";
   }
   return pantNivelPtr;
}
void Mapa::mostrarNivelMapa(){
   textout_centre_ex(buffer.buffer, font,"NIVEL:", 30, 630, 0xFFFFFF, 0);
   textout_centre_ex(buffer.buffer, font,Mapa::pantallaNivel(), 10, 640, 0xFFFFFF, 0);
}
void Mapa::imprimirPuntosPantalla(){
   textout_centre_ex(buffer.buffer, font,"PUNTAJE:", 120, 630, 0xFFFFFF, 0);
   textout_centre_ex(buffer.buffer, font,Mapa::cantidadPuntos(), 90, 640, 0xFFFFFF, 0);
}
const char* Mapa::cantidadPuntos(){
    return CantPuntos[Mapa::getPuntos()];
}
// Jheeremy
