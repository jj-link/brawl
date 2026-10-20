#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void* fn_96_5248(void* object, short flag);

extern "C" void* fn_96_52C0(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0x154, -1);
        if (object != 0) {
            fn_96_5248(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
