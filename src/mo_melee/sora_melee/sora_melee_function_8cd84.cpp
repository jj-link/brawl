#pragma force_active on
extern "C" {
void *fn_27_8CD84(char *p)
{
    char *a = *(char **)(p + 0x60);
    char *b = *(char **)(a + 0xd8);
    return *(void **)(b + 0x34);
}
}
