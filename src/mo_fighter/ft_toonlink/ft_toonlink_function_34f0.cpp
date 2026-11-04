#pragma force_active on
extern "C" {
void fn_27_46588(void*, int, int);
void fn_27_19E258(void*, int, void*, int);
void fn_27_19FA94(void*, int, int);
void fn_27_46700(void*, short);
void fn_27_47220(void*, void*);
void fn_27_48A1C(void*, int, int, int, void*, void*, void*, void*);
void fn_27_CB770(void*, int, int);
}

struct Local {
    int a;
    int b;
    unsigned char buf[0x60];
};

extern "C" void* fn_121_34F0(void* self, int arg1, int arg2, int arg3) {
    Local loc;
    char* p = (char*)self;
    short m1 = -1;
    fn_27_46588(loc.buf, 0, 2);
    fn_27_19E258(self, 2, loc.buf, 0);
    fn_27_46700(loc.buf, m1);
    fn_27_19FA94(p + 0xCC, 2, 0);
    fn_27_CB770(p + 0x248, 2, 0);
    fn_27_47220(p + 0x344, (void*)arg1);
    loc.a = 2;
    loc.b = 1;
    fn_27_48A1C(p + 0x354, arg1, arg2, arg3 & 0xFF, self, p + 0x248, p + 0xCC, p + 0x344);
    return self;
}