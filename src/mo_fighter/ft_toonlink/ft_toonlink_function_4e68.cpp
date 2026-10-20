#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_121_4DF0(void* object, short deleteFlag);

extern "C" void* fn_121_4E68(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_27_1A1B88(p + 0x218, -1);
        if (object != 0) {
            fn_121_4DF0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
