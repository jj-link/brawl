#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A1CFC(void* member, short deleteFlag);
extern "C" void fn_102_46F8(void* object, short deleteFlag);

extern "C" void* fn_102_4680(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1CFC(storage + 0x524, -1);
        if (object != 0) {
            fn_102_46F8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
