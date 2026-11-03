#pragma force_active on
extern "C" {
void fn_27_46588(void*, int, int);
void fn_27_19DB80(void*, int, void*, int);
void fn_27_46700(void*, short);
void fn_27_19FC2C(void*, int, int);
void fn_27_1994FC(void*, int, int);
void fn_27_47B00(void*, void*);
void fn_27_48A1C(void*, void*, void*, unsigned char, void*, void*, void*, void*, int, int);
}
extern "C" void* fn_114_9510(void* self, void* a, void* b, unsigned char c) {
    unsigned char buf[0x60];
    int v = -1;
    fn_27_46588(buf, 0, 3);
    fn_27_19DB80(self, 0xE, buf, 0);
    fn_27_46700(buf, v);
    fn_27_19FC2C((char*)self + 0x54C, 3, 0);
    fn_27_1994FC((char*)self + 0x780, 3, 0);
    fn_27_47B00((char*)self + 0x8F4, a);
    fn_27_48A1C((char*)self + 0x904, a, b, c, self, (void*)((int)self + 0x780), (void*)((int)self + 0x54C), (void*)((int)self + 0x8F4), 3, 1);
    return self;
}