#pragma force_active on
typedef short s16;
typedef int s32;

struct ZakoFlags {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char after;
};

extern "C" {
void fn_126_9034(void* obj, void* arg);
void fn_126_968C(s16* destination, const s16* source);
s32 fn_126_9114(void* obj, s16* source, void* arg);
}

extern "C" void fn_126_9084(unsigned char* self, const s16* source, void* arg) {
    s16 tmp;
    ZakoFlags* sub = reinterpret_cast<ZakoFlags*>(self + 0xC);
    if ((source[0] & 1) != 0 && (bool)sub->flag == true && sub->after == 0) {
        fn_126_9034(sub, arg);
    }
    fn_126_968C(&tmp, source);
    fn_126_9114(self + 4, &tmp, arg);
}
