#pragma force_active on
extern "C" void fn_105_4C24(void* object, short deleting);
extern "C" void fn_105_5580(void* object, short deleting);

void operator delete(void*);

extern "C" void* fn_105_4BAC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_105_4C24(storage + 0x68cc, -1);
        if (object != 0) {
            fn_105_5580(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
