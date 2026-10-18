#pragma force_active on
extern "C" {
void fn_27_4D800(void*, int);
void fn_27_19D4A8(void*, int, void*, int);
void fn_27_4D8E0(void*, short);
void fn_27_CB6E0(void*, int, int);
void fn_27_4DCA4(void*, void*, void*, unsigned char, void*, int);

void* fn_119_63A0(void* a, void* b, void* c, unsigned char d) {
    char buf[0x68];
    fn_27_4D800(buf, 0);
    fn_27_19D4A8(a, 2, buf, 0);
    fn_27_4D8E0(buf, -1);
    fn_27_CB6E0((char*)a + 0xCC, 1, 0);
    fn_27_4DCA4((char*)a + 0x150, b, c, d, a, 1);
    return a;
}
}
