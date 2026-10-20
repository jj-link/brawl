#pragma force_active on
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_105_66E4(void*, short);

extern "C" void* fn_105_666C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x4B8, -1);
        if (object != 0) {
            fn_105_66E4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
