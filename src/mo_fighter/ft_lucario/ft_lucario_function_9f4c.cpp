#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void* fn_118_1980(void*, short);

extern "C" void* fn_118_9F4C(void* object, short deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<unsigned char*>(object) + 0x10534, -1);
        fn_118_1980(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
