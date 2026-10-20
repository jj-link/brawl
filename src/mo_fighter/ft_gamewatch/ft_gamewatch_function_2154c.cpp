#pragma force_active on
void operator delete(void*);
extern "C" void* fn_107_3A20(void*, short);
extern "C" void* fn_107_215DC(void*, short);
extern "C" void* fn_107_21668(void*, short);
extern "C" void* fn_107_216F4(void*, short);
extern "C" void* fn_107_50A0(void*, short);

extern "C" void* fn_107_2154C(void* object, short deleting) {
    if (object != 0) {
        short neg = -1;
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_107_3A20(static_cast<unsigned char*>(object) + 0x4B0, neg);
        fn_107_215DC(storage + 0x384, neg);
        fn_107_21668(storage + 0x258, neg);
        fn_107_216F4(storage + 0x12C, neg);
        fn_107_50A0(object, neg);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
