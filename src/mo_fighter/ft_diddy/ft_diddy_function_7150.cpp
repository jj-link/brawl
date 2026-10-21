#pragma force_active on
extern "C" {
void fn_27_4AC40(void* p, int flag);
void fn_27_4AD20(void* p, short v);
void fn_27_19C31C(void* self, int a, void* buf, int b);
void fn_27_4B184(void* obj, int a, int b, unsigned char c, void* self, void* d, unsigned char e, unsigned char f);
}

extern "C" void* fn_115_7150(void* self, int a, int b, unsigned char c, void* d)
{
    char buf[0x60];
    fn_27_4AC40(buf, 0);
    fn_27_19C31C(self, 4, buf, 0);
    fn_27_4AD20(buf, (short)-1);
    fn_27_4B184((char*)self + 0x17c, a, b, c, self, d, 1, 1);
    return self;
}
