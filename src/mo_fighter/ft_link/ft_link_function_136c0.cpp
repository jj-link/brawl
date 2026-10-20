#pragma force_active on
void operator delete(void*);
extern "C" void* fn_93_13654(void*, short);
extern "C" void* fn_93_135C8(void*, short);
extern "C" void* fn_93_1353C(void*, short);
extern "C" void* fn_93_134B0(void*, short);
extern "C" void* fn_93_13424(void*, short);

extern "C" void* fn_93_136C0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_93_13654(storage + 0x4B0, -1);
        fn_93_135C8(storage + 0x384, -1);
        fn_93_1353C(storage + 0x258, -1);
        fn_93_134B0(storage + 0x12C, -1);
        fn_93_13424(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
