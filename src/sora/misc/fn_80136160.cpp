#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;
typedef long s32;

extern "C" u32 fn_80134344(void* p, u32 idx);

extern "C" u32 fn_80136160(void* arg0, s32 arg1) {
    u32 var_r6 = 0;
    u32 var_r5 = 0;
    s32 temp_r7 = arg1 * 16;
    void* r31 = (void*)((char*)arg0 + temp_r7);
    if (*(int*)((char*)r31 + 0xd4) != 0 && *(int*)((char*)r31 + 0xd8) != 0) {
        var_r5 = 1;
    }
    if (var_r5 != 0) {
        s32 r5 = (s32)arg0 + temp_r7;
        if (*(int*)((char*)r5 + 0xdc) != 0) {
            var_r6 = 1;
        }
    }
    if (var_r6 != 0 && fn_80134344(arg0, (u32)arg1) == 1) {
        return *(u8*)(*(int*)((char*)r31 + 0xd4) + 0x11);
    }
    return 0;
}
