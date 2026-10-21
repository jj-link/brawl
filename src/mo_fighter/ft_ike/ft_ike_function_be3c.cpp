#pragma force_active on
typedef unsigned char u8;
typedef short s16;

struct IkeSub {
    u8 pad[5];
    u8 flag : 1;
    u8 rest : 7;
    u8 after;
};

extern "C" {
void fn_119_BDEC(void* obj, void* arg);
void fn_119_C52C(s16* dst, const s16* src);
void fn_119_BECC(void* obj, s16* idx, void* arg);
}

extern "C" void fn_119_BE3C(u8* self, s16* idx, void* arg) {
    s16 tmp[4];
    IkeSub* sub = reinterpret_cast<IkeSub*>(self + 0xC);
    if ((idx[0] & 1) != 0) {
        bool flag = sub->flag;
        if (flag == true && sub->after == 0) {
            fn_119_BDEC(sub, arg);
        }
    }
    fn_119_C52C(tmp, idx);
    fn_119_BECC(self + 4, tmp, arg);
}
