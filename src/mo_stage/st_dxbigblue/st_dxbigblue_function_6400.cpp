#pragma force_active on
extern "C" {
void fn_81_4F40(void* p, int flag);
void __dl__FPv(void* p);

void* fn_81_6400(void* p, int del) {
    if (p != 0) {
        fn_81_4F40(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
