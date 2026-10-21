#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern void fn_8034E738(int, int);
extern const char lbl_8048AA34[];

void fn_8033C018(int arg0, int arg1) {
    fn_80335638(0x100, lbl_8048AA34, arg1);
    fn_8034E738(arg0, arg1);
}
