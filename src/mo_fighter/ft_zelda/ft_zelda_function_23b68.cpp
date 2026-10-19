#pragma force_active on
extern "C" {
void* fn_27_BED74(void*, short);
void __dl__FPv(void*);

void* fn_104_23B68(void* obj, short flag) {
    if (obj) {
        fn_27_BED74(obj, static_cast<short>(-1));
        if (flag > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
}
