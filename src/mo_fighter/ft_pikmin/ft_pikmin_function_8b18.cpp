#pragma force_active on
extern "C" void fn_27_4AC40(void* p, int v);
extern "C" void fn_27_19C31C(void* self, int a, void* p, int b);
extern "C" void fn_27_4AD20(void* p, short flag);
extern "C" void fn_27_4B184(void* self, int a, int b, int c, void* d, int e, bool f, bool g);

extern "C" {
void* fn_113_8B18(void* self, int a, int b, unsigned char c, int d)
{
    char buf[0x5C];
    fn_27_4AC40(buf, 0);
    fn_27_19C31C(self, 4, buf, 0);
    fn_27_4AD20(buf, (short)-1);
    fn_27_4B184((char*)self + 0x17c, a, b, c, self, d, true, true);
    return self;
}
}
