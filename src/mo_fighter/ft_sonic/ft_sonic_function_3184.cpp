#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_93100(void*, short);
extern "C" void* fn_123_3208(void*, short);
extern "C" void* fn_27_19F4C4(void*, short);
extern "C" void* fn_27_1A55B0(void*, short);

extern "C" void* fn_123_3184(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_93100(storage + 0x4FC0, -1);
        fn_123_3208(storage + 0x7C, -1);
        fn_27_19F4C4(storage + 0x20, -1);
        fn_27_1A55B0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
