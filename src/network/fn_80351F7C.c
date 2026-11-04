#pragma force_active on
extern void fn_80335638(int level, const char *fmt, ...);
extern void fn_80351D30(void *arg0, void *arg1);
extern char lbl_8048D2F0[];

void fn_80351F7C(char *arg0) {
    fn_80335638(-1, &lbl_8048D2F0[0x9C]);
    fn_80335638(-1, &lbl_8048D2F0[0xC0]);
    fn_80351D30(arg0, arg0 + 4);
    fn_80335638(-1, &lbl_8048D2F0[0xD4]);
    fn_80335638(-1, &lbl_8048D2F0[0xF8]);
    fn_80351D30(arg0, arg0 + 0x10);
    fn_80335638(-1, &lbl_8048D2F0[0xD4]);
    fn_80335638(-1, &lbl_8048D2F0[0x60], *(int*)(arg0 + 0x1C));
    fn_80335638(-1, &lbl_8048D2F0[0x9C]);
}
