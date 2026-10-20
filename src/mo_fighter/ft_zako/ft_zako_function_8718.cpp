#pragma force_active on
void operator delete(void*);
extern "C" void* fn_126_86B8(void* object, short deleting);
extern "C" void fn_126_8584(void* object, short deleting);

extern "C" void* fn_126_8718(void* object, short deleting) {
    if (object != 0) {
        fn_126_86B8(static_cast<unsigned char*>(object) + 0x204, -1);
        if (object != 0) {
            fn_126_8584(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
