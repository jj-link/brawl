#pragma force_active on
extern "C" {
void fn_27_46588(void* buf, int a, int b);
void fn_27_CD64C(int self, int a, void* buf, int b);
void fn_27_46700(void* buf, short value);
void fn_27_CDD58(int self, int a, int b);
void fn_27_CB6E0(int vec, int size, int param);
void fn_27_47220(int self, int b);
void fn_27_48A1C(int a, int b, int c, unsigned char d, int e, int f, int g, int h, int i, int j);
}

extern "C" int fn_107_8F9C(int self, int b, int c, unsigned char d) {
    unsigned char buf[0x60];
    fn_27_46588(buf, 0, 2);
    fn_27_CD64C(self, 1, buf, 0);
    fn_27_46700(buf, -1);
    fn_27_CDD58(self + 0x6C, 1, 0);
    fn_27_CB6E0(self + 0x130, 1, 0);
    fn_27_47220(self + 0x1B4, b);
    fn_27_48A1C(self + 0x1C4, b, c, d, self, self + 0x130, self + 0x6C, self + 0x1B4, 2, 1);
    return self;
}
