#pragma force_active on

extern "C" {
extern char lbl_80454FD0[0x10];
extern const float lbl_805A2150;
extern const float lbl_805A2154;

struct Flags {
    unsigned char a : 2;
    unsigned char b : 6;
};

void fn_800A9DCC(char *arg0)
{
    *(int *)(arg0 + 0x00) = 0;
    *(char **)(arg0 + 0x04) = lbl_80454FD0;
    *(int *)(arg0 + 0x08) = 0;
    *(short *)(arg0 + 0x0C) = 0;
    *(short *)(arg0 + 0x0E) = 0;
    ((Flags *)(arg0 + 0x11))->a = 0;
    *(float *)(arg0 + 0x14) = lbl_805A2150;
    *(float *)(arg0 + 0x54) = lbl_805A2154;
}
}
