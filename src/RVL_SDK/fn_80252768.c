#pragma force_active on
extern unsigned char lbl_8052D5A8[];

void fn_80252768(void* val, int idx) {
    ((void**)(lbl_8052D5A8 + 0x3c))[idx - 0x40] = val;
}
