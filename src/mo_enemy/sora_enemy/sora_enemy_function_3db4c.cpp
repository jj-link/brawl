#pragma force_active on
extern "C" void *fn_41_3DBB8(char *base, int idx);
extern "C" int fn_27_8D3E4(void *);

extern "C" void fn_41_3DB4C(char *self) {
    int i = 0;
    while (i < 3) {
        void *p = fn_41_3DBB8(self + 0xc, i);
        if (fn_27_8D3E4(p) == 0) {
            break;
        }
        i++;
    }
}
