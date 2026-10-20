#pragma force_active on
typedef short s16;

extern "C" void fn_96_20C78(void* object, void* arg);
extern "C" s16* fn_96_13310(s16* destination, const s16* source);
extern "C" int fn_96_12E08(void* object, const s16* source, void* arg);

namespace {
struct KirbyFlags {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char other : 7;
    unsigned char disabled;
};
}

extern "C" void fn_96_12D78(void* object, const s16* source, void* arg) {
    unsigned char* base = static_cast<unsigned char*>(object);
    KirbyFlags* sub = reinterpret_cast<KirbyFlags*>(base + 0xC);
    if ((source[0] & 1) != 0 && (bool)sub->enabled == true && sub->disabled == 0) {
        fn_96_20C78(sub, arg);
    }
    s16 tmp[2];
    fn_96_13310(tmp, source);
    fn_96_12E08(base + 4, tmp, arg);
}
