#pragma force_active on
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern const f32 lbl_27_rodata_EC0;

struct SoraMeleeObj {
    u32 m_00;
    u32 m_04;
    f32 m_08;
    f32 m_0c;
    f32 m_10;
    u32 m_14;
    u8 m_18;
    u8 m_19;
    u8 m_1a;
    s16 m_1c;
};

extern "C" void fn_27_C1A30(SoraMeleeObj* p, u8 a, u32 b)
{
    p->m_00 = 0;
    p->m_04 = b;
    p->m_14 = 0xFFFF;
    p->m_18 = a;
    p->m_19 = 2;
    p->m_1a = 0;
    p->m_08 = lbl_27_rodata_EC0;
    p->m_1c = -1;
    p->m_10 = lbl_27_rodata_EC0;
    p->m_0c = lbl_27_rodata_EC0;
}
