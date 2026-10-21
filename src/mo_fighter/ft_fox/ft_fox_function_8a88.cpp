#pragma force_active on
extern "C" {
void fn_27_46588(void* buf, int a, int b);
void fn_27_19DDC8(int self, int a, void* buf, int b);
void fn_27_46700(void* buf, short value);
void fn_27_19FC2C(int self, int a, int b);
void fn_27_1994FC(int self, int a, int b);
void fn_27_47B00(int self, int a);
void fn_27_48A1C(int a, int b, int c, unsigned char d, int e, int f, int g, int h, int i, int j);
}

extern "C" int fn_97_8A88(int self, int arg1, int arg2, unsigned char arg3) {
    unsigned char buf[0x60];
    fn_27_46588(buf, 0, 3);
    fn_27_19DDC8(self, 0xF, buf, 0);
    fn_27_46700(buf, -1);
    fn_27_19FC2C(self + 0x5AC, 3, 0);
    fn_27_1994FC(self + 0x7E0, 3, 0);
    fn_27_47B00(self + 0x954, arg1);
    fn_27_48A1C(self + 0x964, arg1, arg2, arg3, self, self + 0x7E0, self + 0x5AC, self + 0x954, 3, 1);
    return self;
}
