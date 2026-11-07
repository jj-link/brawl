#include <revolution/GX/GXHardware.h>
#pragma force_active on

extern "C" {
void GXSetZMode(int, int, int);
void fn_801F0530(void);
void fn_801F08D8(unsigned short);
void fn_801F1524(int, int, unsigned short, unsigned short);
void fn_801F15A4(unsigned short, unsigned short);
void fn_801F16E4(int);
void fn_801F19E8(float);
void fn_801F1AB4(unsigned char*, int);
void fn_801F1B2C(int, int, int, int);
void fn_801F1D10(int);
void fn_801F1D24(int, int);
void fn_801F471C(int);
void fn_801F4748(int);
extern int lbl_805A0098;
extern float lbl_805A14C8;
}

struct Obj {
    char pad0[0x2];
    unsigned short y;
    unsigned short x;
    char pad1[0x7 - 0x4];
    unsigned char state;
    char pad2[0x0];
};

extern "C" void fn_80023ECC(unsigned char* arg0) {
    unsigned char buf[4];
    int temp_r31;

    temp_r31 = lbl_805A0098;
    fn_801F1B2C(0, temp_r31 + 0x1A, 1, temp_r31 + 0x32);
    fn_801F16E4(0);
    fn_801F19E8(*(float*)(arg0 + 0x3C));
    fn_801F1524(0, 0, *(unsigned short*)(arg0 + 0x34), *(unsigned short*)(arg0 + 0x36));
    fn_801F15A4(*(unsigned short*)(arg0 + 0x2), *(unsigned short*)(arg0 + 0x0));
    fn_801F1D10(0);
    buf[0] = arg0[0x2C];
    buf[1] = arg0[0x2D];
    buf[2] = arg0[0x2E];
    buf[3] = arg0[0x2F];
    fn_801F1AB4(buf, *(int*)(arg0 + 0x30));
    if ((arg0[0x74] >> 7) & 1) {
        fn_801F471C(1);
    } else {
        fn_801F471C(0);
    }
    if ((arg0[0x74] >> 6) & 1) {
        GXSetZMode(0, 7, 1);
    } else {
        GXSetZMode(0, 7, 0);
    }
    fn_801F4748(1);
    if (arg0[0x7] == 0xF0) {
        arg0[0x7] = 0;
    }
    fn_801F1D24(*(int*)(arg0 + (arg0[0x7] << 3) + 0x10), 1);
    fn_801F1B2C(0, temp_r31 + 0x1A, 0, temp_r31 + 0x32);
    fn_801F19E8(lbl_805A14C8);
    fn_801F08D8(0xFFF0);
    fn_801F0530();
}
