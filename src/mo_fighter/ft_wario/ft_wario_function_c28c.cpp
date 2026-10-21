#pragma force_active on
typedef signed short s16;
typedef int s32;

extern "C" {
void fn_110_C23C(void* a, void* b);
s16* fn_110_C6C4(s16* destination, const s16* source);
void fn_110_C31C(void* a, s16* b, void* c);
}

struct FlagByte {
    unsigned char hi : 1;
    unsigned char rest : 7;
};

extern "C" void fn_110_C28C(void* self, const s16* source, void* arg) {
    unsigned char* composite = static_cast<unsigned char*>(self);
    unsigned char* sub = composite + 0xC;
    s16 local[4];

    if ((source[0] & 1) != 0) {
        FlagByte* fb = reinterpret_cast<FlagByte*>(sub + 5);
        bool flag = fb->hi;
        if (flag == true && sub[6] == 0) {
            fn_110_C23C(sub, arg);
        }
    }

    fn_110_C6C4(local, source);
    fn_110_C31C(composite + 4, local, arg);
}
