#pragma force_active on
extern "C" {
void fn_27_46588(void* buf, int a, int b);
void fn_27_19E6E8(int self, int a, void* buf, int b);
void fn_27_46700(void* buf, short n);
void fn_27_19FC2C(int self, int a, int b);
void fn_27_1994FC(int self, int a, int b);
void fn_27_47B00(int self, int b);
void fn_27_48A1C(int a, int b, int c, unsigned char d, int e, int f, int g, int h, int i, int j);
}

extern "C" int fn_96_3C14(int arg0, int arg1, int arg2, unsigned char arg3) {
    char buf[0x60];
    fn_27_46588(buf, 0, 3);
    fn_27_19E6E8(arg0, 9, buf, 0);
    fn_27_46700(buf, -1);
    fn_27_19FC2C(arg0 + 0x36C, 3, 0);
    fn_27_1994FC(arg0 + 0x5A0, 3, 0);
    fn_27_47B00(arg0 + 0x714, arg1);
    fn_27_48A1C(arg0 + 0x724, arg1, arg2, arg3, arg0, arg0 + 0x5A0, arg0 + 0x36C, arg0 + 0x714, 3, 1);
    return arg0;
}
