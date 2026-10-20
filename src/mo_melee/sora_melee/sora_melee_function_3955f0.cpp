#pragma force_active on
typedef int s32;

struct fn_27_Obj {
    char pad[0x18];
    s32 m_18;
};

extern "C" void* fn_27_3955F0(fn_27_Obj* p1, s32 unused, s32 p2) {
    return *(void**)((char*)p1 + ((p2 - p1->m_18) << 2) + 0x24);
}
