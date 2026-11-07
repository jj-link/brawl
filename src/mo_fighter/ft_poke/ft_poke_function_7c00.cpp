#pragma force_active on
extern "C" {
void fn_27_46588(void* p, int a, int b);
void fn_27_CD64C(void* self, int a, void* buf, int b);
void fn_27_46700(void* p, short v);
void fn_27_CDD58(void* self, int a, int b);
void fn_27_CB6E0(void* self, int a, int b);
void fn_27_47220(void* self, int a);
void fn_27_48A1C(void* a, int b, int c, unsigned char d, void* e, void* f, void* g, void* h);
}

struct Local {
    int a;
    int b;
    unsigned char buf[0x60];
};

extern "C" void* fn_116_7C00(void* self, int arg1, int arg2, unsigned char arg3) {
    Local loc;
    char* p = (char*)self;
    short m1 = -1;
    fn_27_46588(loc.buf, 0, 2);
    fn_27_CD64C(self, 1, loc.buf, 0);
    fn_27_46700(loc.buf, m1);
    fn_27_CDD58(p + 0x6C, 1, 0);
    fn_27_CB6E0(p + 0x130, 1, 0);
    fn_27_47220(p + 0x1B4, arg1);
    loc.a = 2;
    loc.b = 1;
    fn_27_48A1C(p + 0x1C4, arg1, arg2, arg3, self, p + 0x130, p + 0x6C, p + 0x1B4);
    return self;
}
