#pragma force_active on
typedef signed short s16;
typedef signed int s32;

namespace {
struct ZeldaElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_104_D8A8(void* a, void* b);
s16* fn_104_DC48(s16* destination, const s16* source);
s32 fn_104_D988(void* a, void* b, void* c);
}

extern "C" void fn_104_D8F8(unsigned char* self, const s16* p4, void* p5) {
    unsigned char* q = self + 0xC;
    if (p4[0] & 2) {
        bool enabled = reinterpret_cast<ZeldaElementFlags*>(q + 5)->enabled;
        if (enabled == true && q[6] == 0) {
            fn_104_D8A8(q, p5);
        }
    }
    s16 buf[4];
    fn_104_DC48(buf, p4);
    fn_104_D988(self + 4, buf, p5);
}
