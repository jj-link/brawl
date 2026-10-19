#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void* fn_117_19B4(void*, short);

extern "C" void* fn_117_A218(void* object, short deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<unsigned char*>(object) + 0x47768, -1);
        fn_117_19B4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
