#pragma force_active on
void operator delete(void*);
extern "C" {
void* __dt__16acCmdInterpreterFv(void*, short);
}

extern "C" void* fn_101_23D8(void* object, short deleting) {
    if (object != 0) {
        __dt__16acCmdInterpreterFv(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
