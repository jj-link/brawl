#pragma force_active on

typedef signed int s32;

extern void closesocket(s32);
extern void fn_8035A4FC(s32);
extern void fn_8035C2D8(s32, s32);
extern void fn_8035E00C(void *);

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 sock;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
} Struct_8036F974;

void fn_8036F974(s32 unused, Struct_8036F974 *arg1) {
    fn_8035C2D8(arg1->sock, 2);
    closesocket(arg1->sock);
    fn_8035E00C((void *)arg1->unk1C);
    arg1->unk1C = 0;
    fn_8035E00C((void *)arg1->unk2C);
    arg1->unk2C = 0;
    if (arg1->unk3C != 0) {
        fn_8035A4FC(arg1->unk3C);
        arg1->unk3C = 0;
    }
    fn_8035E00C(arg1);
}
