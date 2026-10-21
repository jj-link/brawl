#pragma force_active on
extern "C" void fn_801C07F8(int, int, int, int);

extern "C" int fn_801C6164(int a, int b, int c, int d) {
    fn_801C07F8(a + 8, c, d, 0x18);
    return 1;
}
