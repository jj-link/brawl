#pragma force_active on
extern "C" char* lbl_27_bss_5668;

class Obj {};

struct PtmfTable {
    void (Obj::*e[15])();
};

extern "C" const PtmfTable lbl_27_rodata_41B8;

inline char* getObj() {
    char* p = lbl_27_bss_5668;
    if (p != 0 && *(int*)(p + 0x44) == 0x3d) {
        return p;
    }
    return 0;
}

extern "C" void fn_27_25BE08(Obj* self) {
    char* p = getObj();
    if (p != 0) {
        PtmfTable t = lbl_27_rodata_41B8;
        (self->*t.e[*(int*)((char*)self + 0x48)])();
    }
}
