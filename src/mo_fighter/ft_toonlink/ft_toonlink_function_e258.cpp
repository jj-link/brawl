#pragma force_active on
typedef signed short s16;
typedef unsigned char u8;

struct ToonSub {
    u8 pad[5];
    u8 flag : 1;
    u8 rest : 7;
    u8 next;
};

extern "C" void fn_121_E208(void* self, void* arg);
extern "C" void fn_121_E948(s16* dest, const s16* source);
extern "C" void fn_121_E2E8(void* self, s16* data, void* arg);

extern "C" void fn_121_E258(void* self, s16* param, void* arg) {
    u8* base = static_cast<u8*>(self);
    ToonSub* sub = reinterpret_cast<ToonSub*>(base + 0xC);
    if ((param[0] & 1) != 0) {
        bool flag = sub->flag;
        if (flag == true && sub->next == 0) {
            fn_121_E208(sub, arg);
        }
    }
    s16 local[4];
    fn_121_E948(local, param);
    fn_121_E2E8(base + 4, local, arg);
}
