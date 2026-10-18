#pragma force_active on
extern "C" {
void* fn_120_397C(void* p, short flag)
{
    if (p != 0 && flag > 0) {
        operator delete(p);
    }
    return p;
}
}
