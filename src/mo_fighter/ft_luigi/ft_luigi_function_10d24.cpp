extern "C" bool fn_27_1DA56C(void* object);

// Recover the complete fighter from its secondary interface.
extern "C" bool fn_99_10D24(void* object) {
    return fn_27_1DA56C(static_cast<unsigned char*>(object) - 0x88);
}
