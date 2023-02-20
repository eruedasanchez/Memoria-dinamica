#include "SistemaDeMensajes.h"

/* Completar */

SistemaDeMensajes::SistemaDeMensajes(){
    for(int i = 0; i < 4; i++){
        _conns[i] = nullptr;
    }
}

/* Destructor de la clase */
SistemaDeMensajes::~SistemaDeMensajes(){
    for(int id = 0; id < 4; id++){
        delete _proxys[id];
    }

}

void SistemaDeMensajes::registrarJugador(int id, string ip){
    // Pre: 0 <= id < 4
    /* Codigo del punto 1
    if(_conns[id] != nullptr){
        delete _conns[id];
    } else {
        ConexionJugador* jugador = new ConexionJugador(ip);
        _conns[id] = jugador;
    }
     */

    /* Codigo del punto 3 */
    if(_conns[id] != nullptr){
        /* Se actualiza con el nuevo ip */
        delete _conns[id];
    }
    ConexionJugador* jugador = new ConexionJugador(ip);
    _conns[id] = jugador;
}

/* OBSERVACION: El "const" mas a la derecha indica que la funcion registrado durante su codigo
 * no puede alterar la instancia de la clase Sistema de Mensajes */
bool SistemaDeMensajes::registrado(int id) const {
    // Pre: 0 <= id < 4
    if (_conns[id] != nullptr) {
        return true;
    } else {
        return false;
    }
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje){
    // Pre: registrado(id)
    _conns[id]->enviarMensaje(mensaje);
}

string SistemaDeMensajes::ipJugador(int id) const {
    // Pre: registrado(id)
    return _conns[id]->ip();
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    // Pre: registrado(id)
    _conns[id] = nullptr;
}

Proxy* SistemaDeMensajes::obtenerProxy(int id){
    Proxy* proxy_jugador = new Proxy(_conns[id]);
    return proxy_jugador;
}
