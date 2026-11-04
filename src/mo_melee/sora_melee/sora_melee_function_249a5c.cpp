#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
struct gfApplication { u8 pad[0xF8]; u16 m_frameRate; };
extern gfApplication* g_gfApplication;
extern float lbl_27_rodata_4038;
struct SubObj {
    u8 pad[0xF];
    u8 flag0 : 1;
    u8 flag1 : 1;
    u8 flag2 : 1;
    u8 flag3 : 1;
    u8 flag4 : 1;
    u8 flag5 : 1;
    u8 flag6 : 1;
    u8 flag7 : 1;
};
struct Obj {
    u8 pad0[0x44];
    SubObj* unk44;
    u8 pad1[0x8D];
    s8 unkD5;
    u8 pad2[9];
    u8 unkDF;
    u8 pad3[0x14];
    float unkF4;
};
extern "C" void fn_27_247EBC(Obj*);
extern "C" void fn_27_249A5C(Obj* self) {
    fn_27_247EBC(self);
    self->unkDF = 1;
    self->unkF4 = lbl_27_rodata_4038 / (float)g_gfApplication->m_frameRate;
    self->unkD5 = self->unk44->flag4 == 0;
}
