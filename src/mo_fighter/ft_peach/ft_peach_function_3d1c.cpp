#pragma force_active on
extern "C" {
void* fn_103_3E00(void*, short);
void* fn_103_3E84(void*, short);
void* fn_27_1A2D10(void*, short);
void* fn_103_3EE4(void*, short);
void* fn_27_1A1E70(void*, short);
void* fn_27_CD934(void*, short);
void* fn_103_3B44(void*, short);
void* fn_27_C74E8(void*, short);
void* __dl__FPv(void*);

#pragma dont_inline on
void* fn_103_3D1C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        short d = -1;
        fn_103_3E00(p + 0x110, d);
        fn_103_3E84(p + 0xFC, d);
        if (p + 0xEC != 0) {
            fn_27_1A2D10(p + 0xEC, d);
        }
        if (p + 0x48 != 0) {
            fn_103_3EE4(p + 0xD4, d);
            if (p + 0x68 != 0) {
                if (p + 0x68 != 0) {
                    if (p + 0x68 != 0) {
                        fn_27_1A1E70(p + 0x68, d);
                    }
                }
            }
            fn_27_CD934(p + 0x48, d);
        }
        if (p + 0x10 != 0) {
            fn_103_3B44(p + 0x24, d);
        }
        fn_27_C74E8(object, d);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
#pragma dont_inline reset
}
