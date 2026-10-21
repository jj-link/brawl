#pragma force_active on
extern "C" {
void fn_27_4AC40(void* p, int flag);
void fn_27_19C31C(void* self, int a, void* b, int c);
void fn_27_4AD20(void* p, short flag);
void fn_27_4B184(void* p, int a, int b, int c, void* self, int d, bool e, bool f);
}

extern "C" void* fn_104_8354(char* self, int a, int b, unsigned char c, int d)
{
    char buf[0x60];
    fn_27_4AC40(buf, 0);
    fn_27_19C31C(self, 4, buf, 0);
    fn_27_4AD20(buf, (short)-1);
    fn_27_4B184(self + 0x17c, a, b, c, self, d, true, true);
    return self;
}
