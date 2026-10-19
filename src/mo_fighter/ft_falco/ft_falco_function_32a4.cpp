#pragma force_active on
void operator delete(void*);
extern "C" void* fn_108_3314(void*, short);
extern "C" void fn_108_60D8(void*, short);

extern "C" void* fn_108_32A4(void* object, short deleting) {
    if (object != 0) {
        fn_108_3314(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_108_60D8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
