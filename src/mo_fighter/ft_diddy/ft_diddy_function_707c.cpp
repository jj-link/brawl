#pragma force_active on
extern "C" {
void fn_27_46588(void* buf, int a, int b);
void fn_27_19E4A0(void* self, int a, void* buf, int b);
void fn_27_46700(void* buf, short value);
void fn_27_19FA94(void* self, int a, int b);
void fn_27_CB770(void* self, int a, int b);
void fn_27_47B00(void* self, int a);
void fn_27_48A1C(void* a, int b, int c, unsigned char d, void* e, void* f, void* g, void* h);
}

struct Local {
    int a;
    int b;
    unsigned char buf[0x60];
};

extern "C" void* fn_115_707C(char* self, int arg1, int arg2, unsigned char arg3) {
    Local s;
    fn_27_46588(s.buf, 0, 3);
    fn_27_19E4A0(self, 0x14, s.buf, 0);
    fn_27_46700(s.buf, -1);
    fn_27_19FA94(self + 0x78C, 2, 0);
    fn_27_CB770(self + 0x908, 2, 0);
    fn_27_47B00(self + 0xA04, arg1);
    s.a = 3;
    s.b = 1;
    fn_27_48A1C(self + 0xA14, arg1, arg2, arg3, self, self + 0x908, self + 0x78C, self + 0xA04);
    return self;
}
