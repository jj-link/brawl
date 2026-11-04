#include <mu/menu.h>
#pragma force_active on

extern unsigned char lbl_80455458[];
extern const unsigned char lbl_805A21F0[8];

static inline int countColors(int charKind) {
    unsigned char* p =
        *(unsigned char**)(lbl_80455458 + (charKind << 4) + 8);
    int count = 0;
    while (*p != 12) {
        p += 2;
        ++count;
    }
    return count;
}

static inline unsigned char getColor(int charKind, int colorNo) {
    unsigned char* table =
        *(unsigned char**)(lbl_80455458 + (charKind << 4) + 8);
    return table[colorNo * 2];
}

int muMenu::findCharTeamColorNo(int charKind, int teamColor, int teamSet) {
    int color = lbl_805A21F0[teamColor];
    for (; teamSet < countColors(charKind); ++teamSet) {
        if (color == (int)getColor(charKind, teamSet)) {
            break;
        }
    }
    return teamSet;
}
