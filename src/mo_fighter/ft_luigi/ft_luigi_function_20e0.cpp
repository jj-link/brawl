#pragma force_active on
extern "C" void* __dt__16acCmdInterpreterFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_20E0(void* object, short deleting) {
    if (object) {
        __dt__16acCmdInterpreterFv(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
