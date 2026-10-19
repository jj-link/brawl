#pragma force_active on
extern "C" {
void fn_79_1AB4(void*, int);
void __dl__FPv(void*);

void* fn_79_ADB4(void* p, int flag)
{
    if (p != 0) {
        fn_79_1AB4(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
