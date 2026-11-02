#pragma force_active on
extern "C" {
void fn_27_46588(void* p, int a, int b);
void fn_27_19E258(void* self, int a, void* buf, int b);
void fn_27_19FA94(void* self, int a, int b);
void fn_27_46700(void* p, short v);
void fn_27_47220(void* self, int a);
void fn_27_48A1C(void* a, int b, int c, unsigned char d, void* e, void* f, void* g, void* h);
void fn_27_CB770(void* self, int a, int b);
}

struct Local {
    int a;
    int b;
    unsigned char buf[0x60];
};

extern "C" void* fn_118_7580(void* self, int arg1, int arg2, unsigned char arg3) {
    Local loc;
    char* p = (char*)self;
    short m1 = -1;
    fn_27_46588(loc.buf, 0, 2);
    fn_27_19E258(self, 2, loc.buf, 0);
    fn_27_46700(loc.buf, m1);
    fn_27_19FA94(p + 0xCC, 2, 0);
    fn_27_CB770(p + 0x248, 2, 0);
    fn_27_47220(p + 0x344, arg1);
    loc.a = 2;
    loc.b = 1;
    fn_27_48A1C(p + 0x354, arg1, arg2, arg3, self, p + 0x248, p + 0xCC, p + 0x344);
    return self;
}
