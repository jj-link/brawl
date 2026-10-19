#pragma force_active on
extern "C" {
void* __dt__16soStopModuleImplFv(void*, short);
void __dl__FPv(void*);
void* fn_102_1ADFC(void* obj, short flag);
}

void* fn_102_1ADFC(void* obj, short flag) {
    if (obj != 0) {
        __dt__16soStopModuleImplFv(obj, -1);
        if (flag > 0)
            __dl__FPv(obj);
    }
    return obj;
}
