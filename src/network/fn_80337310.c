#pragma force_active on
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u64 t10;
} S;

extern u64 OSGetTime(void);
extern S *lbl_805A0F70;

void fn_80337310(void) {
    u64 t;
    if (lbl_805A0F70 != 0) {
        lbl_805A0F70->f8 = 0;
        t = OSGetTime();
        lbl_805A0F70->t10 = t;
    }
}
