#pragma force_active on
extern "C" void* fn_93_4728(void* object, short deleting);
extern "C" void* fn_93_46C8(void* object, short deleting);
extern "C" void* fn_93_12F64(void* object, short deleting);
extern "C" void* fn_93_12EEC(void* object, short deleting);
extern "C" void* fn_93_12DD0(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);
extern void operator delete(void*);

extern "C" void* fn_93_12FC0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_93_4728(storage + 0x11C, -1);
        fn_93_46C8(storage + 0x108, -1);
        fn_93_12F64(storage + 0xEC, -1);
        fn_93_12EEC(storage + 0x48, -1);
        fn_93_12DD0(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
