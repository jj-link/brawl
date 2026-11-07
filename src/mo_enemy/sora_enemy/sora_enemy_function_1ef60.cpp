#pragma force_active on
extern "C" int fn_41_1AE30(int);
extern "C" float fn_41_1AFD8(int, float, int);
extern "C" float lbl_41_rodata_C90[];

extern "C" void fn_41_1EF60(void* self, float farg0) {
    const float* t = lbl_41_rodata_C90;
    char* p = (char*)self;
    float v = farg0;
    if (fn_41_1AE30(*(int*)(p + 0x8)) != 1 && t[7] != v && t[29] != v) {
        if (t[30] == v || t[31] == v || t[32] == v ||
            t[33] == v || t[34] == v || t[35] == v) {
            v = fn_41_1AFD8(*(int*)(p + 0x8), v, *(int*)(p + 0x8c));
        }
        if (t[11] == v) {
            v = t[3];
            *(unsigned char*)(p + 0xb0) = 1;
        }
        *(float*)(p + 0x5c) = v;
        *(float*)(p + 0x6c) = v;
    }
}
