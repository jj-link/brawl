#pragma force_active on
extern "C" {
void fn_27_46588(void*, int, int);
void fn_27_19D6F0(void*, int, void*, int);
void fn_27_46700(void*, short);
void fn_27_19FC2C(void*, int, int);
void fn_27_1994FC(void*, int, int);
void fn_27_47B00(void*, int);
void fn_27_48A1C(void*, int, int, unsigned char, void*, void*, void*, void*);
}

struct Local {
    int a;
    int b;
    unsigned char buf[0x60];
};

extern "C" void* fn_91_35A4(void* self, int arg1, int arg2, unsigned char arg3) {
    Local loc;
    char* p = (char*)self;
    short m1 = -1;
    fn_27_46588(loc.buf, 0, 3);
    fn_27_19D6F0(self, 0xC, loc.buf, 0);
    fn_27_46700(loc.buf, m1);
    fn_27_19FC2C(p + 0x48C, 3, 0);
    fn_27_1994FC(p + 0x6C0, 3, 0);
    fn_27_47B00(p + 0x834, arg1);
    loc.a = 3;
    loc.b = 1;
    fn_27_48A1C(p + 0x844, arg1, arg2, arg3, self, p + 0x6C0, p + 0x48C, p + 0x834);
    return self;
}
