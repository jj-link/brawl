#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_1A1CFC(void*, short);
void* fn_101_77E8(void*, short);
}

extern "C" void* fn_101_7770(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1CFC(static_cast<unsigned char*>(object) + 0x524, static_cast<short>(-1));
        if (object != 0) {
            fn_101_77E8(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
