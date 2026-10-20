#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct fn27Obj {
    u32* m_0;
};

extern "C" {
u32 fn_27_111A68(fn27Obj* p1, u32 p2) {
    return *(u32*)((u8*)(p1->m_0 + p2) + 0x38);
}
}
