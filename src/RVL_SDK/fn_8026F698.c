#pragma force_active on
extern void OSRegisterVersion(const char *);
extern void fn_802708AC(int);
extern int lbl_8059EE58;
extern int lbl_805A0E80;

void fn_8026F698(void) {
    OSRegisterVersion((const char *)lbl_8059EE58);
    fn_802708AC(lbl_805A0E80);
}
