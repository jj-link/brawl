#pragma force_active on
extern unsigned char lbl_805A3AA0[8];
extern unsigned char lbl_80529994[];
void fn_8024ADB0(const void *arg0, unsigned short arg1);
void fn_80232530(void);
void fn_8023BDCC(unsigned char a, int b, int c);
void fn_8023C248(unsigned char a, int b, int c);
void fn_80235134(void);
unsigned short fn_80238E0C(void);
void fn_802324FC(void *a, int b, int c);
void fn_802344F4(void);
void fn_80232984(void);

void fn_802328D4(void) {
    fn_8024ADB0(lbl_805A3AA0, 0);
    fn_80232530();
    fn_8023BDCC(0, 0, 0);
    fn_8023C248(0, 0, 0);
    fn_80235134();
    if (fn_80238E0C() == 0) {
        *(void (**)(void))(lbl_80529994 + 0x7C) = fn_802344F4;
        fn_802324FC(lbl_80529994 + 0x74, 0, 0x3E8);
        return;
    }
    lbl_80529994[0x72] = 1;
    *(void (**)(void))(lbl_80529994 + 0x7C) = fn_80232984;
    fn_802324FC(lbl_80529994 + 0x74, 0, 0x1388);
}
