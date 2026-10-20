#include <st/module.h>
#pragma force_active on

extern "C" {
void fn_105_10DC0(void* obj, void* arg);
s16* fn_105_12C6C(s16* dst, const s16* src);
s32 fn_105_11194(void* obj, s16* data, void* arg);
}

struct IceFlags {
    unsigned char enabled : 1;
    unsigned char rest : 7;
};

extern "C" void fn_105_11104(unsigned char* self, s16* src, void* arg) {
    unsigned char* p = self + 0xC;
    IceFlags* f = reinterpret_cast<IceFlags*>(p + 5);
    if ((src[0] & 1) != 0 && (bool)f->enabled == true && p[6] == 0) {
        fn_105_10DC0(p, arg);
    }
    s16 buf[4];
    fn_105_12C6C(buf, src);
    fn_105_11194(self + 4, buf, arg);
}
