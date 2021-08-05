#include "Pastilla.cpp"
class Vacuna : public Comida{
   private:
   BITMAP *vacuna=NULL;//Variable de la imagen del muro;
   int ejeX;
   int ejeY;
   public:
   Vacuna();
   ~Vacuna();
   int getEjeX();
   int getEjeY();
   BITMAP* getVacuna();
};

