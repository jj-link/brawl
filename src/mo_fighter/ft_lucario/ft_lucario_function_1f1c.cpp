#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_7700(void*, short);

extern "C" void* fn_118_1F1C(void* object, short deleting) {
    if (object != 0) {
        fn_27_7700(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
