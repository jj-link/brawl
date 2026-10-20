#pragma force_active on
typedef short s16;
typedef int s32;

struct Flags {
    unsigned char flag : 1;
    unsigned char pad : 7;
};

extern "C" void fn_102_B830(unsigned char* self, s32 value);
extern "C" s16* fn_102_BE88(s16* destination, const s16* source);
extern "C" s32 fn_102_B910(unsigned char* self, const s16* source, s32 value);

extern "C" void fn_102_B880(unsigned char* self, const s16* source, s32 value) {
    unsigned char* sub = self + 0xC;
    if ((*source & 1) != 0) {
        bool bit = reinterpret_cast<Flags*>(sub + 5)->flag;
        if (bit == 1 && sub[6] == 0) {
            fn_102_B830(sub, value);
        }
    }

    s16 local;
    fn_102_BE88(&local, source);
    fn_102_B910(self + 4, &local, value);
}
