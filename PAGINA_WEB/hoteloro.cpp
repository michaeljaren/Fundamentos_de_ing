#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Reserva {
    int idReserva;
    int idHabitacion;
    string nombreCliente;
    string correoCliente;
    string telefonoCliente;
    int cantidadPersonas;
    string fechaInicio;
    string fechaFin;
    string estado;
};

class HotelOroVerde {
private:
    vector<Reserva> reservas;
    int nextIdReserva = 1;

public:
    void menu();
    void agendarReserva();
    void consultarReserva();
    void contacto();
};

void HotelOroVerde::menu() {
    int option;

    do {
        cout << "=== Hotel Oro Verde - Guayaquil ===" << endl;
        cout << "1. Agendar reserva en el hotel" << endl;
        cout << "2. Consultar reserva" << endl;
        cout << "3. Contacto" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> option;

        switch (option) {
            case 1:
                agendarReserva();
                break;
            case 2:
                consultarReserva();
                break;
            case 3:
                contacto();
                break;
            case 4:
                cout << "¡Gracias por usar nuestro sistema!" << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (option != 4);
}

void HotelOroVerde::agendarReserva() {
    Reserva nuevaReserva;
    cout << "Ingrese la cantidad de personas: ";
    cin >> nuevaReserva.cantidadPersonas;

    cout << "Seleccione el tipo de habitacion:" << endl;
    cout << "1. Habitacion Estandar - $150" << endl;
    cout << "2. Habitacion Superior - $200" << endl;
    cout << "3. Habitacion Ejecutiva - $250" << endl;
    cout << "4. Suite - $350" << endl;
    cout << "5. Habitacion Familiar - $300" << endl;
    cout << "Seleccione una opcion: ";
    int tipoHabitacion;
    cin >> tipoHabitacion;

    // Validar entrada de habitacion
    while (tipoHabitacion < 1 || tipoHabitacion > 5) {
        cout << "Opcion no valida. Seleccione nuevamente: ";
        cin >> tipoHabitacion;
    }

    cout << "Ingrese el CI del cliente (10 digitos): ";
    cin >> nuevaReserva.idHabitacion;
    while (nuevaReserva.idHabitacion < 1000000000 || nuevaReserva.idHabitacion > 9999999999) {
        cout << "El ID de la habitacion debe ser de 10 digitos. Intente nuevamente: ";
        cin >> nuevaReserva.idHabitacion;
    }

    cout << "Ingrese el nombre del cliente: ";
    cin.ignore(); 
    getline(cin, nuevaReserva.nombreCliente);
    cout << "Ingrese el correo del cliente: ";
    getline(cin, nuevaReserva.correoCliente);
    cout << "Ingrese el telefono del cliente: ";
    getline(cin, nuevaReserva.telefonoCliente);
    cout << "Ingrese la fecha de inicio de la reserva (DD/MM/AAAA): ";
    getline(cin, nuevaReserva.fechaInicio);
    cout << "Ingrese la fecha de fin de la reserva (DD/MM/AAAA): ";
    getline(cin, nuevaReserva.fechaFin);

    nuevaReserva.idReserva = nextIdReserva++;
    nuevaReserva.estado = "Reservado";

    reservas.push_back(nuevaReserva);
    cout << "Reserva agendada con exito. ID de reserva: " << nuevaReserva.idReserva << endl;
}

void HotelOroVerde::consultarReserva() {
    int idReserva;
    cout << "Ingrese el ID de la reserva: ";
    cin >> idReserva;

    bool found = false;
    for (const auto& reserva : reservas) {
        if (reserva.idReserva == idReserva) {
            cout << "Detalles de la reserva:" << endl;
            cout << "ID Habitacion: " << reserva.idHabitacion << endl;
            cout << "Nombre Cliente: " << reserva.nombreCliente << endl;
            cout << "Correo: " << reserva.correoCliente << endl;
            cout << "Telefono: " << reserva.telefonoCliente << endl;
            cout << "Cantidad de Personas: " << reserva.cantidadPersonas << endl;
            cout << "Fecha de Inicio: " << reserva.fechaInicio << endl;
            cout << "Fecha de Fin: " << reserva.fechaFin << endl;
            cout << "Estado: " << reserva.estado << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Reserva no encontrada." << endl;
    }
}

void HotelOroVerde::contacto() {
    cout << "=== Contacto ===" << endl;
    cout << "Direccion: Av. 9 de Octubre, Guayaquil, Ecuador" << endl;
    cout << "Telefono: +593 4 123 4567" << endl;
    cout << "Email: info@oroverdeguayaquil.com" << endl;
    cout << "¡Siguenos en nuestras redes sociales!" << endl;
}

int main() {
    HotelOroVerde hotel;
    hotel.menu();
    return 0;
}
