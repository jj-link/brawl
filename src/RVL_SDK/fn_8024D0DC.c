#pragma force_active on
extern char lbl_8052CDC0[];

void fn_8024D0DC(short x) {
    *(short*)(lbl_8052CDC0 + 0x2) = x;
    *(short*)(lbl_8052CDC0 + 0x4) = x;
}
