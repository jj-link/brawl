#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char* g_GameGlobal;
extern char lbl_2_data_7A8[];
extern const float lbl_2_rodata_98;

u32* fn_2_2FA0(u32* self, u32 arg) {
    u32 z = 0;
    self[0] = z;
    self[2] = z;
    self[4] = arg;
    self[5] = z;
    self[13] = z;
    self[14] = z;
    self[16] = (u32)lbl_2_data_7A8;
    self[21] = 0x270f;
    self[22] = 0x270f;
    self[23] = 0x270f;
    self[24] = z;
    self[25] = z;
    self[15] = z;
    float f = lbl_2_rodata_98;
    *(float*)(*(char**)(g_GameGlobal + 0x44) + 0x4) = f;
    *(float*)(*(char**)(g_GameGlobal + 0x44) + 0x8) = f;
    return self;
}
}
