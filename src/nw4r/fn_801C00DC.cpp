typedef int s32;

extern "C" {
s32 fn_80203640(s32);
}

#pragma force_active on
extern "C" s32 fn_801C00DC(s32 arg0) {
    return (fn_80203640(arg0 + 0x24) + 0x87) & 0xFFFFFFE0;
}
