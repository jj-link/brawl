#pragma force_active on

extern "C" {
void fn_27_46588(void* p, int a, int b);
void fn_27_19E4A0(void* self, int a, void* buf, int b);
void fn_27_46700(void* p, short v);
void fn_27_19FA94(void* self, int a, int b);
void fn_27_CB770(void* self, int a, int b);
void fn_27_47B00(void* self, int a);
void fn_27_48A1C(void* a, int b, int c, unsigned char d,
                 void* e, void* f, void* g, void* h, int i, int j);
}

extern "C" void* fn_104_19D68(void* self, int arg1, int arg2, unsigned char arg3) {
    unsigned char buf[0x60];
    short m1 = -1;
    char* p = (char*)self;

    fn_27_46588(buf, 0, 3);
    fn_27_19E4A0(self, 0x14, buf, 0);
    fn_27_46700(buf, m1);
    fn_27_19FA94(p + 0x78C, 2, 0);
    fn_27_CB770(p + 0x908, 2, 0);
    fn_27_47B00(p + 0xA04, arg1);
    fn_27_48A1C(p + 0xA14, arg1, arg2, arg3, self,
                 p + 0x908, p + 0x78C, p + 0xA04, 3, 1);
    return self;
}
