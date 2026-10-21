#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" {
extern char lbl_8045C768[];

struct fn_800FD650_obj {
    s32 m_0;
    u8 m_4;
    u8 pad5;
    u8 pad6;
    u8 pad7;
    u32 m_8;
    u32 m_c;
    u32 m_10;
    u32 m_14;
    u32 m_18;
    void* m_1c;
};

void fn_800FD650(fn_800FD650_obj* s, u8 arg1, s32 arg2) {
    s->m_1c = (void*)lbl_8045C768;
    s->m_18 = 0x28;
    s->m_c = 0;
    s->m_8 = 0;
    s->m_10 = 0;
    s->m_14 = 0;
    s->m_4 = arg1;
    s->m_0 = arg2;
    s->m_18 = (arg2 == 0) ? 0x28 : 0x2A;
}
}
