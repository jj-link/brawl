#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_122_9234(void* object, short flag);

extern "C" void* fn_122_91BC(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x48C, -1);
        if (object != 0) {
            fn_122_9234(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
