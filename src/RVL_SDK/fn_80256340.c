#pragma force_active on
typedef unsigned char u8;

extern u8 lbl_8052D5A8[];
extern char lbl_80484B18[];
extern void fn_802319FC(int, const char *, int);
extern void fn_80231FB0(void *, int, int);

void fn_80256340(u8 *arg0, int arg1)
{
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319FC(0x90003, lbl_80484B18, arg1);
    }
    *(void **)(arg0 + 0x10) = arg0;
    fn_80231FB0(arg0, 0xB, arg1);
}