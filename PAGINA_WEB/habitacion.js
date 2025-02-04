const mongoose = require('mongoose');

const habitacionSchema = new mongoose.Schema({
    idHabitacion: { type: Number, required: true, unique: true },
    tipo: { type: String, required: true },
    precio: { type: Number, required: true },
    estado: { type: String, required: true },
});

module.exports = mongoose.model('Habitacion', habitacionSchema);
