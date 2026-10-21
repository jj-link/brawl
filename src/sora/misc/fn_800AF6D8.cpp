#pragma force_active on
typedef unsigned char u8;

extern "C" const u8 lbl_80407AAC[];

extern "C" int exchangeMuStageKindToMsgID__6muMenuFiii(int kind, int, int) {
    const u8* p = lbl_80407AAC + kind * 4;
    return p[3];
}
