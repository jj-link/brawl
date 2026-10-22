#pragma force_active on
extern "C" {
void fn_27_4AC40(void*, int);
void fn_27_19C31C(void*, int, void*, int);
void fn_27_4AD20(void*, short);
void fn_27_4B184(void*, int, int, int, void*, int, bool, bool);
}

extern "C" void* fn_116_7DA8(void* self, int a, int b, unsigned char c, int d) {
    char buf[0x60];
    bool flag = true;
    fn_27_4AC40(buf, 0);
    fn_27_19C31C(self, 4, buf, 0);
    fn_27_4AD20(buf, (short)-1);
    fn_27_4B184((char*)self + 0x17c, a, b, c, self, d, flag, flag);
    return self;
}
