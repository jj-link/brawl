#pragma force_active on
extern "C" void fn_27_1D53A0(void *p, int a, int b);

struct FnObj {
    char pad[0x9e8];
};

extern "C" void fn_27_11185C(FnObj **self)
{
    fn_27_1D53A0((void *)((char *)(*self) + 0x9e8), 0, 0);
}
