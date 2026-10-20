#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_108_6DD0(void* object, short deleteFlag);

extern "C" void* fn_108_6D58(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0xF0, -1);
        if (object != 0) {
            fn_108_6DD0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
