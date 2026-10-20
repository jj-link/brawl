#pragma force_active on
extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void* fn_93_4FD0(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_5048(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object);
        fn_27_D2904(member + 0x318, -1);
        if (object != 0) {
            fn_93_4FD0(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
