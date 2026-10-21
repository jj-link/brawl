#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_39B4(void*, short);
extern "C" void* fn_122_5524(void*, short);
extern "C" void* fn_122_55B0(void*, short);
extern "C" void* fn_122_563C(void*, short);
extern "C" void* fn_122_7300(void*, short);

extern "C" void* fn_122_7270(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_39B4(storage + 0x4B0, -1);
        fn_122_5524(storage + 0x384, -1);
        fn_122_55B0(storage + 0x258, -1);
        fn_122_563C(storage + 0x12C, -1);
        fn_122_7300(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
