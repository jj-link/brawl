#pragma force_active on
typedef unsigned char u8;
typedef short s16;
typedef int s32;

struct Flags {
    u8 bit : 1;
    u8 rest : 7;
};

extern "C" {
void fn_122_133E4(u8*, void*);
s16* fn_122_13B24(s16*, const s16*);
s32 fn_122_134C4(u8*, s16*, void*);
}

extern "C" void fn_122_13434(u8* self, const s16* src, void* arg) {
    u8* sub = self + 0xC;
    s16 tmp[4];
    Flags* f = reinterpret_cast<Flags*>(sub + 5);
    if ((src[0] & 1) != 0 && static_cast<bool>(f->bit) == true && sub[6] == 0) {
        fn_122_133E4(sub, arg);
    }
    fn_122_13B24(tmp, src);
    fn_122_134C4(self + 4, tmp, arg);
}
