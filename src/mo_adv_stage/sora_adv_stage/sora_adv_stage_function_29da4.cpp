#pragma force_active on
extern "C" {
void fn_27_27255C(void *self, int a, int b, void *c);

void fn_40_29DA4(char *self)
{
    fn_27_27255C(self + 0x14c, 1, 0, *(void **)(self + 0x168));
}
}
