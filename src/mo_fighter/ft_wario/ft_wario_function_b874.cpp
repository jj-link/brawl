#pragma force_active on
extern "C" const float lbl_110_rodata_8;
extern "C" const float lbl_110_rodata_C;

struct V2 {
    float x;
    float y;
};

extern "C" V2* fn_110_B860(V2* dst, const V2* src);

extern "C" void fn_110_B874(void* self) {
    char* p = (char*)self;
    V2 a;
    V2 b;
    a.x = lbl_110_rodata_8;
    a.y = lbl_110_rodata_8;
    V2* r = fn_110_B860((V2*)(p + 0x20), &a);
    r = fn_110_B860((V2*)(p + 0x10), r);
    r = fn_110_B860((V2*)(p + 0x08), r);
    b.x = lbl_110_rodata_C;
    b.y = lbl_110_rodata_C;
    r = fn_110_B860((V2*)(p + 0x28), &b);
    r = fn_110_B860((V2*)(p + 0x18), r);
    *(unsigned char*)(p + 0x31) = 0;
    *(unsigned char*)(p + 0x30) = 0;
    *(unsigned char*)(p + 0x32) = 1;
}
