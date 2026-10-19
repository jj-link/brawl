#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_68E0(void* object, short deleting);

extern "C" void* fn_118_6884(void* object, short deleting) {
    if (object != 0) {
        fn_118_68E0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
