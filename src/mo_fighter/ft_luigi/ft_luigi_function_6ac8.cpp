#pragma force_active on
extern "C" {
void fn_27_46588(void*, int, int);
void fn_27_19D6F0(void*, int, void*, int);
void fn_27_46700(void*, short);
void fn_27_19FC2C(void*, int, int);
void fn_27_1994FC(void*, int, int);
void fn_27_47B00(void*, int);
void fn_27_48A1C(void*, int, int, unsigned char, void*, void*, void*, void*, int, int);
}
extern "C" void* fn_99_6AC8(char* self, int a1, int a2, unsigned char a3) {
    unsigned char buf[0x60];
    fn_27_46588(buf, 0, 3);
    fn_27_19D6F0(self, 12, buf, 0);
    fn_27_46700(buf, -1);
    fn_27_19FC2C(self + 0x48C, 3, 0);
    fn_27_1994FC(self + 0x6C0, 3, 0);
    fn_27_47B00(self + 0x834, a1);
    fn_27_48A1C(self + 0x844, a1, a2, a3, self, self + 0x6C0, self + 0x48C, self + 0x834, 3, 1);
    return self;
}