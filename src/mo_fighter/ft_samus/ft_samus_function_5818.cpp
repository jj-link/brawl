#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_94_5890(void*, short);

extern "C" void* fn_94_5818(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x138, -1);
        if (object != 0) {
            fn_94_5890(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
