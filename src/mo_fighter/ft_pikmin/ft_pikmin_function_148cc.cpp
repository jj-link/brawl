#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_113_14AC4(void*, short);
void* fn_113_14B20(void*, short);
void* fn_113_29B4(void*, short);
void* fn_113_14B7C(void*, short);
void* fn_113_14BD8(void*, short);
void* fn_113_14C34(void*, short);
void* fn_113_14CB8(void*, short);
void* fn_113_14D44(void*, short);
void* fn_113_14DA4(void*, short);
void* fn_113_14E1C(void*, short);
void* fn_113_2DAC(void*, short);
void* fn_113_2EE0(void*, short);
void* fn_113_150A8(void*, short);
void* fn_113_15184(void*, short);
void* fn_113_2F98(void*, short);
void* fn_113_3004(void*, short);
void* fn_113_3064(void*, short);
void* fn_113_30C4(void*, short);
void* fn_113_3120(void*, short);
void* fn_113_151E0(void*, short);
void* fn_113_15254(void*, short);
void* fn_113_152CC(void*, short);
void* fn_113_15338(void*, short);
void* fn_113_153BC(void*, short);
void* fn_113_317C(void*, short);
void* fn_113_3248(void*, short);
void* fn_113_32A4(void*, short);
void* fn_113_3310(void*, short);
void* fn_113_1549C(void*, short);
void* fn_113_34D4(void*, short);
void* fn_113_3540(void*, short);
void* fn_113_35F8(void*, short);
void* fn_113_3638(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_113_15624(void*, short);
}

extern "C" void* fn_113_148CC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        short d = -1;

        fn_113_14AC4(p + 0x2974, d);
        fn_113_14B20(p + 0x2934, d);
        fn_113_29B4(p + 0x291C, d);
        fn_113_14B7C(p + 0x28CC, d);
        fn_113_14BD8(p + 0x2778, d);
        fn_113_14C34(p + 0x2668, d);
        fn_113_14CB8(p + 0x24D4, d);
        fn_113_14D44(p + 0x241C, d);
        fn_113_14DA4(p + 0x21E8, d);
        fn_113_14E1C(p + 0x1EB0, d);
        fn_113_2DAC(p + 0x1E0C, d);
        fn_113_2EE0(p + 0x1DD8, d);
        fn_113_150A8(p + 0x1D00, d);
        fn_113_15184(p + 0x1CD0, d);
        fn_113_2F98(p + 0x1B6C, d);
        fn_113_3004(p + 0x1B04, d);
        fn_113_3064(p + 0x1AF8, d);
        fn_113_30C4(p + 0x1AD0, d);
        fn_113_3120(p + 0x1A68, d);
        fn_113_151E0(p + 0x1910, d);
        fn_113_15254(p + 0x1718, d);
        fn_113_152CC(p + 0x15CC, d);
        fn_113_15338(p + 0x13BC, d);
        fn_113_153BC(p + 0x1000, d);
        fn_113_317C(p + 0xF9C, d);
        fn_113_3248(p + 0xF60, d);
        fn_113_32A4(p + 0xEB8, d);
        fn_113_3310(p + 0xE04, d);
        fn_113_1549C(p + 0xB84, d);
        fn_113_34D4(p + 0x9A4, d);
        fn_113_3540(p + 0x974, d);
        fn_113_35F8(p + 0x964, d);
        fn_113_3638(p + 0x94C, d);
        __dt__16soModuleAccesserFv(p + 0x86C, d);
        fn_113_15624(object, d);

        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
