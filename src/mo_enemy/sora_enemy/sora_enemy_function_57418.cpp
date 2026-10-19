#pragma force_active on
extern "C" void fn_41_573A8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_57418(void* obj, short flag) {
    if (obj != 0) {
        fn_41_573A8(obj, 0);
        if (flag > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
