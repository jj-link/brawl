#pragma force_active on
typedef signed short s16;
typedef signed int s32;

struct Flags {
    unsigned char pad[5];
    unsigned char enabled : 1;
    unsigned char rest : 7;
    unsigned char next;
};

extern "C" {
void fn_105_1156C(void* obj, void* arg);
s16* fn_105_12C6C(s16* dst, const s16* src);
s32 fn_105_11930(void* obj, s16* src, void* arg);
}

extern "C" void fn_105_118A0(unsigned char* obj, s16* src, void* arg) {
    s16 local[4];
    Flags* flags = reinterpret_cast<Flags*>(obj + 0xC);
    if ((src[0] & 1) != 0) {
        bool enabled = flags->enabled;
        if (enabled == true && flags->next == 0) {
            fn_105_1156C(flags, arg);
        }
    }
    fn_105_12C6C(local, src);
    fn_105_11930(obj + 4, local, arg);
}
