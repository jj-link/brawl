#pragma force_active on
extern "C" void* fn_102_212C(void*, short);
extern "C" void* fn_102_21C8(void*, short);
extern "C" void* fn_102_2208(void*, short);
extern "C" void* fn_27_C7770(void*, short);
void operator delete(void*);

extern "C" void* fn_102_111F8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_102_212C(storage + 0xdc, memberDeleting);
        fn_102_21C8(storage + 0xc0, memberDeleting);
        fn_102_2208(storage + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
