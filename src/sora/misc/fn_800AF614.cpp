#pragma force_active on
extern const unsigned char lbl_80407AAC[0xA4];

class muMenu {
public:
    static int exchangeMuStageKindToSrStageKind(int a, int b, int c);
};

int muMenu::exchangeMuStageKindToSrStageKind(int a, int b, int c) {
    return lbl_80407AAC[a * 4];
}
