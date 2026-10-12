extern "C" bool fn_27_1DA4FC(void* object);

// Recover the complete fighter from its secondary interface (duplicate adapter entry).
extern "C" bool fn_99_10D44(void* object) {
    return fn_27_1DA4FC(static_cast<unsigned char*>(object) - 0x88);
}
