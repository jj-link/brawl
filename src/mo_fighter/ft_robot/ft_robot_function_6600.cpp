#pragma force_active on
extern "C" {
void fn_27_46588(void*, int, int);
void fn_27_19E010(void*, int, void*, int);
void fn_27_46700(void*, short);
void fn_27_19FC2C(void*, int, int);
void fn_27_1994FC(void*, int, int);
void fn_27_47B00(void*, int);
void fn_27_48A1C(void*, int, int, unsigned char, void*, void*, void*, void*, int, int);
}
extern "C" void* fn_120_6600(void* self, int a, int b, unsigned char c) {
    unsigned char buf[0x60];
    int v = -1;
    fn_27_46588(buf, 0, 3);
    fn_27_19E010(self, 0x11, buf, 0);
    fn_27_46700(buf, v);
    fn_27_19FC2C((char*)self + 0x66c, 3, 0);
    fn_27_1994FC((char*)self + 0x8a0, 3, 0);
    fn_27_47B00((char*)self + 0xa14, a);
    fn_27_48A1C((char*)self + 0xa24, a, b, c, self, (void*)((int)self + 0x8a0), (void*)((int)self + 0x66c), (void*)((int)self + 0xa14), 3, 1);
    return self;
}