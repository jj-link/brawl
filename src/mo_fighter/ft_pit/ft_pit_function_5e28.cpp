#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void* object, short param);
extern "C" void fn_112_5EA0(void* object, short deleting);

extern "C" void* fn_112_5E28(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x470, -1);
        if (object != 0) {
            fn_112_5EA0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
