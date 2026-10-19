#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_1B34(void*, short);

extern "C" void* fn_118_1C50(void* object, short deleting) {
    if (object != 0) {
        fn_118_1B34(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
