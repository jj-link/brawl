#pragma force_active on
extern "C" {
void fn_27_46588(void*, int, int);
void fn_27_19E4A0(void*, int, void*, int);
void fn_27_46700(void*, short);
void fn_27_19FA94(void*, int, int);
void fn_27_CB770(void*, int, int);
void fn_27_47B00(void*, void*);
void fn_27_48A1C(void*, void*, void*, unsigned char, void*, void*, void*, void*);
}

struct Local {
    int sp8;
    int spC;
    char buf[0x60];
};

extern "C" void* fn_119_6234(char* self, void* a, void* b, unsigned char c) {
    Local l;
    fn_27_46588(l.buf, 0, 3);
    fn_27_19E4A0(self, 0x14, l.buf, 0);
    fn_27_46700(l.buf, -1);
    fn_27_19FA94(self + 0x78C, 2, 0);
    fn_27_CB770(self + 0x908, 2, 0);
    fn_27_47B00(self + 0xA04, a);
    l.sp8 = 3;
    l.spC = 1;
    fn_27_48A1C(self + 0xA14, a, b, c, self, self + 0x908, self + 0x78C, self + 0xA04);
    return self;
}
