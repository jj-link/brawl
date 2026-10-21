#pragma force_active on
typedef int s32;

typedef struct {
    unsigned char pad[0xa0];
    s32 unkA0;
    s32 unkA4;
} UnnamedStruct;

extern "C" void fn_801BE444(UnnamedStruct* arg0, s32 arg1) {
    s32 val = arg0->unkA0 + arg1;
    arg0->unkA0 = val;
    if (val > arg0->unkA4) {
        arg0->unkA0 = arg0->unkA4;
    }
}
