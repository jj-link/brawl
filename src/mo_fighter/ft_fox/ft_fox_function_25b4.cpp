#pragma force_active on

extern "C" {
void* fn_97_2210(void*, short);
void* fn_97_22AC(void*, short);
void* fn_97_22EC(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);

void* fn_97_25B4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_97_2210(members + 0xDC, -1);
        fn_97_22AC(members + 0xC0, -1);
        fn_97_22EC(members + 0x14, -1);
        if (object != 0) {
            fn_27_C7770(object, -1);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
