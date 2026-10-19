#pragma force_active on
extern "C" void fn_27_1999C4(void *self, int a, int b);
extern "C" void fn_27_19BF3C(void *self, int a, int b);
extern "C" void fn_27_150320(void *dst, void *a, int b, void *self, void *other);

extern "C" {
void *fn_108_8C70(char *self, void *a, short b)
{
    fn_27_1999C4(self, 10, 0);
    fn_27_19BF3C(self + 0x584, 2, 0);
    fn_27_150320(self + 0x5b8, a, b, self, self + 0x584);
    return self;
}
}
