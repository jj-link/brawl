#pragma force_active on
extern "C" void* fn_123_3F00(void*, short);
extern "C" void* fn_123_539C(void*, short);
extern "C" void* fn_27_19E99C(void*, short);
void operator delete(void*);

extern "C" void* fn_123_5324(void* object, short deleting) {
    if (object != 0) {
        fn_123_3F00(static_cast<unsigned char*>(object) + 0x85C, -1);
        fn_123_539C(static_cast<unsigned char*>(object) + 0x19C, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
