#pragma force_active on
extern "C" {

void __dl__FPv(void*);

void* fn_107_4554(void* p, short n)
{
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}

}
