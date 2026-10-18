#pragma force_active on
extern "C" {

void __dl__FPv(void*);

void* fn_109_D17C(void* p, short s)
{
    if (p != 0 && s > 0)
        __dl__FPv(p);
    return p;
}

}
