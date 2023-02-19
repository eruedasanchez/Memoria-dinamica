#include "SistemaDeMensajes.h"

/* Completar */

SistemaDeMensajes::SistemaDeMensajes(){
    for(int i = 0; i < 4; i++){
        _conns[i] = nullptr;
    }
}

void SistemaDeMensajes::registrarJugador(int id, string ip){
    // Pre: 0 <= id < 4
}

bool SistemaDeMensajes::registrado(int id) const{

}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje){
    // Pre: registrado(id)
}

string SistemaDeMensajes::ipJugador(int id) const{
    // Pre: registrado(id)
}
