#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

extern s32 fn_8035A590(s32);
extern u32 *fn_8035A598(s32, s32);
extern void fn_8035A918(s32, s32);
extern void fn_8035B120(s32, void **);

void fn_803782F8(void *arg0) {
    void *sp8;
    s32 temp_r31;
    s32 var_r29;

    sp8 = arg0;
    if (*(s32 *)((u8 *)arg0 + 0x14) == 0) {
        switch (*(s32 *)((u8 *)arg0 + 0x24)) {
        case 0:
            if (*(s32 *)((u8 *)arg0 + 0xC) == 7) {
                temp_r31 = fn_8035A590(*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x8) + 0x10));
                var_r29 = 0;
                while (var_r29 < temp_r31) {
                    if ((u32)sp8 == *fn_8035A598(*(s32 *)((u8 *)*(void **)((u8 *)sp8 + 0x8) + 0x10), var_r29)) {
                        fn_8035A918(*(s32 *)((u8 *)*(void **)((u8 *)sp8 + 0x8) + 0x10), var_r29);
                        return;
                    }
                    var_r29++;
                }
                return;
            }
            fn_8035B120(*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x8) + 0xC), &sp8);
            break;
        default:
            return;
        }
    }
}
