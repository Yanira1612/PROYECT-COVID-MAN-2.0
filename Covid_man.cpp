#include "Covid_man.h"
SAMPLE* Covid_man::getMusicMuerte(){
    return muerte;
}
Covid_man::~Covid_man(){

}
Covid_man::Covid_man(){
    this->muerte= load_wav("muerte.wav");
    this->pacbmp=load_bitmap("covid_man.bmp",NULL);;//Creara un espacio en donde estara pacman
    this->muertebmp=load_bitmap("muerte.bmp",NULL);
    this->pacman=create_bitmap(33,33);//Dimensiones de un pacman;//Imagen pacman
    this->dir=4;//para que pacman no se mueva al iniciar el juego
    this->px=30*14;
    this->py=30*17;//posicion adecuada de pacman
    this->numMapa=1;
    this->vidas=3;
}
BITMAP* Covid_man::getMuertebmp(){
    return muertebmp;
    }
void Covid_man::setPacman(BITMAP* pacman){
    this->pacman=pacman;
    }
BITMAP* Covid_man::getPacman(){
    return this->pacman;
    }
void Covid_man::inicioMuerte(){
    clear(pacman);
    clear(buffer.buffer);
}
void Covid_man::finalMuerte(int i){
    blit(muertebmp,pacman,i*33,0,0,0,33,33);
    draw_sprite(buffer.buffer,pacman,px,py);
}
const char* Covid_man::imprimirVida(int vida){
    if(vida==0)
        return "0";

    else if(vida==1)
        return "1";

    else if(vida ==2)
        return "2";

    else if(vida ==3)
        return "3";

    else if(vida ==4)
        return "4";

    else if(vida ==5)
        return "5";

    else if(vida ==6)
        return "6";

    return "error";
}
void Covid_man::movimiento(){
    if(key[KEY_LEFT])
            dir=0;
    else if(key[KEY_RIGHT])
            dir=1;
    else if(key[KEY_UP])
            dir=2;
    else if(key[KEY_DOWN])
            dir=3;

    if(numMapa==1){//Nivel 1 del juego
        if(dir==0){
          if(mapa1[py/30][(px-30)/30]!='X')//Evitamos que pacman cruce los muros
             px=px-30;
          else
             dir=4;
        }
        else if(dir==1){
           if(mapa1[py/30][(px+30)/30]!='X')
             px=px+30;
           else
             dir=4;
        }
        else if(dir==2){
           if(mapa1[(py-30)/30][(px)/30]!='X')
             py=py-30;
           else
             dir=4;
         }

        else if(dir==3){
           if(mapa1[(py+30)/30][(px)/30]!='X')
              py=py+30;
           else
              dir=4;
        }
    }
    else if(numMapa==2){//Nivel 2 del juego
        if(dir==0){
          if(mapa2[py/30][(px-30)/30]!='X')//Evitamos que pacman cruce los muros
             px=px-30;
          else
             dir=4;
        }
        else if(dir==1){
           if(mapa2[py/30][(px+30)/30]!='X')
             px=px+30;
           else
             dir=4;
        }
        else if(dir==2){
           if(mapa2[(py-30)/30][(px)/30]!='X')
             py=py-30;
           else
             dir=4;
         }

        else if(dir==3){
           if(mapa2[(py+30)/30][(px)/30]!='X')
              py=py+30;
           else
              dir=4;
        }
    }
    Covid_man::atajo(numMapa);
    clear(buffer.buffer);//borramos posiciones anteriores de pacman
}
void Covid_man::dibujar(){

    blit(pacbmp,pacman,dir*33,0,0,0,33,33);
    draw_sprite(buffer.buffer,pacman,px,py);//para respetar transparencia

}
void Covid_man::morderPacman(){
    clear(pacman);
    blit(pacbmp,pacman,4*33,0,0,0,33,33);
    draw_sprite(buffer.buffer,pacman,px,py);//para respetar transparencia

}
void Covid_man::atajo(int numMapa){
    if(numMapa==1){//Deinicion del atajo del mapa 1
        if(px<=-30 && py==270){
            px=870;py=270;
        }
        else if(px>=870 && py==270){
            px=-30;py=270;
        }
        else if(px<=-30 && py==540){
            px=870;py=30;
        }
        else if(px>=870 && py==30){
            px=-30;py=540;
        }
        else if(px>=870 && py==330){
            px=870;py=540;
        }
        else if(px>=870 && py==540){
            px=870;py=330;
        }
   }
   else if(numMapa==2){
        if(px<=-30 && py==270){
            px=870;py=270;
        }
        else if(px>=870 && py==270){
            px=-30;py=270;
        }
        else if(px<=-30 && py==540){
            px=870;py=30;
        }
        else if(px>=870 && py==30){
            px=-30;py=540;
        }
        else if(px>=870 && py==330){
            px=870;py=540;
            dir=0;//Para que vaya en la direccion correcta ya que el taajo entrada y salida estan en el mismo muro
        }
        else if(px>=870 && py==540){
            px=870;py=330;
            dir=0;//Para que vaya en la direccion correcta
        }
   }

}
int Covid_man::getPosX(){
    return px;
}
int Covid_man::getPosY(){
    return py;
}
void Covid_man::setNumMapa(int numMapa){//pARA SABER EN QUE MAPA ESTAMOS
    this->numMapa=numMapa;
}
int Covid_man::getVida(){
   return this->vidas;
}
void Covid_man::setVida(int vidas){
   this->vidas=vidas;
}
void Covid_man::ganarVida(int puntos){
    if(puntos%100==0 && puntos!=0){
        vidas++;
    }
}

