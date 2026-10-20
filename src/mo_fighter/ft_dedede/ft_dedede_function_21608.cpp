#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_215A8(void* object, short deleting);
extern "C" void* fn_117_214D0(void* object, short deleting);

extern "C" void* fn_117_21608(void* object, short deleting) {
    if (object != 0) {
        fn_117_215A8(static_cast<unsigned char*>(object) + 0xE0, static_cast<short>(-1));
        if (object != 0) {
            fn_117_214D0(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
