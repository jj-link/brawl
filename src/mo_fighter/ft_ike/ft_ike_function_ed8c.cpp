#pragma force_active on
extern "C" {
void __dl__FPv(void* p);
}

extern "C" void* fn_119_ED8C(void* p, short flag)
{
    if (p != 0) {
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
