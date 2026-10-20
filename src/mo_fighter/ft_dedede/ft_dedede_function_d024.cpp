#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_CFC4(void* object, short deleting);
extern "C" void* fn_117_CE90(void* object, short deleting);

extern "C" void* fn_117_D024(void* object, short deleting) {
    if (object != 0) {
        fn_117_CFC4(static_cast<unsigned char*>(object) + 0x204, static_cast<short>(-1));
        if (object != 0) {
            fn_117_CE90(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
