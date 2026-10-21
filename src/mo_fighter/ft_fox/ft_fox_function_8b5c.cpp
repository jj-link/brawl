#pragma force_active on
extern "C" {
void fn_27_4AC40(void* p, int flag);
void fn_27_19C31C(void* obj, int a, void* b, int c);
void fn_27_4AD20(void* p, short flag);
void fn_27_4B184(void* p, int a, int b, unsigned char c, void* d, int e, unsigned char f, unsigned char g);

void* fn_97_8B5C(void* self, int a, int b, int c, int d) {
    char buf[0x60];
    fn_27_4AC40(buf, 0);
    fn_27_19C31C(self, 4, buf, 0);
    fn_27_4AD20(buf, -1);
    fn_27_4B184((char*)self + 0x17c, a, b, (unsigned char)c, self, d, 1, 1);
    return self;
}
}
