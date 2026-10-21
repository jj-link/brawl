#pragma force_active on
extern "C" void fn_27_4AC40(void* p, int flag);
extern "C" void fn_27_19C31C(void* self, int a, void* b, int c);
extern "C" void fn_27_4AD20(void* p, short flag);
extern "C" void fn_27_4B184(void* a, int b, int c, unsigned char d, void* e, int f, unsigned char g, unsigned char h);

extern "C" void* fn_119_6308(void* self, int a, int b, unsigned char c, int d)
{
    char buf[0x60];
    int one = 1;
    fn_27_4AC40(buf, 0);
    fn_27_19C31C(self, 4, buf, 0);
    fn_27_4AD20(buf, -1);
    fn_27_4B184((char*)self + 0x17c, a, b, c, self, d, one, one);
    return self;
}
