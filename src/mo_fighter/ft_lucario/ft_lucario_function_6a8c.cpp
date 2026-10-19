#pragma force_active on
void operator delete(void*);
extern "C" void fn_118_D5EC(void*, short);

extern "C" void* fn_118_6A8C(void* object, short deleting) {
    if (object != 0) {
        fn_118_D5EC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
