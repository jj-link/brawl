#pragma force_active on
typedef unsigned char u8;

extern "C" const u8 lbl_80407AAC[];

class muMenu {
public:
    static u8 exchangeMuStageKindToGmHideStageKind(int a, int b, int c);
};

u8 muMenu::exchangeMuStageKindToGmHideStageKind(int a, int b, int c) {
    const u8* p = lbl_80407AAC + a * 4;
    return p[1];
}
