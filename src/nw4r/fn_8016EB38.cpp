#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern "C" {
void fn_8015BFB4(void *a, void *b);
void fn_8016E7D8(void *a, s32 b, void *c);
void *memset(void *p, int c, unsigned long n);

void *fn_8016EB38(void *arg0, void *arg1) {
    u8 *temp_r31;
    s32 temp_r4;
    u8 *temp_r5;

    arg1 = (u8 *)arg1 + *(u16 *)((u8 *)arg1 + 0xc);
    temp_r31 = (u8 *)arg1 + 8;
    memset(temp_r31 + 4, 0, 8);
    fn_8015BFB4((u8 *)arg0 + 0x10, temp_r31);
    temp_r4 = *(s32 *)((u8 *)arg0 + 0x1c);
    temp_r5 = temp_r31 + *(u32 *)temp_r31;
    *(s32 *)((u8 *)arg0 + 0x1c) = temp_r4 + *(u16 *)(temp_r5 + 4);
    fn_8016E7D8(temp_r31, temp_r4, temp_r5);
    return temp_r31;
}
}
