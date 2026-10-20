#pragma force_active on
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;

extern "C" void fn_108_E008(void* p, void* arg);
extern "C" void fn_108_E490(s16* destination, const s16* source);
extern "C" s32 fn_108_E0E8(void* p, s16* src, void* arg);

struct FalcoSub {
    u8 pad[5];
    u8 flag : 1;
    u8 rest : 7;
    u8 field6;
};

extern "C" void fn_108_E058(void* obj, const s16* param, void* arg) {
    u8* base = static_cast<u8*>(obj);
    FalcoSub* p = reinterpret_cast<FalcoSub*>(base + 0xC);
    s16 local;

    if ((param[0] & 1) != 0) {
        bool enabled = p->flag;
        if (enabled == true && p->field6 == 0) {
            fn_108_E008(p, arg);
        }
    }
    fn_108_E490(&local, param);
    fn_108_E0E8(base + 4, &local, arg);
}
