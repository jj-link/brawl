#pragma force_active on
extern "C" void* __dt__16acCmdInterpreterFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_2210(void* object, short flag) {
    if (object) {
        __dt__16acCmdInterpreterFv(object, 0);
        if (flag > 0)
            __dl__FPv(object);
    }
    return object;
}
