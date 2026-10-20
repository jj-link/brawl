#pragma force_active on
extern "C" {
int fn_27_8CD34(char *self)
{
    char *a = *(char **)(self + 0x60);
    char *b = *(char **)(a + 0xd8);
    return *(int *)(b + 0x4);
}
}
