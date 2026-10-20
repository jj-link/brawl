#pragma force_active on
void operator delete(void*);
extern "C" void fn_105_55F8(void* object, short deleting);
extern "C" void* fn_105_5B04(void* object, short deleting);

extern "C" void* fn_105_5580(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_105_55F8(storage + 0x4144, -1);
        if (object != 0) {
            fn_105_5B04(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
