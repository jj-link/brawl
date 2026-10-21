#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void fn_8009E3D0(void* p);

struct Obj {
    u8 _pad[0x44];
    u8 m_hi : 4;
    u8 m_bit : 1;
    u8 m_lo : 3;
};

extern "C" void fn_8009C968(Obj* self, s32 flag) {
    if (flag != 0) {
        fn_8009E3D0((u8*)self + 0x194);
    }
    self->m_bit = flag;
}
