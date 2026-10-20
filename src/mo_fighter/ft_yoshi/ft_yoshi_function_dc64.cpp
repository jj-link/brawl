#pragma force_active on
void operator delete(void*);

extern "C" void* fn_95_DC04(void* object, short deleting);
extern "C" void* fn_95_DAD0(void* object, short deleting);

extern "C" void* fn_95_DC64(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_DC04(storage + 0x1C8, -1);
        if (object != 0) {
            fn_95_DAD0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
