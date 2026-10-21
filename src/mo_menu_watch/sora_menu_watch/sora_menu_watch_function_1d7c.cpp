#pragma force_active on
struct Entry {
    unsigned char a;
    int kind;
    unsigned char col;
    unsigned char pad[0xb];
};

extern "C" int exchangeMuSelchkind2GmCharacterKind__6muMenuFiii(int);
extern "C" int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
extern "C" int getNumCharColor__6muMenuFiii(int);
extern "C" int getFighterColorFileNo__6muMenuFiii(int, int);
extern "C" void fn_1_379C(int, int, int);

inline int colorCount(int kind) {
    int m = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(kind);
    return m == 0x28 ? 1 : getNumCharColor__6muMenuFiii(m);
}

inline int colorFile(int kind, int col) {
    int m = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(kind);
    return m == 0x28 ? 0 : getFighterColorFileNo__6muMenuFiii(m, col);
}

extern "C" void fn_15_1D7C(unsigned char* self, unsigned char* p) {
    if (self[0xd59] == 0) {
        Entry* e = (Entry*)(p + 0xc);
        int kind;
        int col;
        int i;
        for (i = 0; i < p[8]; i++, e++) {
            kind = exchangeMuSelchkind2GmCharacterKind__6muMenuFiii(e->kind);
            if (kind != 0x3e) {
                col = e->col;
                int c;
                if (col < colorCount(kind)) {
                    c = colorFile(kind, col);
                } else {
                    c = 0;
                }
                fn_1_379C(e->a, (unsigned char)kind, (unsigned char)c);
            }
        }
    }
}
