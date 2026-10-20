#pragma force_active on
typedef unsigned char u8;

struct Inner {
    u8 m_pad[0x71];
    u8 m_flag : 1;
    u8 m_rest : 7;
};

extern "C" void fn_27_2EFF0(u8* self) {
    Inner* inner = *(Inner**)(self + 4);
    if (inner != 0) {
        inner->m_flag = 0;
    }
}
