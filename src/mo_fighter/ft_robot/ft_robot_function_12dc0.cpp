#pragma force_active on
extern "C" {
void* fn_120_12D20(void*, short);
void* fn_120_12D60(void*, short);
void* fn_120_12CAC(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_120_12DC0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_120_12D20(storage + 0xB0, -1);
        fn_120_12D60(storage + 0x30, -1);
        fn_120_12CAC(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
