#pragma force_active on
extern "C" void* __dt__16acCmdInterpreterFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_212C(void* object, short deleteFlag) {
    if (object != 0) {
        __dt__16acCmdInterpreterFv(object, 0);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
