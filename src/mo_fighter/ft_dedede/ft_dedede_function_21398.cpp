#pragma force_active on
void operator delete(void*);
extern "C" void fn_117_21338(void* object, short deleting);
extern "C" void* fn_117_21268(void* object, short deleting);

extern "C" void* fn_117_21398(void* object, short deleting) {
    if (object != 0) {
        fn_117_21338(static_cast<unsigned char*>(object) + 0x64, -1);
        if (object != 0) {
            fn_117_21268(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
