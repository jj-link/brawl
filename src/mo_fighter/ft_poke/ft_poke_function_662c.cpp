#pragma force_active on
extern "C" {

void fn_27_1540CC(void*, short);
void __dl__FPv(void*);

void* fn_116_662C(void* p, int flags)
{
    if (p != 0) {
        fn_27_1540CC(p, -1);
        if ((short)flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

}
