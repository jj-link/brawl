#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_108_21B4(void*, short);
void* fn_108_2250(void*, short);
void* fn_108_2290(void*, short);
void* fn_27_C7770(void*, short);
}
extern "C" void* fn_108_10164(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_108_21B4(storage + 0xDC, memberDeleting);
        fn_108_2250(storage + 0xC0, memberDeleting);
        fn_108_2290(storage + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
