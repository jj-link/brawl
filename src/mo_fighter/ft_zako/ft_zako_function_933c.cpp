#pragma force_active on
typedef unsigned char u8;
typedef short s16;

struct Flags {
    unsigned char enabled : 1;
    unsigned char rest : 7;
};

extern "C" void fn_126_92EC(void* obj, void* arg);
extern "C" void fn_126_968C(s16* destination, const s16* source);
extern "C" void fn_126_93CC(void* obj, const s16* src, void* arg);

extern "C" void fn_126_933C(u8* self, const s16* src, void* arg) {
    u8* sub = self + 0xC;
    if (src[0] & 2) {
        bool e = reinterpret_cast<Flags*>(sub + 5)->enabled;
        if (e == true && sub[6] == 0) {
            fn_126_92EC(sub, arg);
        }
    }
    s16 tmp[2];
    fn_126_968C(tmp, src);
    fn_126_93CC(self + 4, tmp, arg);
}
