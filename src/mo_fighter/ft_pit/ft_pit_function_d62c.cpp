#pragma force_active on
typedef unsigned char u8;
typedef short s16;
typedef int s32;

struct Flags5 {
    u8 enabled : 1;
    u8 other : 7;
};

extern "C" {
void fn_112_D5DC(void* self, void* arg);
void fn_112_DA64(s16* destination, const s16* source);
s32 fn_112_D6BC(void* self, s16* buffer, void* arg);
}

extern "C" void fn_112_D62C(u8* self, const s16* source, void* arg) {
    u8* sub = self + 0xc;
    if ((source[0] & 1) != 0) {
        Flags5* f = reinterpret_cast<Flags5*>(sub + 5);
        bool enabled = f->enabled;
        if (enabled == true && sub[6] == 0) {
            fn_112_D5DC(sub, arg);
        }
    }

    s16 buffer[4];
    fn_112_DA64(buffer, source);
    fn_112_D6BC(self + 4, buffer, arg);
}
