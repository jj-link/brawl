#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_8007E99C(void*);
extern "C" void fn_8007EC08(void*, void*, int, int, int);
extern "C" int fn_8007ED14(void*);
extern "C" int fn_8007EF68(void*);
extern "C" void fn_8007ED30(void*);
extern "C" int fn_8007EDA0(void*);
extern "C" void fn_8007EDE8(void*);
extern "C" void fn_8007EE24(void*);
extern "C" int fn_8007EEAC(void*);
extern "C" void fn_8007EEFC(void*);
extern "C" void fn_8007F15C(void*, unsigned int);
extern "C" int fn_8007EF64(void*);
extern "C" void fn_8007EF48(void*, void*, void*);

struct Obj {
    char pad0_40[0x40];
    int m40;
    char pad44_48[4];
    void* m48;
    char pad4C_50[4];
    int m50;
    void* m54;
    char pad58_60[8];
    int m60;
    int m64;
};

extern "C" void fn_40_3DB3C(Obj* self) {
    switch (self->m40) {
    case 1:
        if (self->m54 != 0) {
            void* p = __nw__FUlQ25Heaps8HeapType(1, 0x2a);
            if (p != 0) {
                p = fn_8007E99C(p);
            }
            self->m48 = p;
            fn_8007EC08(p, self->m54, 0, 1, 0);
            self->m40 = 2;
        }
        break;
    case 2:
        if (fn_8007ED14(self->m48)) {
            self->m50 = fn_8007EF68(self->m48);
            fn_8007ED30(self->m48);
            self->m40 = 3;
        }
        break;
    case 3:
        if (fn_8007EDA0(self->m48)) {
            fn_8007EDE8(self->m48);
            fn_8007EE24(self->m48);
            self->m40 = 4;
        }
        break;
    case 4:
        if (fn_8007EEAC(self->m48)) {
            fn_8007EEFC(self->m48);
            fn_8007F15C(self->m48, 0);
            self->m40 = 5;
        }
        break;
    case 5:
        if (fn_8007EF64(self->m48) == 1) {
            fn_8007EF48(self->m48, &self->m60, &self->m64);
            self->m40 = 6;
        }
        break;
    case 6:
    case 7:
        break;
    }
}
