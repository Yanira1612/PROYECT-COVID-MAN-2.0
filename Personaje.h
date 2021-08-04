
#include "Buffer.h"
class Personaje{
     private:

     public:
     virtual int getPosX()=0;
     virtual int getPosY()=0;
     virtual void setNumMapa(int)=0;
     virtual void movimiento()=0;
     virtual void dibujar()=0;
     virtual void atajo(int)=0;

};
