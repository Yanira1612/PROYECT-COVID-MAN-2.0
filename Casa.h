#include "Obstaculos.h"
#include <allegro.h>
class Casa : public Obstaculos{
   private:
   BITMAP *casa=NULL;//Variable de la imagen del muro;
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
