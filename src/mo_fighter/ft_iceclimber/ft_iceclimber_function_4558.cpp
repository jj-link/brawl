#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_B5324(void*, short);
extern "C" void* fn_105_45E4(void*, short);

extern "C" void* fn_105_4558(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_B5324(storage + 0x20, -1);
        if (storage + 0x10 != 0) {
            fn_105_45E4(storage + 0x10, 0);
        }
        if (object != 0) {
            fn_105_45E4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
