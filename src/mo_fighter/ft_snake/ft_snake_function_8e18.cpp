#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_FBAC(void*, short);
extern "C" void* fn_122_3F24(void*, short);
extern "C" void* fn_122_8E90(void*, short);

extern "C" void* fn_122_8E18(void* object, short deleting) {
    if (object != 0) {
        fn_122_FBAC(static_cast<unsigned char*>(object) + 0xE0, -1);
        fn_122_3F24(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_122_8E90(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
