#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void* fn_124_BC5C(void* p, short flag);
}

extern "C" void* fn_124_BC5C(void* p, short flag)
{
    if (p != 0 && flag > 0) {
        __dl__FPv(p);
    }
    return p;
}
