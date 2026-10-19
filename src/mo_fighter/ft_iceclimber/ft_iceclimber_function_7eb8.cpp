#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_14B698(void*, short);

extern "C" void* fn_105_7EB8(void* object, short deleteFlag) {
    if (object != 0) {
        fn_27_14B698(object, static_cast<short>(-1));
        if (deleteFlag > 0) {
            operator delete(object);
        }
    }
    return object;
}
