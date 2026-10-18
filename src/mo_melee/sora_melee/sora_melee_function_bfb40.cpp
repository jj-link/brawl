#pragma force_active on
extern "C" {
void fn_27_C136C(char* p, unsigned int n);

void fn_27_BFB40(char* p, unsigned int n) {
    if (n == 1) {
        p += 0xb8;
    } else {
        p += 0x30;
    }
    fn_27_C136C(p, n);
}
}
