#pragma force_active on
extern "C" {
extern const unsigned char lbl_80407BE0[];
extern const unsigned char lbl_80407AAC[];

int exchangeSrStageKindToMuStageKind__6muMenuFiii(int c, int, int) {
    const unsigned char* p = lbl_80407BE0;
    int idx;
    int i;

    for (i = 0, idx = 0; i < 10; i++) {
        if (c == p[0])
            return (lbl_80407BE0 + idx * 2)[1];
        p += 2;
        idx++;
    }

    p = lbl_80407AAC;
    for (i = 0, idx = 0; i < 41; i++) {
        if (c == p[0])
            break;
        p += 4;
        idx++;
    }
    return idx;
}
}