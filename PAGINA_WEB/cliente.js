const mongoose = require('mongoose');

const clienteSchema = new mongoose.Schema({
    idCliente: { type: Number, required: true, unique: true },
    nombre: { type: String, required: true },
    correo: { type: String, required: true, unique: true },
    telefono: { type: String, required: true },
});

module.exports = mongoose.model('Cliente', clienteSchema);
