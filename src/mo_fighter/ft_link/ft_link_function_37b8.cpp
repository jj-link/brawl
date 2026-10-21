#pragma force_active on
extern "C" void fn_27_4AC40(void* p, int flag);
extern "C" void fn_27_19C31C(void* p, int a, void* b, int c);
extern "C" void fn_27_4AD20(void* p, short flag);
extern "C" void fn_27_4B184(void* a, int b, int c, int d, void* e, int f, bool g, bool h);

struct Local {
    char buf[0x60];
};

extern "C" {
void* fn_93_37B8(void* self, int a2, int a3, int a4, int a5);
}

extern "C" void* fn_93_37B8(void* self, int a2, int a3, int a4, int a5) {
    Local local;
    fn_27_4AC40(&local, 0);
    fn_27_19C31C(self, 4, &local, 0);
    fn_27_4AD20(&local, -1);
    fn_27_4B184((char*)self + 0x17c, a2, a3, (unsigned char)a4, self, a5, true, true);
    return self;
}
