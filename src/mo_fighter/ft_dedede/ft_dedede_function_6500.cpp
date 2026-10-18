#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_14B698(void*, short);

extern "C" void* fn_117_6500(void* object, short deleting) {
    if (object != 0) {
        fn_27_14B698(object, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
