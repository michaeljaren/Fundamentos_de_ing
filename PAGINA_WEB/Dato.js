// Seleccionamos el formulario y la tabla
const clienteForm = document.getElementById('clienteForm');
const clientesTable = document.querySelector('#clientesTable tbody');

// Función para agregar una fila a la tabla
function agregarCliente(codigo, nombres, apellidos, numeroCuenta, tipoCuenta) {
    const fila = document.createElement('tr');
    fila.innerHTML = `
        <td>${codigo}</td>
        <td>${nombres}</td>
        <td>${apellidos}</td>
        <td>${numeroCuenta}</td>
        <td>${tipoCuenta}</td>
    `;
    clientesTable.appendChild(fila);
}

// Evento al enviar el formulario
clienteForm.addEventListener('submit', (e) => {
    e.preventDefault(); // Evita el reinicio de la página

    // Obtener los valores de los campos del formulario
    const codigo = document.getElementById('codigo').value;
    const nombres = document.getElementById('nombres').value;
    const apellidos = document.getElementById('apellidos').value;
    const numeroCuenta = document.getElementById('numeroCuenta').value;
    const tipoCuenta = document.getElementById('tipoCuenta').value;

    // Validar que todos los campos tengan datos
    if (codigo && nombres && apellidos && numeroCuenta && tipoCuenta) {
        // Agregar el cliente a la tabla
        agregarCliente(codigo, nombres, apellidos, numeroCuenta, tipoCuenta);

        // Limpiar los campos del formulario
        clienteForm.reset();
    } else {
        alert('Por favor, completa todos los campos.');
    }
});
