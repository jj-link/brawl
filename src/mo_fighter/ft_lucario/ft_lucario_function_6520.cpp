#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_43B4(void*, short);

extern "C" void* fn_118_6520(void* object, short deleting) {
    if (object != 0) {
        fn_118_43B4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
