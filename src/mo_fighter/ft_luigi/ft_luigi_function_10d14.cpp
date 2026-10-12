extern "C" bool fn_27_1DA5A4(void* object);

// Recover the complete fighter from its secondary interface (duplicate adapter entry).
extern "C" bool fn_99_10D14(void* object) {
    return fn_27_1DA5A4(static_cast<unsigned char*>(object) - 0x88);
}
