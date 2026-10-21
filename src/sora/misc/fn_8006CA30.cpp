#pragma force_active on
extern "C" {
extern unsigned char lbl_80497DA4[0x28];
extern int lbl_805A0170;
void fn_8015E680(void* self, int arg);
}

extern "C" void fn_8006CA30(int arg0) {
    fn_8015E680(lbl_80497DA4, arg0);
    lbl_805A0170 = 0;
}
