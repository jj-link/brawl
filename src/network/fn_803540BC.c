extern void fn_80335638(int, const char *, ...);
extern char lbl_8048DBD0[];
extern void *lbl_805A0FD4;
extern int lbl_805A0FD8;

#pragma force_active on
void fn_803540BC(void) {
    fn_80335638(0x01000000, lbl_8048DBD0);
    ((void (*)(int, void *, int))(*(int *)((char *)lbl_805A0FD4 + 0x5b34)))(0, lbl_805A0FD4, 0);
    lbl_805A0FD4 = 0;
    lbl_805A0FD8 = 0x19;
}
