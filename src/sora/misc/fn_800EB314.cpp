#pragma force_active on

#include <types.h>

extern "C" {
void OSReport(const char*, ...);
unsigned int __cvt_fp2unsigned(float);
extern void* g_GameGlobal;
}

extern const float lbl_805A248C;
extern const float lbl_805A2500;
extern const float lbl_805A2504;
extern const float lbl_805A2508;
extern char lbl_8045A428[];

extern "C" void fn_800EB314(void) {
    char* elem;
    char* str = lbl_8045A428;
    int offset = 0;
    int i = 0;

    do {
        elem = *(char**)((char*)g_GameGlobal + 0x18) + offset;
        if (*(u8*)(elem + 0x25) != 3) {
            OSReport(str + 0xA04, i);
            OSReport(str + 0xA38, *(u32*)(elem + 0x200));
            OSReport(str + 0xA50, *(float*)(elem + 0x2C8));
            OSReport(str + 0xA6C, *(float*)(elem + 0x2CC));

            u32 v = __cvt_fp2unsigned(
                lbl_805A248C * (float)*(u32*)(elem + 0x200) / lbl_805A2500);
            *(u32*)(elem + 0x200) = v;

            *(float*)(elem + 0x2C8) = lbl_805A248C * *(float*)(elem + 0x2C8) *
                                      lbl_805A2504 * lbl_805A2504 * lbl_805A2504 /
                                      lbl_805A2508;
            *(float*)(elem + 0x2CC) = lbl_805A248C * *(float*)(elem + 0x2CC) *
                                      lbl_805A2504 * lbl_805A2504 * lbl_805A2504 /
                                      lbl_805A2508;

            OSReport(str + 0xA88, v);
            OSReport(str + 0xAA0, *(float*)(elem + 0x2C8));
            OSReport(str + 0xAC0, *(float*)(elem + 0x2CC));

            *(u32*)(elem + 0x234) = __cvt_fp2unsigned(*(float*)(elem + 0x2C8));
            *(u32*)(elem + 0x238) = __cvt_fp2unsigned(*(float*)(elem + 0x2CC));

            *(u32*)(elem + 0x204) =
                __cvt_fp2unsigned((float)*(u32*)(elem + 0x204) / lbl_805A2504);
            *(u32*)(elem + 0x208) =
                __cvt_fp2unsigned((float)*(u32*)(elem + 0x208) / lbl_805A2504);
            *(u32*)(elem + 0x20C) =
                __cvt_fp2unsigned((float)*(u32*)(elem + 0x20C) / lbl_805A2504);
            *(u32*)(elem + 0x23C) =
                __cvt_fp2unsigned((float)*(u32*)(elem + 0x23C) / lbl_805A2504);
            *(u32*)(elem + 0x240) =
                __cvt_fp2unsigned((float)*(u32*)(elem + 0x240) / lbl_805A2504);
        }
        i++;
        offset += 0x2AC;
    } while (i < 4);
}
