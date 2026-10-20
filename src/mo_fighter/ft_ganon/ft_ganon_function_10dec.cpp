#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_109_4300(void*, short);
extern "C" void* fn_109_435C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_10DEC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0xd8, -1);
        fn_27_21038(storage + 0xc4, -1);
        fn_109_4300(storage + 0x88, -1);
        fn_109_435C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
