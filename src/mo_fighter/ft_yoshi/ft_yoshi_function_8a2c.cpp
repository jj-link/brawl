#pragma force_active on
extern "C" {
void fn_27_4AC40(void* p, int a);
void fn_27_19C31C(void* p, int a, void* b, int c);
void fn_27_4AD20(void* p, short a);
void fn_27_4B184(void* a, int b, int c, int d, void* e, int f, bool g, bool h);
}

extern "C" void* fn_95_8A2C(void* self, int a, int b, int c, int d) {
    char local[0x54];
    bool flag = true;
    fn_27_4AC40(local, 0);
    fn_27_19C31C(self, 4, local, 0);
    fn_27_4AD20(local, -1);
    fn_27_4B184((char*)self + 0x17c, a, b, c & 0xFF, self, d, flag, flag);
    return self;
}
