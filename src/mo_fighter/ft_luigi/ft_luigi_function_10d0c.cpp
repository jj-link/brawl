extern "C" bool fn_27_1DA5C4(void* object);

// Recover the complete fighter from its secondary interface.
extern "C" bool fn_99_10D0C(void* object) {
    return fn_27_1DA5C4(static_cast<unsigned char*>(object) - 0x88);
}
