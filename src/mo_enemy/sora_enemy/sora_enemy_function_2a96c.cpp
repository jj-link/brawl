#pragma force_active on
typedef unsigned char u8;

struct Flags34 {
    u8 f : 3;
    u8 r : 5;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
void fn_41_51C4(void*, void*);
extern float lbl_41_rodata_DC0;
}

extern "C" void fn_41_2A96C(char* self) {
    Flags34* fl = (Flags34*)(self + 0x34);
    if (fl->f) {
        char* inner = *(char**)(*(char**)(self + 0x1C) + 0x8);
        void* obj = __dynamic_cast(inner, 0x3C, __RTTI__5Enemy, __RTTI__11StageObject, 1);
        fn_41_51C4(obj, *(void**)(self + 0x48));
    }
    fl->f = 0;
    float z = lbl_41_rodata_DC0;
    *(float*)(self + 0x30) = z;
    *(float*)(self + 0x2C) = z;
}
