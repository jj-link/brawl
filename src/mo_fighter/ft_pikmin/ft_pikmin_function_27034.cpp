#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);

void* fn_113_27034(void* p, short size)
{
    if (p != 0) {
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
