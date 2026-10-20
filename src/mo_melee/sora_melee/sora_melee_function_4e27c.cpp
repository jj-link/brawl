#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;

struct Obj {
    char pad0[0xf4];
    s32 m_f4;
    char pad1[0x104 - 0xf8];
    u8 m_104;
};

extern "C" void fn_27_4E27C(Obj* obj) {
    obj->m_f4 = -1;
    obj->m_104 = 0;
}
