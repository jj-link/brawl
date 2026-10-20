#pragma force_active on
void operator delete(void*);
extern "C" void* fn_93_B6F4(void*, short);
extern "C" void* fn_93_5984(void*, short);
extern "C" void* fn_93_58B8(void*, short);

extern "C" void* fn_93_5A34(void* object, short deleting) {
    if (object != 0) {
        fn_93_B6F4(static_cast<unsigned char*>(object) + 0xE0, -1);
        fn_93_5984(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_93_58B8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
