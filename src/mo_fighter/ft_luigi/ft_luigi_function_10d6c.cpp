extern "C" bool fn_27_1D90D4(void* object);

// Recover the complete fighter from its secondary interface.
extern "C" bool fn_99_10D6C(void* object) {
    return fn_27_1D90D4(static_cast<unsigned char*>(object) - 0x88);
}
