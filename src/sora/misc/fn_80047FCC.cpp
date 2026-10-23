#pragma force_active on
typedef int s32;

extern "C" void* fn_801B32C8(
    void*, void*, s32*, s32, s32, s32, s32, s32,
    s32, s32, s32, s32, s32);
extern "C" char lbl_8042B6C8[];

inline void* operator new(unsigned long, void* p) {
    return p;
}

struct Obj {
    void* vtable;

    Obj(void* a1, s32* a2, s32 a3, s32 a4, s32 a5,
        s32 a6, s32 a7, s32 a8, s32 a9, s32 a10,
        s32 a11, s32 a12) {
        s32 copy = *a2;
        fn_801B32C8(this, a1, &copy, a3, a4, a5, a6, a7,
                    a8, a9, a10, a11, a12);
        vtable = lbl_8042B6C8;
    }
};

extern "C" Obj* fn_80047FCC(
    Obj* self, void* a1, s32* a2, s32 a3, s32 a4,
    s32 a5, s32 a6, s32 a7, s32 a8, s32 a9,
    s32 a10, s32 a11, s32 a12) {
    return new(self) Obj(a1, a2, a3, a4, a5, a6, a7,
                         a8, a9, a10, a11, a12);
}
