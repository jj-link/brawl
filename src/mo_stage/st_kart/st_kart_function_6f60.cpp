#pragma force_active on
extern "C" void* fn_49_6F60(int* self, int index) {
    int i = (self[2] >> 28) + index;
    if (i >= 7) {
        i -= 7;
    }
    return (char*)self + i * 8 + 0xc;
}
