#pragma force_active on
void operator delete(void*);
extern "C" void* fn_95_BCE8(void*, short);
extern "C" void* fn_95_62D0(void*, short);
extern "C" void* fn_95_6340(void*, short);

extern "C" void* fn_95_6258(void* object, short deleting) {
    if (object != 0) {
        fn_95_BCE8(static_cast<unsigned char*>(object) + 0xE0, -1);
        fn_95_62D0(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_95_6340(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
