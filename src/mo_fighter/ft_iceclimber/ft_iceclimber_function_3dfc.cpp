#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_3EA0(void* object, short deleting);
extern "C" void* fn_105_3F78(void* object, short deleting);
extern "C" void* fn_27_1A2D10(void* object, short deleting);
extern "C" void* fn_105_3FD8(void* object, short deleting);
extern "C" void* fn_105_4100(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);

extern "C" void* fn_105_3DFC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_105_3EA0(storage + 0x110, -1);
        fn_105_3F78(storage + 0xFC, -1);
        unsigned char* sub = storage + 0xEC;
        if (sub != 0) {
            fn_27_1A2D10(sub, -1);
        }
        fn_105_3FD8(storage + 0x48, -1);
        fn_105_4100(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
