#pragma force_active on
void operator delete(void*);
extern "C" void fn_109_55E8(void* object, short flag);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);

extern "C" void* fn_109_5570(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1B88(storage + 0xF0, -1);
        if (object != 0) {
            fn_109_55E8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
