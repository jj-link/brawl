#pragma force_active on
extern "C" {
void fn_27_19C818(void*, short);
void __dl__FPv(void*);

void* fn_109_62B8(void* p, short flag) {
    if (p != 0) {
        fn_27_19C818(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
