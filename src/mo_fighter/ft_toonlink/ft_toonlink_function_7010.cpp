#pragma force_active on
extern "C" void* fn_27_63EBC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_121_7010(void* obj, short flags);
}

extern "C" void* fn_121_7010(void* obj, short flags) {
    if (obj != 0) {
        fn_27_63EBC(obj, static_cast<short>(-1));
        if (flags > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
