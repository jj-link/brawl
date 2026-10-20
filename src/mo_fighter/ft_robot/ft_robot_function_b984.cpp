#pragma force_active on
extern "C" void fn_120_B924(void* object, short deleting);
extern "C" void fn_120_B7EC(void* object, short deleting);

extern "C" void* fn_120_B984(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_120_B924(storage + 0x17C, -1);
        if (object != 0) {
            fn_120_B7EC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
