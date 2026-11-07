#pragma force_active on
extern "C" {
void fn_27_46588(void* buf, int a, int b);
void fn_27_19DB80(void* self, int a, void* buf, int b);
void fn_27_46700(void* buf, short n);
void fn_27_19FDC4(void* self, int a, int b);
void fn_27_199694(void* self, int a, int b);
void fn_27_47B00(void* self, int a);
void fn_27_48A1C(void* a, int b, int c, unsigned char d, void* e, void* f, void* g, void* h);
}

struct Local {
    int a;
    int b;
    unsigned char buf[0x60];
};

extern "C" void* fn_112_809C(void* self, int arg1, int arg2, unsigned char arg3) {
    Local loc;
    char* p = (char*)self;
    short m1 = -1;
    fn_27_46588(loc.buf, 0, 3);
    fn_27_19DB80(self, 0xE, loc.buf, 0);
    fn_27_46700(loc.buf, m1);
    fn_27_19FDC4(p + 0x54C, 4, 0);
    fn_27_199694(p + 0x838, 4, 0);
    fn_27_47B00(p + 0xA24, arg1);
    loc.a = 3;
    loc.b = 1;
    fn_27_48A1C(p + 0xA34, arg1, arg2, arg3, self, p + 0x838, p + 0x54C, p + 0xA24);
    return self;
}