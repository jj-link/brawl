#pragma force_active on
typedef int s32;

struct fn27Table {
    char pad0[0x18];
    s32 m_18;
};

extern "C" s32 fn_27_3600F0(fn27Table* self, s32 unused, s32 idx) {
    return ((s32*)((char*)self + 0x48))[idx - self->m_18];
}
