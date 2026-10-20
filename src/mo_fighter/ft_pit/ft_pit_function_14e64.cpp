#pragma force_active on
void operator delete(void*);
extern "C" void* fn_112_455C(void*, short);
extern "C" void* fn_112_45C8(void*, short);
extern "C" void* fn_112_4654(void*, short);
extern "C" void* fn_112_46E0(void*, short);
extern "C" void* fn_112_14EF4(void*, short);

extern "C" void* fn_112_14E64(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_112_455C(storage + 0x4B0, -1);
        fn_112_45C8(storage + 0x384, -1);
        fn_112_4654(storage + 0x258, -1);
        fn_112_46E0(storage + 0x12C, -1);
        fn_112_14EF4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
