#pragma force_active on
extern "C" {
void fn_8030CEEC(void *, int, int, unsigned char *);

void fn_8030CEB0(void *arg0, int arg1, unsigned char *arg2)
{
    unsigned char sp8;

    if (arg1 > 1) {
        sp8 = *arg2;
        fn_8030CEEC(arg0, 0, arg1 - 1, &sp8);
    }
}
}
