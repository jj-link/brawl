#pragma force_active on
extern "C" void fn_27_1A15B8(void* obj, short flag);
extern "C" void fn_120_4138(void* obj, short flag);

extern "C" void* fn_120_40C0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x470, -1);
        if (object != 0) {
            fn_120_4138(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
