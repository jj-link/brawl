#pragma force_active on
extern "C" {
void fn_27_4AC40(void* p, int flag);
void fn_27_19C31C(void* self, int a, void* p, int b);
void fn_27_4AD20(void* p, short flag);
void fn_27_4B184(void* a, int b, int c, unsigned char d, void* e, int f, bool g, bool h);
void* fn_101_9DE0(void* self, int a2, int a3, unsigned char a4, int a5);
}

extern "C" void* fn_101_9DE0(void* self, int a2, int a3, unsigned char a4, int a5) {
    unsigned char buf[0x60];
    fn_27_4AC40(buf, 0);
    fn_27_19C31C(self, 4, buf, 0);
    fn_27_4AD20(buf, -1);
    fn_27_4B184(static_cast<unsigned char*>(self) + 0x17c, a2, a3, a4, self, a5, true, true);
    return self;
}
