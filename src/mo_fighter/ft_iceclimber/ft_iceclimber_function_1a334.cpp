#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_3814(void*, short);
extern "C" void* fn_105_1A3C4(void*, short);
extern "C" void* fn_105_1A450(void*, short);
extern "C" void* fn_105_1A4DC(void*, short);
extern "C" void* fn_105_1A568(void*, short);

extern "C" void* fn_105_1A334(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_105_3814(storage + 0x4B0, -1);
        fn_105_1A3C4(storage + 0x384, -1);
        fn_105_1A450(storage + 0x258, -1);
        fn_105_1A4DC(storage + 0x12C, -1);
        fn_105_1A568(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
