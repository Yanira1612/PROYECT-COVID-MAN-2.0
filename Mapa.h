#include <allegro.h>
#include "Covid_man.h"
#include "Casa.h"
#include "Vacuna.h"
#include <iostream>
#include <cstdlib>
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
    bool salida=false;
    bool entrar=true;
    //musica
    //SAMPLE *muerte= load_wav("muerte.wav");
    MIDI *musica= load_midi("musica_fondo.mid");
    SAMPLE *recoger= load_wav("recoger.wav");

    BITMAP *fondo1=load_bitmap("FONDO1.bmp",nullptr);
    BITMAP *fondo2=load_bitmap("FONDO2.bmp",nullptr);
    BITMAP *fondo3=load_bitmap("FONDO3.bmp",nullptr);
    BITMAP *cursor=load_bitmap("cursor.bmp",nullptr);
    BITMAP *over=load_bitmap("over.bmp",nullptr);
    BITMAP *win=load_bitmap("win.bmp",nullptr);
    //Buffer buffer;//Creamos un bitmap en la RAM
    //Casa casa;//Imagen casa
    int nivel;//nivel en el que se encuentra el mapa
    int ejeX;
    int ejeY;
    int puntos=0;
    Covid_man jugador;
    Casa* casa=new Casa();

    Pastilla* pastilla=new Pastilla();
    Vacuna* vacuna=new Vacuna();
    Enfermo enemigo1{"enemigo1.bmp"};
    Enfermo enemigo2{"enemigo2.0.bmp"};
    Enfermo enemigo3;
    public:
    Mapa(int,int,int);//(nombrefichero,nivel,ejex,ejey)
    ~Mapa();
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
    void cruce();
    void mostrarWin(bool);
    void mostrarOver(bool);
    void menu();

    void setNivelMapa(int);
    int getNivelMapa();
    void setEjeX(int);
    int getEjeX();
    void setEjeY(int);
    int getEjeY();
    int getPuntos();
    void setPuntos(int);


};
Mapa::~Mapa(){



}
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
              if(mapa1[row][col]=='X'){//Coordenada para dibujar una casa
                  casa->setTipo(row);
                  casa->definirCasa();
                  draw_sprite(buffer.buffer,casa->getCasa(),col*casa->getEjeX(),row*casa->getEjeY());//Imprimimos casa sobre buffer

              }
              else if(mapa1[row][col]=='o'){//Coordenada para dibujar comida
                 draw_sprite(buffer.buffer,pastilla->getPastilla(),col*pastilla->getEjeX(),row*pastilla->getEjeY());
                 if((jugador.getPosY())/30==row && (jugador.getPosX())/30==col){//Dividimos entre 30 para que regrese a las dimensiones que le corresponde
                    //play_sample(recoger,300,150,1000,0);
                    mapa1[row][col]=' ';
                    puntos++;
                 }
              }
              else if(mapa1[row][col]=='v'){
                 draw_sprite(buffer.buffer,vacuna->getVacuna(),col*vacuna->getEjeX(),row*vacuna->getEjeY());
                 if((jugador.getPosY())/30==row && (jugador.getPosX())/30==col){//Dividimos entre 30 para que regrese a las dimensiones que le corresponde
                    //play_sample(recoger,300,150,1000,0);
                    mapa1[row][col]=' ';
                    puntos=puntos+2;
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
                  casa->setTipo(row);
                  casa->definirCasa();
                  draw_sprite(buffer.buffer,casa->getCasa(),col*casa->getEjeX(),row*casa->getEjeY());
              }
              else if(mapa2[row][col]=='o'){
                 draw_sprite(buffer.buffer,pastilla->getPastilla(),col*pastilla->getEjeX(),row*pastilla->getEjeY());
                 if((jugador.getPosY())/30==row && (jugador.getPosX())/30==col){//Dividimos entre 30 para que regrese a las dimensiones que le corresponde
                    play_sample(recoger,300,150,1000,0);
                    mapa2[row][col]=' ';
                    puntos++;
                 }
              }
              else if(mapa1[row][col]=='v'){
                 draw_sprite(buffer.buffer,vacuna->getVacuna(),col*vacuna->getEjeX(),row*vacuna->getEjeY());
                 if((jugador.getPosY())/30==row && (jugador.getPosX())/30==col){//Dividimos entre 30 para que regrese a las dimensiones que le corresponde
                    play_sample(recoger,300,150,1000,0);
                    mapa1[row][col]=' ';
                    puntos=puntos+2;
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
    pantalla();

    menu();//pantalla de inicio del usuario
    //play_midi(musica,1);
    while(!key[KEY_ESC] && entrar==true){
         jugador.movimiento();
         Mapa::dibujar_mapa();//creamos el buffer

         Mapa::mostrarNivelMapa();//Colocamos aqui para que no aprezca de forma parpadeante en pantalla
         Mapa::imprimirPuntosPantalla();
         textout_centre_ex(buffer.buffer, font,"VIDAS:", 210, 630, 0xFFFFFF, 0);
         textout_centre_ex(buffer.buffer, font,jugador.imprimirVida(jugador.getVida()), 190, 640, 0xFFFFFF, 0);

         //Zona de declaracion de jugadores
         enemigo1.movimiento();
         enemigo2.movimiento();
         enemigo3.movimiento();
         jugador.dibujar();

         Mapa::cruce();//Cruce entre jugador y enemigos

         pantalla();
         rest(70);//delay 70 ms
         jugador.morderPacman();
         pantalla();

         rest(90);
         Mapa::avanzarNivel();

         Mapa::mostrarOver(entrar);
         Mapa::mostrarWin(entrar);
    }
}
void Mapa::menu(){
    while(!salida){
        if(mouse_x>380 && mouse_x<500 && mouse_y>290 && mouse_y<345){//comenzar
            blit(fondo2,buffer.buffer,0,0,0,0,880,700);
            if(mouse_b& 1){//1 es click derrecho mouse_b es click
                salida=true;
            }
        }
        else if(mouse_x>380 && mouse_x<500 && mouse_y>400 && mouse_y<460){
            blit(fondo3,buffer.buffer,0,0,0,0,880,700);
            if(mouse_b& 1){//1 es click derrecho mouse_b es click
                salida=true;
                entrar=false;
            }
        }
        else{
            blit(fondo1,buffer.buffer,0,0,0,0,880,700);
        }
        masked_blit(cursor,buffer.buffer,0,0,mouse_x,mouse_y,13,22);
        blit(buffer.buffer,screen,0,0,0,0,880,700);
        clear(buffer.buffer);
    }
}
void Mapa::mostrarWin(bool entrar){
    if(Mapa::getNivelMapa()>2 && jugador.getVida()>0){
            clear(buffer.buffer);
            //textout_centre_ex(buffer.buffer, font,"WIN ", 390, 390, 0xFFFFFF, 0);
            blit(win,buffer.buffer,0,0,0,0,1280,930);
            remove_sound();
            pantalla();
            rest(10000);//Esperamos 10 segundos
            entrar=false;
    }
}
void Mapa::mostrarOver(bool entrar){
    if(jugador.getVida()==0){//Si perdemos el juego
            clear(buffer.buffer);
            //textout_centre_ex(buffer.buffer, font,"GAME OVER ", 390, 390, 0xFFFFFF, 0);
            blit(over,buffer.buffer,0,0,0,0,1280,930);
            remove_sound();
            pantalla();
            rest(10000);//Esperamos 10 segundos
            entrar=false;
      }
}
void Mapa::cruce(){
    if(jugador.getPosX()==enemigo1.getPosX() && jugador.getPosY()==enemigo1.getPosY()){
           play_sample(jugador.getMusicMuerte(),300,150,1000,0);
           rest(70);
           jugador.setVida(jugador.getVida()-1);
           for(int i=0;i<6;i++){
              jugador.inicioMuerte();
              Mapa::dibujar_mapa();
              jugador.finalMuerte(i);

             pantalla();
             rest(70);
           }
           play_midi(musica,1);
       }
    if(jugador.getPosX()==enemigo2.getPosX() && jugador.getPosY()==enemigo2.getPosY()){
            play_sample(jugador.getMusicMuerte(),300,150,1000,0);
            rest(70);
            jugador.setVida(jugador.getVida()-1);
           for(int i=0;i<6;i++){
              jugador.inicioMuerte();
              Mapa::dibujar_mapa();
              jugador.finalMuerte(i);

             pantalla();
             rest(70);
           }
           play_midi(musica,1);
       }
    if(jugador.getPosX()==enemigo3.getPosX() && jugador.getPosY()==enemigo3.getPosY()){
            play_sample(jugador.getMusicMuerte(),300,150,1000,0);
            rest(70);
            jugador.setVida(jugador.getVida()-1);
           for(int i=0;i<6;i++){
              jugador.inicioMuerte();
              Mapa::dibujar_mapa();
              jugador.finalMuerte(i);

             pantalla();
             rest(70);

           }
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

