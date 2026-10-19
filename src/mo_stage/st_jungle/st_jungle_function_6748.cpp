#pragma force_active on
extern "C" char* fn_51_6748(int* self, int index) {
    int i = (self[2] >> 30) + index;
    if (i >= 1) {
        i -= 1;
    }
    return (char*)self + i * 0x90 + 0xc;
}
