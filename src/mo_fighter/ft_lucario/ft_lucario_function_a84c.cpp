#pragma force_active on
extern "C" int fn_118_A840();

extern "C" int fn_118_A84C(unsigned char* self, int unused, int i, int j) {
    int off = fn_118_A840() * 0x1c;
    int* table = *(int**)(off + (self - 0x10000) + i * 4 - 0x7548);
    return table[j];
}
