#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_121_4B20(void* object, short flag);

extern "C" void* fn_121_4B98(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0xf0, -1);
        if (object != 0) {
            fn_121_4B20(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
