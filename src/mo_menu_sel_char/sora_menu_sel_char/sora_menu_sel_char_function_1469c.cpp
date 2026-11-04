#include <mu/selchar/mu_selchar_player_area.h>
#pragma force_active on

extern "C" int fn_10_110F8(muSelCharPlayerArea*, int);
extern "C" int fn_10_12010(muSelCharPlayerArea*, int);
extern "C" int fn_800AF6F0(int);
extern "C" const float lbl_10_rodata_6A8;
extern "C" const float lbl_10_rodata_6D4;

inline bool used(muSelCharPlayerArea* self, int kind, int color) {
    muSelCharTask* task = self->m_selCharTask;
    int count = *(int*)((char*)task + 0x648);
    muSelCharPlayerArea* other;
    for (int i = 0; i < count; ++i) {
        if (i != self->m_areaIdx && (other = task->m_selCharPlayerAreas[i])->m_playerKind != 0 &&
            kind == other->m_charKind && color == other->m_charColorNo)
            return true;
    }
    return false;
}

extern "C" void fn_10_1469C(muSelCharPlayerArea* self, int kind) {
    if (kind != 40 && kind != 41) {
        int color = 0;
        while (color < fn_10_110F8(self, kind)) {
            if (!used(self, kind, color)) break;
            ++color;
        }
        unsigned char teamSet;
        int teamColor;
        int playerKind;
        bool team = *(bool*)((char*)self->m_selCharTask + 0x5c8);
        if (!team) {
            teamSet = self->m_teamSet;
            teamColor = self->m_teamColor;
            playerKind = self->m_playerKind;
            int oldCharacter = fn_10_12010(self, self->m_charKind);
            self->setCharPic(oldCharacter, playerKind, color, team, teamColor, teamSet);
        }
        self->m_charColorNo = color;
    }
    int character = fn_10_12010(self, kind);
    float frame;
    switch (character) {
    case 40: frame = lbl_10_rodata_6A8; break;
    case 41: frame = lbl_10_rodata_6D4; break;
    default: frame = (float)(fn_800AF6F0(muMenu::exchangeMuSelchkind2MuStockchkind(character)) + 1); break;
    }
    self->m_muFranchiseIcon->setFrameTex(frame);
    self->setCharPic(character, self->m_playerKind, self->m_charColorNo,
        *(bool*)((char*)self->m_selCharTask + 0x5c8), self->m_teamColor, self->m_teamSet);
    self->m_charKind = (MuSelchkind)kind;
}