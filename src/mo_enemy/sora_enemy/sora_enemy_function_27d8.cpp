#pragma force_active on
extern "C" void* __dt__16acCmdInterpreterFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_27D8(void* object, int shouldDelete) {
    if (object) {
        __dt__16acCmdInterpreterFv(object, 0);
        if ((short)shouldDelete > 0)
            __dl__FPv(object);
    }
    return object;
}
