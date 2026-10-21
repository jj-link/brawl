#pragma force_active on
extern void fn_8023D6CC(int a, int b, int c, int d);
extern void fn_80240728(int a, int b, int c);

void fn_8023D824(void) {
    fn_8023D6CC(0, 0, 0, 0x1F);
    fn_80240728(0, 0, 0x1F);
}
