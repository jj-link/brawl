#pragma force_active on
extern "C" void fn_27_4AC40(void* p, int flag);
extern "C" void fn_27_4AD20(void* p, short flag);
extern "C" void fn_27_19C31C(void* self, int a, void* buf, int b);
extern "C" void fn_27_4B184(void* self, int a1, int a2, unsigned char a3, void* self2, int a4, unsigned char a5, unsigned char a6);

extern "C" void* fn_122_B5D8(void* self, int a1, int a2, int a3, int a4)
{
    char buf[0x5C];
    fn_27_4AC40(buf, 0);
    fn_27_19C31C(self, 4, buf, 0);
    fn_27_4AD20(buf, -1);
    fn_27_4B184((char*)self + 0x17c, a1, a2, (unsigned char)a3, self, a4, 1, 1);
    return self;
}
