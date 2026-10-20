#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_95_6B94(void* object, short deleteFlag);

extern "C" void* fn_95_6B1C(void* object, short deleteFlag) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0x154, -1);
        if (object != 0) {
            fn_95_6B94(object, 0);
        }
        if (deleteFlag > 0) {
            operator delete(object);
        }
    }
    return object;
}
