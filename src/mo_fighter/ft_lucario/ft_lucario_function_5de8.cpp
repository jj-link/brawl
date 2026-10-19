#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_5B39C(void*, short);

extern "C" void* fn_118_5DE8(void* object, short deleting) {
    if (object != 0) {
        fn_27_5B39C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
