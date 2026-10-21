#pragma force_active on
extern unsigned char lbl_80532448[0x18];

void fn_8027FF58(void) {
    *(int*)(&lbl_80532448[0x00]) = 0;
    *(char*)(&lbl_80532448[0x10]) = 0;
    *(int*)(&lbl_80532448[0x08]) = 0;
    *(int*)(&lbl_80532448[0x04]) = 0;
    *(int*)(&lbl_80532448[0x0C]) = 0;
}
