#pragma force_active on
extern "C" void fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_121_4C88(void* object, short flag);
void operator delete(void*);

extern "C" void* fn_121_4D00(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_D2904(storage + 0x154, -1);
        if (object != 0) {
            fn_121_4C88(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
