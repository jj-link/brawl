#pragma force_active on
typedef signed short s16;
typedef signed int s32;

struct GanonFlags {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char after;
};

extern "C" void fn_109_B8A0(void* self, void* arg);
extern "C" void fn_109_BFA8(s16* destination, const s16* source);
extern "C" s32 fn_109_B980(void* self, s16* data, void* arg);

extern "C" void fn_109_B8F0(void* self, const s16* source, void* arg) {
    unsigned char* base = static_cast<unsigned char*>(self);
    GanonFlags* sub = reinterpret_cast<GanonFlags*>(base + 0xC);
    s16 local;

    if ((source[0] & 1) != 0) {
        bool flag = sub->flag;
        if (flag == 1 && sub->after == 0) {
            fn_109_B8A0(sub, arg);
        }
    }

    fn_109_BFA8(&local, source);
    fn_109_B980(base + 4, &local, arg);
}
