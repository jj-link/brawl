#pragma force_active on
extern "C" void* __dt__16acCmdInterpreterFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_21C4(void* object, int deleting) {
    if (object != 0) {
        __dt__16acCmdInterpreterFv(object, 0);
        if ((short)deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
