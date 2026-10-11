// The singleton itself remains owned by sora_melee's original BSS unit.
extern "C" unsigned char lbl_27_bss_1CC[];

struct LucarioInputWords {
    unsigned char prefix[8];
    unsigned int first;
    unsigned int second;
};

extern "C" int fn_118_13C58(void*) { return 1; }
extern "C" void fn_118_13C60(void*) {}
extern "C" int fn_118_13C64(void*) { return 0; }
extern "C" int fn_118_13C6C(void*) { return 0; }
extern "C" int fn_118_13C74(void*) { return 0; }
extern "C" int fn_118_13C7C(void*) { return 0; }
extern "C" void fn_118_13C84(void*) {}
extern "C" void* fn_118_13C88(void*) { return lbl_27_bss_1CC; }
extern "C" int fn_118_13C94(void*) { return 0; }
extern "C" void fn_118_13C9C(void*) {}
extern "C" void fn_118_13CA0(void*) {}
extern "C" void fn_118_13CA4(void*) {}
extern "C" void fn_118_13CA8(void*) {}
extern "C" void fn_118_13CAC(void*) {}
extern "C" void fn_118_13CB0(void*) {}
extern "C" void fn_118_13CB4(void*) {}
extern "C" void fn_118_13CB8(void*) {}
extern "C" void fn_118_13CBC(void*) {}

extern "C" void fn_118_13CC0(LucarioInputWords* object, unsigned int value) {
    object->second = value;
}
extern "C" unsigned int fn_118_13CC8(const LucarioInputWords* object) {
    return object->second;
}
extern "C" void fn_118_13CD0(void*) {}
extern "C" unsigned int fn_118_13CD4(const LucarioInputWords* object) {
    return object->first;
}
extern "C" void fn_118_13CDC(LucarioInputWords* object, unsigned int value) {
    object->first = value;
}
extern "C" unsigned int fn_118_13CE4(const LucarioInputWords* object) {
    return object->first;
}
