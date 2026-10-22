#pragma force_active on
extern "C" {
void fn_27_4AC40(void* a, int b);
void fn_27_19C31C(void* a, int b, void* c, int d);
void fn_27_4AD20(void* a, short b);
void fn_27_4B184(void* a, int b, int c, int d, void* e, void* f, bool g, bool h);
}

extern "C" void* fn_96_3D78(void* self, int a, int b, int c, void* d) {
    char local[0x60];
    bool flag = true;
    fn_27_4AC40(local, 0);
    fn_27_19C31C(self, 4, local, 0);
    fn_27_4AD20(local, -1);
    fn_27_4B184((char*)self + 0x17c, a, b, c & 0xff, self, d, flag, flag);
    return self;
}
