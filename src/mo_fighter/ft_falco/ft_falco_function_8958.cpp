#pragma force_active on
extern "C" {
void fn_27_1994FC(void* self, int a, int b);
void fn_27_19DDC8(void* self, int a, void* buf, int b);
void fn_27_19FC2C(void* self, int a, int b);
void fn_27_46588(void* buf, int a, int b);
void fn_27_46700(void* buf, short v);
void fn_27_47B00(void* self, int a);
void fn_27_48A1C(void* a, int b, int c, unsigned char d, void* e, void* f, void* g, void* h, int i, int j);
}

extern "C" void* fn_108_8958(char* self, int a, int b, unsigned char c) {
    unsigned char buf[0x60];
    fn_27_46588(buf, 0, 3);
    fn_27_19DDC8(self, 0xF, buf, 0);
    fn_27_46700(buf, -1);
    fn_27_19FC2C(self + 0x5AC, 3, 0);
    fn_27_1994FC(self + 0x7E0, 3, 0);
    fn_27_47B00(self + 0x954, a);
    fn_27_48A1C(self + 0x964, a, b, c, self, self + 0x7E0, self + 0x5AC, self + 0x954, 3, 1);
    return self;
}
