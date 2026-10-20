#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_1C730(void* object, short deleting);
extern "C" void fn_113_1C658(void* object, short deleting);

extern "C" void* fn_113_1C790(void* object, short deleting) {
    if (object != 0) {
        fn_113_1C730(static_cast<unsigned char*>(object) + 0xA0, -1);
        if (object != 0) {
            fn_113_1C658(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
