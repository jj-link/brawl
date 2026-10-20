#pragma force_active on
typedef unsigned int u32;

typedef struct FtBits {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 8;
        u32 b : 4;
        u32 c : 20;
    } word8;
} FtBits;

extern "C" {
void fn_27_1A743C(FtBits *p, u32 v) {
    p->word8.b = v;
}
}
