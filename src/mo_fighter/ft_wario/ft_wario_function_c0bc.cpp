#pragma force_active on
typedef signed short s16;
typedef signed int s32;

struct WarioSubFlags {
    unsigned char pad[5];
    unsigned char bit : 1;
    unsigned char rest : 7;
    unsigned char next;
};

extern "C" {
void fn_110_C06C(void* dst, void* arg);
s16* fn_110_C6C4(s16* destination, const s16* source);
s32 fn_110_C14C(void* dst, const s16* src, void* arg);
}

extern "C" void fn_110_C0BC(unsigned char* self, const s16* src, void* arg) {
    s16 local;
    WarioSubFlags* sub = reinterpret_cast<WarioSubFlags*>(self + 0xC);
    if ((src[0] & 1) != 0) {
        bool flag = sub->bit;
        if (flag == true && sub->next == 0) {
            fn_110_C06C(sub, arg);
        }
    }
    fn_110_C6C4(&local, src);
    fn_110_C14C(self + 4, &local, arg);
}
