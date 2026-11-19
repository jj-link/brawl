#include <types.h>
#include <mu/selchar/mu_selchar_player_area.h>
#pragma force_active on

extern "C" int fn_10_110F8(muSelCharPlayerArea*, int);
extern "C" int fn_10_12010(muSelCharPlayerArea*, int);

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

extern "C" void fn_10_17A7C(muSelCharPlayerArea* self) {
    int kind = self->m_charKind;
    if ((u32)(kind - 40) > 1U) {
        unsigned char teamSet;
        int teamColor;
        int playerKind;
        bool team;
        int count = fn_10_110F8(self, kind);
        int color = self->m_charColorNo;
        do {
            --color;
            if (color < 0)
                color = count - 1;
        } while (used(self, kind, color));
        team = *(bool*)((char*)self->m_selCharTask + 0x5c8);
        if (!team) {
            teamSet = self->m_teamSet;
            teamColor = self->m_teamColor;
            playerKind = self->m_playerKind;
            int character = fn_10_12010(self, self->m_charKind);
            self->setCharPic(character, playerKind, color, team, teamColor, teamSet);
        }
        self->m_charColorNo = color;
    }
}
