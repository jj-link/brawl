#pragma force_active on
void operator delete(void*);

extern "C" void fn_107_EDF4(void*, short);

extern "C" void* fn_107_EE6C(void* object, short arg2) {
    if (object != 0) {
        fn_107_EDF4(object, 0);
        if (arg2 > 0) {
            operator delete(object);
        }
    }
    return object;
}
