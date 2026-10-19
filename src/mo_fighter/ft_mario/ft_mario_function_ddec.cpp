#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_91_70(void*, int, int, int, int);
extern unsigned char lbl_91_data_1B4[];
}

extern "C" void* fn_91_DDEC(void*, int a, int b, int c, int d) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x2DBE8, b);
    if (obj != 0) {
        unsigned char* p = static_cast<unsigned char*>(obj);
        fn_91_70(obj, a, b, c, d);
        unsigned char* base = lbl_91_data_1B4;
        *reinterpret_cast<unsigned char**>(p + 0x3c) = base;
        *reinterpret_cast<unsigned char**>(p + 0x40) = base + 0x64;
        *reinterpret_cast<unsigned char**>(p + 0x48) = base + 0x70;
        *reinterpret_cast<unsigned char**>(p + 0x54) = base + 0x84;
        *reinterpret_cast<unsigned char**>(p + 0x64) = base + 0xdc;
        *reinterpret_cast<unsigned char**>(p + 0x70) = base + 0xec;
        *reinterpret_cast<unsigned char**>(p + 0x7c) = base + 0xfc;
        *reinterpret_cast<unsigned char**>(p + 0x88) = base + 0x110;
        *reinterpret_cast<unsigned char**>(p + 0x94) = base + 0x128;
        *reinterpret_cast<unsigned char**>(p + 0xa0) = base + 0x140;
        *reinterpret_cast<unsigned char**>(p + 0xac) = base + 0x158;
        *reinterpret_cast<unsigned char**>(p + 0xb8) = base + 0x16c;
        *reinterpret_cast<unsigned char**>(p + 0xc4) = base + 0x180;
        *reinterpret_cast<unsigned char**>(p + 0xd0) = base + 0x190;
        *reinterpret_cast<unsigned char**>(p + 0xdc) = base + 0x1c4;
        *reinterpret_cast<unsigned char**>(p + 0xe8) = base + 0x1d4;
        *reinterpret_cast<unsigned char**>(p + 0xf4) = base + 0x1e8;
        *reinterpret_cast<unsigned char**>(p + 0x100) = base + 0x254;
    }
    return obj;
}
