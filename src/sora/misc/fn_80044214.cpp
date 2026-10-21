#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_80044214(u32* p) {
    u32* q = p;
    u32 i = 0;
    for (; i < ((((*p) + 1) >> 5) + 1); i++) {
        *++q = 0;
    }
}
