#pragma force_active on
extern "C" {
extern unsigned char lbl_804556D8[];
}

class muMenu {
public:
    static int exchangeGmCharacterKind2MuStockchkind(int c);
};

int muMenu::exchangeGmCharacterKind2MuStockchkind(int c) {
    const unsigned char* p = lbl_804556D8;
    int idx;
    int i;
    for (i = 0, idx = 0; i < 0x3d; i++) {
        if (c == p[2]) goto done;
        if (c == p[3]) goto done;
        p += 16;
        idx++;
    }
done:
    if (idx == 0x3d) idx = 0;
    return idx;
}
