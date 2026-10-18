#pragma force_active on
extern "C" {
void fn_124_95E4(void*, short);
void __dl__FPv(void*);

void* fn_124_9644(void* p, short flag) {
    if (p != 0) {
        fn_124_95E4((char*)p + 4, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
