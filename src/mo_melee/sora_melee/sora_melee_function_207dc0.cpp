#pragma force_active on
extern "C" void gfMemFill__FPvUcUl(void*, unsigned char, unsigned long);
extern "C" {
extern const float lbl_27_rodata_2F68;
extern const float lbl_27_rodata_2F6C;
extern char* g_aiMgr;
}
extern "C" void fn_27_207DC0(char* p, int a, int b, int c, signed char d) {
    gfMemFill__FPvUcUl(p, 0, 0x1c4);
    if (a < 0 || b == -1 || c == 0) {
        p[0] = -1;
        *(int*)(p+0xac) = -1;
        *(int*)(p+0x4c) = 0;
    } else {
        p[0] = a;
        *(int*)(p+0xac) = b;
        *(int*)(p+0x4c) = c;
    }
    *(int*)(p+0xb0) = -1;
    p[1] = d;
    *(int*)(p+0x50) = 0x8000;
    *(int*)(p+0x54) = 0;
    *(int*)(p+0xd8) = -1;
    *(int*)(p+0xe0) = 0;
    p[3] = -1;
    p[0x1b9] = 0;
    p[0x1bb] = 0;
    *(short*)(p+0xaa) = 0;
    p[2] = 0;
    *(int*)(p+8) = 0;
    *(int*)(p+0x58) = 0;
    *(float*)(p+0x74) = lbl_27_rodata_2F68;
    *(float*)(p+0x78) = lbl_27_rodata_2F68;
    *(float*)(p+0x7c) = lbl_27_rodata_2F68;
    *(float*)(p+0x5c) = lbl_27_rodata_2F68;
    *(float*)(p+0x60) = lbl_27_rodata_2F68;
    *(float*)(p+0x64) = lbl_27_rodata_2F68;
    *(float*)(p+0x68) = lbl_27_rodata_2F6C;
    *(float*)(p+0x6c) = lbl_27_rodata_2F6C;
    *(float*)(p+0x70) = lbl_27_rodata_2F6C;
    *(float*)(p+0x88) = lbl_27_rodata_2F68;
    *(float*)(p+0x8c) = lbl_27_rodata_2F68;
    *(float*)(p+0x80) = lbl_27_rodata_2F68;
    *(float*)(p+0x84) = lbl_27_rodata_2F68;
    *(float*)(p+0x98) = lbl_27_rodata_2F68;
    *(float*)(p+0x9c) = lbl_27_rodata_2F68;
    *(float*)(p+0x90) = lbl_27_rodata_2F68;
    *(float*)(p+0x94) = lbl_27_rodata_2F68;
    *(float*)(p+0xa0) = lbl_27_rodata_2F6C;
    *(float*)(p+0xa4) = lbl_27_rodata_2F68;
    *(short*)(p+0xa8) = 0;
    *(int*)(p+0xb8) = 0;
    *(int*)(p+0xb4) = 0;
    float a0[3]; *(float*)((char*)a0+0) = lbl_27_rodata_2F68; *(float*)((char*)a0+4) = lbl_27_rodata_2F68; *(float*)((char*)a0+8) = lbl_27_rodata_2F68;
    *(char**)(p+0xbc) = g_aiMgr + 0xac;
    *(float*)(p+0xc4) = lbl_27_rodata_2F68;
    *(int*)(p+0xcc) = -1;
    *(int*)(p+0xc8) = -1;
    *(int*)(p+0xd0) = 0;
    *(int*)(p+0xd4) = 0;
    *(float*)(p+0xdc) = lbl_27_rodata_2F68;
    p[4] = 0;
    p[0x1bd] = 0;
    p[0x1bc] = 0;
    float a1[3]; *(float*)((char*)a1+0) = lbl_27_rodata_2F6C; *(float*)((char*)a1+4) = lbl_27_rodata_2F6C; *(float*)((char*)a1+8) = lbl_27_rodata_2F6C;
    float a2[2]; *(float*)((char*)a2+0) = lbl_27_rodata_2F68; *(float*)((char*)a2+4) = lbl_27_rodata_2F68;
    float a3[2]; *(float*)((char*)a3+0) = lbl_27_rodata_2F68; *(float*)((char*)a3+4) = lbl_27_rodata_2F68;
}