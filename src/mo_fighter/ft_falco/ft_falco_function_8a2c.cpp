#pragma force_active on

extern "C" {
void fn_27_4AC40(void*, int);
void fn_27_19C31C(void*, int, void*, int);
void fn_27_4AD20(void*, short);
void fn_27_4B184(void*, int, int, unsigned char, void*, int, bool, bool);

void* fn_108_8A2C(void* self, int a, int b, unsigned char c, int d) {
    char buf[0x58];
    fn_27_4AC40(buf, 0);
    fn_27_19C31C(self, 4, buf, 0);
    fn_27_4AD20(buf, -1);
    fn_27_4B184((char*)self + 0x17c, a, b, c, self, d, true, true);
    return self;
}
}
