#pragma force_active on
void operator delete(void*);
extern "C" void* fn_109_10218(void*, short);
extern "C" void* fn_109_10284(void*, short);
extern "C" void* fn_109_3A08(void*, short);
extern "C" void* fn_109_10310(void*, short);
extern "C" void* fn_109_1039C(void*, short);

extern "C" void* fn_109_10188(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_109_10218(storage + 0x4B0, -1);
        fn_109_10284(storage + 0x384, -1);
        fn_109_3A08(storage + 0x258, -1);
        fn_109_10310(storage + 0x12C, -1);
        fn_109_1039C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
