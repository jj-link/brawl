#pragma force_active on
extern "C" {
void fn_27_46588(void*, int, int);
void fn_27_CD64C(void*, int, void*, int);
void fn_27_46700(void*, short);
void fn_27_CDD58(void*, int, int);
void fn_27_CB6E0(void*, int, int);
void fn_27_4839C(void*, int);
void fn_27_48A1C(void*, int, int, unsigned char, void*, void*, void*, void*);
}

struct Local {
    int a;
    int b;
    unsigned char buf[0x60];
};

extern "C" void* fn_101_9D0C(void* self, int a, int b, unsigned char c) {
    Local loc;
    char* p = (char*)self;
    fn_27_46588(loc.buf, 0, 4);
    fn_27_CD64C(self, 1, loc.buf, 0);
    fn_27_46700(loc.buf, -1);
    fn_27_CDD58(p + 0x6C, 1, 0);
    fn_27_CB6E0(p + 0x130, 1, 0);
    fn_27_4839C(p + 0x1B4, a);
    loc.a = 4;
    loc.b = 1;
    fn_27_48A1C(p + 0x1C4, a, b, c, self, p + 0x130, p + 0x6C, p + 0x1B4);
    return self;
}