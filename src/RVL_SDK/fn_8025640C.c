#pragma force_active on
extern unsigned char lbl_8052D5A8[];
extern const char lbl_80484B38[];
extern void fn_802319FC(int, const char *, int);
extern void fn_80231FB0(void *, int, int);

void fn_8025640C(void *arg0, int arg1)
{
    char *temp_r31;

    temp_r31 = (char *)arg0 + 0x70;
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319FC(0x90003, lbl_80484B38, arg1);
    }
    *(void **)(temp_r31 + 0x10) = arg0;
    fn_80231FB0(temp_r31, 0xC, arg1);
}
