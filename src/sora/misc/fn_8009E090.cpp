#pragma force_active on

struct Obj {
    float x, y, z, w;
    unsigned char pad10[0x22C - 0x10];
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234[4];
    float unk244[5];
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_8009D468(Obj* p);
extern "C" Obj* lbl_805A0280;
extern "C" const float lbl_805A1DC8;

inline void zeroRange(int* begin, int* end) {
    int* p = begin;
    do { *p = 0; ++p; } while (p < end);
}

extern "C" void fn_8009E090(float farg0) {
    if (lbl_805A0280 == 0) {
        Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x274, 1);
        if (obj != 0) {
            obj->unk22C = 0;
            zeroRange((int*)&obj->unk230, (int*)obj->unk244);
            fn_8009D468(obj);
            obj->unk244[0] = lbl_805A1DC8;
            obj->unk244[1] = lbl_805A1DC8;
            obj->unk244[2] = lbl_805A1DC8;
            obj->unk244[3] = lbl_805A1DC8;
            obj->unk244[4] = lbl_805A1DC8;
        }
        lbl_805A0280 = obj;
    }
    lbl_805A0280->z = lbl_805A0280->w * farg0;
}