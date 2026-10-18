#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_120_3CA0(void*, short);
void* fn_120_3D24(void*, short);
void* fn_120_3D84(void*, short);
void* fn_120_3DE0(void*, short);
void* fn_120_4898(void*, short);
void* fn_27_C74E8(void*, short);
}

extern "C" void* fn_120_3C04(void* object, short deleting) {
    if (object != 0) {
        unsigned char* base = static_cast<unsigned char*>(object);
        fn_120_3CA0(base + 0xDE0, -1);
        fn_120_3D24(base + 0xDCC, -1);
        fn_120_3D84(base + 0x948, -1);
        fn_120_3DE0(base + 0xD4, -1);
        fn_120_4898(base + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
