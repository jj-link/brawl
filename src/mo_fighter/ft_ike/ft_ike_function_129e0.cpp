#pragma force_active on
void operator delete(void*);
extern "C" void* fn_119_12974(void*, short);
extern "C" void* fn_119_128E8(void*, short);
extern "C" void* fn_119_1285C(void*, short);
extern "C" void* fn_119_127D0(void*, short);
extern "C" void* fn_119_12744(void*, short);

extern "C" void* fn_119_129E0(void* object, short deleting) {
    if (object != 0) {
        short neg = -1;
        fn_119_12974((char*)object + 0x4B0, neg);
        fn_119_128E8((char*)object + 0x384, neg);
        fn_119_1285C((char*)object + 0x258, neg);
        fn_119_127D0((char*)object + 0x12C, neg);
        fn_119_12744(object, neg);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
