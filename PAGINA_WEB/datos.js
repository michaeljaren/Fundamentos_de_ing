// Muestra para compilar en el html de alado
console.log("Bienvenido a la Cooperativa de Ahorro y Crédito.");

// Función para agregar un nuevo cliente y mostrar en la consola
function agregarCliente(codigo, nombres, apellidos, numeroCuenta, tipoCuenta) {
    // Imprimir en la consola los datos del cliente
    console.log("Nuevo cliente agregado:");
    console.log("Código: " + codigo);
    console.log("Nombres: " + nombres);
    console.log("Apellidos: " + apellidos);
    console.log("Número de Cuenta: " + numeroCuenta);
    console.log("Tipo de Cuenta: " + tipoCuenta);
}

// Agregar un nuevo cliente al cooperativa
document.getElementById('clienteForm').addEventListener('submit', function(event) {
    event.preventDefault(); // Prevenir el envío del formulario

    // Obtener los valores de los campos del formulario
    const codigo = document.getElementById('codigo').value;
    const nombres = document.getElementById('nombres').value;
    const apellidos = document.getElementById('apellidos').value;
    const numeroCuenta = document.getElementById('numeroCuenta').value;
    const tipoCuenta = document.getElementById('tipoCuenta').value;

    // sirve para agregar un nuevo cliente
    agregarCliente(codigo, nombres, apellidos, numeroCuenta, tipoCuenta);

    // Crear una nueva fila en la tabla
    const table = document.getElementById('clientesTable').getElementsByTagName('tbody')[0];
    const newRow = table.insertRow();


    newRow.insertCell(0).textContent = codigo;
    newRow.insertCell(1).textContent = nombres;
    newRow.insertCell(2).textContent = apellidos;
    newRow.insertCell(3).textContent = numeroCuenta;
    newRow.insertCell(4).textContent = tipoCuenta;

    // Limpiar los campos del formulario
    document.getElementById('clienteForm').reset();
});
