#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_38E0(void*, short);
extern "C" void* fn_104_237A0(void*, short);
extern "C" void* fn_104_2382C(void*, short);
extern "C" void* fn_104_238B8(void*, short);
extern "C" void* fn_104_23944(void*, short);

extern "C" void* fn_104_23710(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_38E0(storage + 0x4B0, -1);
        fn_104_237A0(storage + 0x384, -1);
        fn_104_2382C(storage + 0x258, -1);
        fn_104_238B8(storage + 0x12C, -1);
        fn_104_23944(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
