#pragma force_active on
extern "C" {
void fn_27_4D800(void*, int);
void fn_27_CD364(void*, int, void*, int);
void fn_27_4D8E0(void*, short);
void fn_27_CB6E0(void*, int, int);
void fn_27_4DCA4(void*, void*, void*, unsigned char, void*, int);

void* fn_123_78C4(void* a, void* b, void* c, int d) {
    char buf[0x68];
    fn_27_4D800(buf, 0);
    fn_27_CD364(a, 1, buf, 0);
    fn_27_4D8E0(buf, -1);
    fn_27_CB6E0((char*)a + 0x6c, 1, 0);
    fn_27_4DCA4((char*)a + 0xf0, b, c, d & 0xFF, a, 1);
    return a;
}
}
