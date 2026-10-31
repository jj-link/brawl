#pragma force_active on
extern "C" void fn_27_174B48(void *a, void *b);

extern "C" void fn_27_176808(void *a, void *b)
{
    int v = *(int *)b;
    if (v <= 0x10 || v >= 0x12) {
        fn_27_174B48(a, b);
    }
}
