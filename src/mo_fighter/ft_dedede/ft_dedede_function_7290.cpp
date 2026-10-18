#pragma force_active on
extern "C" {
void fn_27_4D800(void* buf, int value);
void fn_27_CD364(void* self, int a, void* buf, int b);
void fn_27_4D8E0(void* buf, short value);
void fn_27_CB6E0(void* vec, int size, int param);
void fn_27_4DCA4(void* a, void* b, void* c, unsigned char d, void* e, int f);
}

extern "C" void* fn_117_7290(void* self, void* b, void* c, unsigned char d) {
    unsigned char buf[0x60];
    fn_27_4D800(buf, 0);
    fn_27_CD364(self, 1, buf, 0);
    fn_27_4D8E0(buf, -1);
    fn_27_CB6E0((char*)self + 0x6C, 1, 0);
    fn_27_4DCA4((char*)self + 0xF0, b, c, d, self, 1);
    return self;
}
