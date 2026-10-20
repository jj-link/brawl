#pragma force_active on
extern "C" {
void* fn_96_6B10(void*, short);
void* fn_96_6AD0(void*, short);
void* fn_96_6BAC(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_96_AA98(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short neg = -1;
        fn_96_6B10(storage + 0xDC, neg);
        fn_96_6AD0(storage + 0xC0, neg);
        fn_96_6BAC(storage + 0x14, neg);
        if (object != 0) {
            fn_27_C7770(object, neg);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
