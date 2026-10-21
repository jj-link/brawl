#pragma force_active on
typedef unsigned char u8;
typedef short s16;

struct Sub {
    u8 pad[5];
    u8 flag : 1;
    u8 rest : 7;
    u8 next;
};

extern "C" void fn_121_E3D8(void* obj, void* arg);
extern "C" void fn_121_E948(s16* destination, const s16* source);
extern "C" void fn_121_E4B8(void* obj, s16* buffer, void* arg);

extern "C" void fn_121_E428(void* self, const s16* src, void* arg) {
    u8* base = static_cast<u8*>(self);
    Sub* sub = reinterpret_cast<Sub*>(base + 0xC);
    s16 buf[2];

    if (src[0] & 1) {
        bool flag = sub->flag;
        if (flag == true && sub->next == 0) {
            fn_121_E3D8(sub, arg);
        }
    }

    fn_121_E948(buf, src);
    fn_121_E4B8(base + 4, buf, arg);
}
