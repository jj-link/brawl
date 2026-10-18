#pragma force_active on
void operator delete(void*);

extern "C" void* fn_107_3E64(void*, short);
extern "C" void* fn_107_3EE8(void*, short);
extern "C" void* fn_107_1ED10(void*, short);
extern "C" void* fn_107_3F48(void*, short);
extern "C" void* fn_107_1ED6C(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

extern "C" void* fn_107_1EC74(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_107_3E64(members + 0x120, -1);
        fn_107_3EE8(members + 0x10c, -1);
        fn_107_1ED10(members + 0xf0, -1);
        fn_107_3F48(members + 0x4c, -1);
        fn_107_1ED6C(members + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
