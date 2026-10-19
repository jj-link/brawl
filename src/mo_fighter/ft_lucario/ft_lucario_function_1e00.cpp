#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_1E5C(void* object, short deleting);

extern "C" void* fn_118_1E00(void* object, short deleting) {
    if (object != 0) {
        fn_118_1E5C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
