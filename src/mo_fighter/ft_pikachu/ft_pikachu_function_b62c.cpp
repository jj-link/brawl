#pragma force_active on
// Three-way dispatch on the index: 2, 1, 0 map to fixed offsets; anything else returns null.
extern "C" void* fn_98_B62C(char* pool, int index) {
    if (index == 2) return pool + 0x3fa4;
    if (index == 1) return pool + 0x1fdc;
    if (index == 0) return pool + 0x14;
    return 0;
}
