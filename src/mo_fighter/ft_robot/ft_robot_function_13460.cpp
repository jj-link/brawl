#pragma force_active on
extern "C" {
void* fn_120_133F4(void*, short);
void* fn_120_13368(void*, short);
void* fn_120_132DC(void*, short);
void* fn_120_13250(void*, short);
void* fn_120_131C4(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_120_13460(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_120_133F4(storage + 0x4B0, destroy);
        fn_120_13368(storage + 0x384, destroy);
        fn_120_132DC(storage + 0x258, destroy);
        fn_120_13250(storage + 0x12C, destroy);
        fn_120_131C4(object, destroy);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
