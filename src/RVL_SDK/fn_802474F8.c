#pragma force_active on
extern void fn_802471C8(void*);
extern void* memcpy(void*, const void*, unsigned int);
extern char lbl_8052C870[];

void fn_802474F8(void) {
    memcpy(lbl_8052C870 + 0x70, lbl_8052C870 + 0x56, 0xA);
    fn_802471C8(lbl_8052C870 + 0x56);
    lbl_8052C870[0x6F] = 1;
}
