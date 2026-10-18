#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1362C(void*, short);

extern "C" void* fn_117_1FAC(void* object, short deleting) {
    if (object != 0) {
        fn_27_1362C(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
