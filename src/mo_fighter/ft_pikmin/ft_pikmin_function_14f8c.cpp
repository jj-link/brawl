#pragma force_active on
void operator delete(void*);

extern "C" void fn_113_14FE8(void*, short);

extern "C" void* fn_113_14F8C(void* object, int deleting) {
    if (object != 0) {
        fn_113_14FE8(object, 0);
        if (static_cast<short>(deleting) > 0) {
            operator delete(object);
        }
    }
    return object;
}
