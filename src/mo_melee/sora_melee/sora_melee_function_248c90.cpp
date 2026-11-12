#pragma force_active on
#include <types.h>
#include <ip/ip_switch.h>
struct Self {
    char pad[0x3c]; char* f3c; u8 f40; char pad4[3]; void* f44;
    char pad_48[0x84]; int fcc; u8 bytes_d0[16]; int fe0, fe4, fe8; float fec;
    char pad_ec[8]; int ff8, ffc, f100, f104; int arr[6][7]; int f1b0, f1b4;
    char pad_b[0x24]; int f1dc; char pad_e0; u8 f1e1; char pad_e2[2];
    int f1e4, f1e8; char pad_f[0x38]; u8 f224, f225, f226; char pad_227;
    int f228, f22c, f230; u8 f234, f235; char pad_236[10]; int f240, f244;
    u8 f248; char pad_249[3]; int f24c, f250; char pad_254[4]; u8 f258;
};
struct GameGlobal { int pad[6]; int f18; };
extern "C" void fn_27_247D98(void*);
extern "C" void fn_8004B780(void*, void*);
extern "C" char lbl_27_data_4F290[];
extern "C" u8 lbl_27_bss_59A0[];
extern "C" int lbl_27_bss_59A8;
extern "C" int lbl_27_data_4F050;
extern "C" const float lbl_27_rodata_4028;
extern "C" GameGlobal* g_GameGlobal;
extern "C" Self* fn_27_248C90(Self* self, int arg1) {
    int one = 1;
    int four = 4;
    fn_27_247D98(self);
    float fl = lbl_27_rodata_4028;
    self->f3c = lbl_27_data_4F290;
    self->bytes_d0[0] = 0;
    self->bytes_d0[1] = 0;
    self->bytes_d0[2] = 0;
    self->bytes_d0[3] = 0;
    self->bytes_d0[4] = 0;
    self->bytes_d0[5] = 0;
    self->bytes_d0[6] = 0;
    self->bytes_d0[7] = one;
    self->bytes_d0[8] = 0;
    self->bytes_d0[9] = 0;
    self->bytes_d0[10] = 0;
    self->bytes_d0[11] = 0;
    self->bytes_d0[12] = 0;
    self->bytes_d0[13] = 0;
    self->bytes_d0[14] = 0;
    self->bytes_d0[15] = 0;
    self->fe0 = 0;
    self->fe4 = 0;
    self->fe8 = 0;
    self->fec = fl;
    self->ff8 = 0;
    self->ffc = 0;
    self->f100 = one;
    self->f104 = four;
    self->f1b4 = one;
    self->f1dc = 0;
    self->f1e1 = 0;
    self->f1e4 = 0;
    self->f1e8 = 0;
    self->f224 = (u8)arg1;
    self->f225 = 0;
    self->f226 = 0;
    self->f228 = 12;
    self->f22c = 0;
    self->f230 = 0;
    self->f234 = 0;
    self->f235 = one;
    self->f240 = lbl_27_data_4F050;
    self->f244 = 0;
    self->f248 = one;
    self->f24c = lbl_27_data_4F050;
    self->f250 = 0;
    self->f258 = 0;
    lbl_27_bss_59A8 = 0;
    if (ipSwitch::getInstance() != 0) {
        if (ipSwitch::getInstance()->m_keyRecorder != 0) {
            lbl_27_bss_59A0[4] = 0;
            lbl_27_bss_59A0[5] = 0;
            *(u16*)(lbl_27_bss_59A0 + 6) = 0;
            fn_8004B780(ipSwitch::getInstance()->m_keyRecorder, lbl_27_bss_59A0);
        }
    }
    self->f40 = 0;
    int v22b8 = 0x22b8;
    int constA = 0xff439eb2;
    for (int i = 0; i < 7; i++) {
        self->arr[0][i] = 0;
        self->arr[1][i] = 0;
        self->arr[2][i] = v22b8;
        self->arr[3][i] = 0;
        self->arr[4][i] = 0;
        self->arr[5][i] = constA;
    }
    self->f1b0 = constA;
    self->fcc = g_GameGlobal->f18;
    unsigned int key = ((u8)((u8*)self->f44)[8] >> 2) & 0x3F;
    switch (key) {
    case 3: break;
    case 5: self->bytes_d0[7] = 0;
    case 4: self->bytes_d0[3] = one; self->bytes_d0[6] = one; break;
    case 7:
        if (((u8*)self->f44)[0x14] == 4) { self->f100 = 3; self->f1b4 = 4; }
        self->bytes_d0[13] = one; break;
    case 14: self->f226 = one; break;
    case 24: self->f226 = one; self->f225 = one; break;
    case 28: self->f226 = one; self->f225 = one; break;
    case 8: case 9: case 10: self->bytes_d0[11] = one; self->bytes_d0[13] = one; break;
    case 16: case 18: self->f226 = one; self->bytes_d0[11] = one; self->bytes_d0[13] = one; break;
    default: break;
    }
    u8 c = ((u8*)self->f44)[0x14];
    if (c >= 5 && c <= 0xa) { self->f104 = 7; self->f1e1 = one; }
    return self;
}