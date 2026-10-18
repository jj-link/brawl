#pragma force_active on
extern "C" void* __dt__16acCmdInterpreterFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_21B4(void* object, int flag) {
    if (object != 0) {
        __dt__16acCmdInterpreterFv(object, 0);
        if ((short)flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
