#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

struct FieldHolder {
    u32 pad[2];
    u32 flags;
};

extern "C" s32 fn_27_1E7CFC(FieldHolder* p) {
    return (s32)((p->flags << 4) & 0xE0000000) >> 30;
}
