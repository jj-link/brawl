#pragma force_active on
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void* fn_123_5C6C(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_123_5BF4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1B88(storage + 0x88, -1);
        if (object != 0) {
            fn_123_5C6C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
