#pragma force_active on
extern "C" {

extern const unsigned char lbl_80407A40[];

unsigned char exchangeMuCharKindToGmCharacterKind__6muMenuFiii(int idx, int, int) {
    return lbl_80407A40[(idx << 2) - idx];
}

}
