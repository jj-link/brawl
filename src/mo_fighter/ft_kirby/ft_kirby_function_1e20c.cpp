#pragma force_active on
extern "C" void* fn_96_1E20C(int* self, int idx) {
    int i = (self[2] >> 26) + idx;
    if (i >= 24) {
        i -= 24;
    }
    return (char*)self + (i << 2) + 12;
}
