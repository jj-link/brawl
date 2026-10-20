#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_126_3BF0(void* object, short deleteFlag);

extern "C" void* fn_126_3B78(void* object, short deleting) {
    if (object != 0) {
        unsigned char* base = static_cast<unsigned char*>(object);
        fn_27_1A1B88(base + 0xF0, -1);
        if (object != 0) {
            fn_126_3BF0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
