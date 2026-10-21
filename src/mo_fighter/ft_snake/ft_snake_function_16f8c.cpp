#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_39B4(void*, short);
extern "C" void* fn_122_1701C(void*, short);
extern "C" void* fn_122_170A8(void*, short);
extern "C" void* fn_122_17134(void*, short);
extern "C" void* fn_122_171C0(void*, short);

extern "C" void* fn_122_16F8C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_39B4(storage + 0x4B0, -1);
        fn_122_1701C(storage + 0x384, -1);
        fn_122_170A8(storage + 0x258, -1);
        fn_122_17134(storage + 0x12C, -1);
        fn_122_171C0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
