#pragma force_active on
void operator delete(void*);
extern "C" void* fn_121_17444(void* object, short deleting);
extern "C" void fn_121_5F68(void* object, short deleting);

extern "C" void* fn_121_173D4(void* object, short deleting) {
    if (object != 0) {
        fn_121_17444(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_121_5F68(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
