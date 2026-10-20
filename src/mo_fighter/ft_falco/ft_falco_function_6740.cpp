#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_108_67B8(void* object, short deleting);

extern "C" void* fn_108_6740(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1B88(storage + 0x48C, -1);
        if (object != 0) {
            fn_108_67B8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
