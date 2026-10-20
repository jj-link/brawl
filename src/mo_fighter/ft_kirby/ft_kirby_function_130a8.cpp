#pragma force_active on
typedef signed short s16;
typedef int s32;

namespace {
struct KirbyElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_96_13058(void* a, void* b);
s16* fn_96_13310(s16* destination, const s16* source);
s32 fn_96_13138(void* object, const s16* source, void* argument);
}

extern "C" void fn_96_130A8(unsigned char* self, const s16* src, void* arg) {
    unsigned char* p = self + 0xC;
    s16 tmp[4];
    if (src[0] & 4) {
        bool enabled = reinterpret_cast<KirbyElementFlags*>(p + 5)->enabled;
        if (enabled == true && p[6] == 0) {
            fn_96_13058(p, arg);
        }
    }
    fn_96_13310(tmp, src);
    fn_96_13138(self + 4, tmp, arg);
}
