extern "C" bool fn_27_1DA5E0(void* object);

// Recover the complete fighter from its secondary interface (duplicate adapter entry).
extern "C" bool fn_99_10D5C(void* object) {
    return fn_27_1DA5E0(static_cast<unsigned char*>(object) - 0x88);
}
