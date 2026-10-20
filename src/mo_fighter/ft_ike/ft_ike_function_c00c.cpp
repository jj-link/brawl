#pragma force_active on
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;

struct IkeFlagBlock {
    u8 pad[5];
    u8 flag : 1;
    u8 rest : 7;
    u8 disabled;
};

extern "C" {
void fn_119_BFBC(void* obj, void* arg);
void fn_119_C52C(s16* dst, const s16* src);
s32 fn_119_C09C(void* obj, s16* idx, void* arg);
}

extern "C" void fn_119_C00C(unsigned char* self, const s16* src, void* arg) {
    unsigned char* obj = self + 0xc;
    s16 tmp;
    if ((src[0] & 1) != 0) {
        IkeFlagBlock* blk = reinterpret_cast<IkeFlagBlock*>(obj);
        bool on = blk->flag;
        if (on == 1 && blk->disabled == 0) {
            fn_119_BFBC(obj, arg);
        }
    }
    fn_119_C52C(&tmp, src);
    fn_119_C09C(self + 4, &tmp, arg);
}
