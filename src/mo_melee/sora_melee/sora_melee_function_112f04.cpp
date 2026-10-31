#pragma force_active on
extern "C" {
void fn_27_1D545C(void *p);

void fn_27_112F04(char *self)
{
    if (*(unsigned char *)(self + 0xa) != 1) {
        return;
    }
    fn_27_1D545C(*(char **)self + 0x9e8);
}
}
