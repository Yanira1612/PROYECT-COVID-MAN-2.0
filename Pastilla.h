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


