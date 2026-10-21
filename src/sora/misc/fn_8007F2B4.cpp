#pragma force_active on
extern int lbl_805A0250;
extern int lbl_805A0254;
extern int lbl_805A0258;

extern "C" void fn_8007F2B4(int a, int b, int c) {
    lbl_805A0250 = b;
    lbl_805A0254 = c;
    lbl_805A0258 = 0;
}
