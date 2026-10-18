#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_19874C(void*, short);

extern "C" void* fn_117_31AC(void* object, short deleting) {
    if (object != 0) {
        fn_27_19874C(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
