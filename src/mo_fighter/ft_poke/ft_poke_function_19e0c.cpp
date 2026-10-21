#pragma force_active on
extern "C" void fn_116_1AFD0(void* a, void* b);
extern "C" short* fn_116_1A34C(short* destination, const short* source);
extern "C" int fn_116_19E9C(void* a, short* b, void* c);

namespace {
struct PokeFlags {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    unsigned char disabled;
};
}

extern "C" void fn_116_19E0C(unsigned char* self, short* src, void* arg) {
    PokeFlags* sub = reinterpret_cast<PokeFlags*>(self + 0xc);
    short tmp[4];
    if ((src[0] & 1) != 0) {
        bool on = sub->enabled;
        if (on == true && sub->disabled == 0) {
            fn_116_1AFD0(sub, arg);
        }
    }
    fn_116_1A34C(tmp, src);
    fn_116_19E9C(self + 4, tmp, arg);
}
