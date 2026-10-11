// Constants remain owned by the original module's read-only data unit.
extern "C" const float lbl_118_rodata_C0;
extern "C" const float lbl_118_rodata_C8;

struct LucarioScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" float fn_118_13B84(void*) { return lbl_118_rodata_C0; }
extern "C" int fn_118_13B90(void*) { return 0; }
extern "C" float fn_118_13B98(void*) { return lbl_118_rodata_C8; }
extern "C" int fn_118_13BA4(void*) { return 0; }
extern "C" float fn_118_13BAC(void*) { return lbl_118_rodata_C0; }
extern "C" float fn_118_13BB8(void*) { return lbl_118_rodata_C0; }
extern "C" int fn_118_13BC4(void*) { return 0; }
extern "C" void fn_118_13BCC(void*) {}
extern "C" void fn_118_13BD0(void*) {}
extern "C" void fn_118_13BD4(void*) {}

extern "C" void fn_118_13BD8(LucarioScalarPair* object) {
    object->first = object->second = lbl_118_rodata_C0;
}

extern "C" float fn_118_13BEC(const LucarioScalarPair* object) {
    return object->first * object->second;
}
