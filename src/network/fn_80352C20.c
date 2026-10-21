#pragma force_active on
extern void *lbl_805A0FD4;

void fn_80352C20(int arg0) {
    *(int *)((char *)lbl_805A0FD4 + 0x59D8) = 1;
    *(int *)((char *)lbl_805A0FD4 + 0x59DC) = arg0;
}
