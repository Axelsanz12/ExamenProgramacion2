#include <iostream>
using namespace std;

#include "Examen.h"
#include "OrdenProduccion.h"
#include "ArchivoOrdenProduccion.h"

void Examen::EjemploDeListado()
{
    ArchivoOrdenProduccion archivo("ordenes_produccion.dat");
    OrdenProduccion registro;

    int i, cantidadRegistros = archivo.CantidadRegistros();
    for(i = 0; i < cantidadRegistros; i++) {
        registro = archivo.Leer(i);
        cout << registro.toCSV() << endl;
    }
}

/*Punto 1
Indicar el número de máquina que más tiempo de trabajo haya registrado en el primer semestre de 2024.
NOTA: Si hay más de una máquina que cumpla esta condición, indicar la primera de ellas.

semestre del 1 al 6
año 24
total de maquinas 15.

*/


void texto(){

    cout <<"-------------------------------------" <<endl;
}

void Examen::Punto1()
{
    ArchivoOrdenProduccion archivo ("ordenes_produccion.dat");
    OrdenProduccion reg;
    int cantidad = archivo.CantidadRegistros();
    if(cantidad==0) {
        cout << "no se encuentran registros " <<endl;
        return;
    }
    float tiempoMaquinas[15]= {};
    bool primerSemestre=false;

    for(int i = 0 ; i < cantidad ; i ++) {
        reg = archivo.Leer(i);
        int anio= reg.getFecha().getAnio();
        int mes= reg.getFecha().getMes();

        // acaaa año 2024 primer semestre
        if(anio == 2024 && mes >=1  && mes <=6) {
        int maq = reg.getIDMaquina();
            float horas = reg.getTiempoEnHoras();
            if(maq >=1 && maq <= 15) {
                tiempoMaquinas [maq -1] += horas;
                primerSemestre=true;
            }
        }
    }

    /// aca tengo que validar si estuvo en primer semestre.

    if(!primerSemestre) {
            texto();
        cout << "no hay orden en el primer semestre.."<<endl;
        return ;
    }

    int tMAx = 0 ;
    for(int i = 1; i < 15; i++) {
        if(tiempoMaquinas[i]> tiempoMaquinas[tMAx]) {
            tMAx = i;
        }

    }
    texto();
    cout << "la maquina con mayor horas en el primer semestre es: " << tMAx +1 <<endl;

}
/*
Punto 2
La cantidad de máquinas distintas que gastaron más de 90000 en total entre todas las producciones del tipo de pieza 15 que realizaron.

 VECTOR DE 15 -> POR LA CANTIDAD DE PIEZAS
 RECORDA QUE EL ENUNCIADO DECIA COSTO EN PESOOOOS.
 MONTO 90000


*/

void Examen::Punto2(){
    ArchivoOrdenProduccion archivo ("ordenes_produccion.dat");
    OrdenProduccion reg;
    int cantidad = archivo.CantidadRegistros();

    if(cantidad == 0 ){

        texto();
        cout << "no hay registros "<<endl;
        return;
    }

    float gastosPorMaquina[15]={};

    for ( int i = 0 ; i < cantidad ; i++ ){

        reg= archivo.Leer(i);

        if(reg.getIDTipoPieza()==15){
            int maq = reg.getIDMaquina();
            float costo = reg.getCosto();

            if(maq >=1 && maq <= 15){
                gastosPorMaquina[maq -1]+= costo;
            }
        }


    }

    int cont = 0;
    for(int i = 0 ; i <15 ; i++ ){
        if(gastosPorMaquina[i] > 90000){
            cont++;
        }
    }

    texto();
    cout <<"cantidad de maquinas con mayor gasto a 90000 en 15 pieza es :" << cont <<endl;



}
 /*
  Punto 3
Las máquinas que hayan utilizado más materia prima en el 2025 que en el 2024.

 diferencial materia prima del 2024 al 2025

 2 vectores uno del 2024 y otro del 2025  x materia

 */


void Examen::Punto3(){
            ArchivoOrdenProduccion archivo ("ordenes_produccion.dat");
    OrdenProduccion reg;
    int cantidad = archivo.CantidadRegistros();

    if(cantidad == 0 ){

        texto();
        cout << "no hay registros "<<endl;
        return;
    }

    float materia2024[15]={};
    float materia2025[15]={};

    for(int i = 0;i <cantidad ; i++){
        reg = archivo.Leer(i);

        int maq = reg.getIDMaquina();
        int anio = reg.getFecha().getAnio();

        float materia = reg.getCantidadMateriaPrima();


       // if(maq >=1 && maq <= 15 ){
            if(anio == 2024){
                materia2024[maq -1 ]+= materia;
            }else if( anio == 2025){
                materia2025[maq -1 ]+= materia;
            }

        }


    bool bandera = false;   // vemos si no se usaron maquinas en ambos años


    for(int i=0; i < 15 ; i++){
        if(materia2025[i]> materia2024[i]){
                texto();
            cout << "con mayor utilizacion de materia prima maquina: "  << i + 1 << endl;
            bandera= true;
        }

    }
    if(bandera==false){
                texto();
            cout << "no se utilaron materias primas en el 2025 > 2024" <<endl;
        }




    }


