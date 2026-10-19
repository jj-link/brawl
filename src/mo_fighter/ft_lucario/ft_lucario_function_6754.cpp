#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_C96C0(void*, short);

extern "C" void* fn_118_6754(void* object, short deleting) {
    if (object != 0) {
        fn_27_C96C0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
