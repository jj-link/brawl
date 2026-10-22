#pragma force_active on
extern void fn_802319FC(int, const char *, int);
extern void fn_802514BC(void *, int, int);
extern unsigned char lbl_80484B80[];
extern unsigned char lbl_8052D5A8[];

void fn_80256790(unsigned char *arg0, int arg1)
{
    unsigned int temp_r6;

    if (*(unsigned char *)(*(unsigned char **)(arg0 + 0x6C) + 0x72) == 2) {
        temp_r6 = *(unsigned short *)(arg0 + 0x98) + arg1;
        *(unsigned short *)(arg0 + 0x98) = temp_r6;
        if (lbl_8052D5A8[0x414] >= 4) {
            fn_802319FC(0x90003, (const char *)lbl_80484B80, (int)(temp_r6 & 0xFFFF));
        }
        if (*(arg0 + 0x24) == 1) {
            fn_802514BC(*(void **)(arg0 + 0x6C), *(arg0 + 0xD), 1);
        }
    }
}
