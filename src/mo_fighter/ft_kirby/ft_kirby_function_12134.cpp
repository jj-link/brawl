#pragma force_active on
extern "C" void* fn_96_120D4(void* object, short deleting);
extern "C" void* fn_96_11F9C(void* object, short deleting);

extern "C" void* fn_96_12134(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_120D4(storage + 0x17c, -1);
        if (object != 0) {
            fn_96_11F9C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
