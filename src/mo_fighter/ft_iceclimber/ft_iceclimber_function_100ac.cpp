#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_1004C(void* object, short deleting);
extern "C" void fn_105_FF18(void* object, short flag);

extern "C" void* fn_105_100AC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_105_1004C(storage + 0x1c8, -1);
        if (object != 0) {
            fn_105_FF18(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
