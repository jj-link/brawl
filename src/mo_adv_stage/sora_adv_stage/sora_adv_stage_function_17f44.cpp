#include <st/loader/st_loader_manager.h>
#include <ft/ft_manager.h>
#include <gm/gm_global.h>
#pragma force_active on

struct Self {
    char pad0[0x7c]; int first; char pad80[0x2c]; int second;
    char padb0[0xc]; int state; char padc0[0x10]; unsigned char d0, d1;
};
extern "C" void fn_40_183E8(Self*);
extern "C" int fn_27_10AAEC(ftManager*, int);
extern "C" int fn_27_23AC10(void*);
extern "C" void fn_27_10A1AC(ftManager*, int);
inline unsigned char loaderState(stLoaderPlayer* p) {
    return !p ? 0 : p->isEmpty() ? 1 : !p->isLoad() ? 2 : 3 + (fn_27_23AC10(p) != 0);
}
struct Bits { unsigned char flag : 1; };
extern "C" void fn_40_17F44(Self* self) {
    stLoaderPlayer* p0 = g_stLoaderManager->m_loaderPlayers[0];
    stLoaderPlayer* p1 = g_stLoaderManager->m_loaderPlayers[1];
    gmPlayerInitData* data0 = p0 ? p0->getWatchPlayerInitData() : 0;
    gmPlayerInitData* data1 = p1 ? p1->getWatchPlayerInitData() : 0;
    bool two = ((Bits*)((char*)g_GameGlobal->m_advData + 0x606))->flag;
    switch (self->state) {
    case 0:
        fn_40_183E8(self); self->state = 1; break;
    case 1: {
        int kinds[2]; kinds[0] = *(unsigned char*)data0;
        for (int i = 0; i < 2; i++) {
            int id = g_ftManager->getEntryId(i);
            if (id != -1) kinds[i] = fn_27_10AAEC(g_ftManager, id);
        }
        if (kinds[0] == self->first && (!two || kinds[1] == self->second)) {
            self->state = 3; self->d0 = 0; break;
        }
        if (kinds[0] != self->first) {
            g_stLoaderManager->m_loaderPlayers[0]->removeEntity();
            ((unsigned char*)g_stLoaderManager->m_loaderPlayers[0])[0x55] = 0;
            *(unsigned char*)data0 = self->first;
            *(short*)((char*)data0 + 0x20) = 0;
            *(short*)((char*)data0 + 0x22) = 0;
        }
        if (two && kinds[1] != self->second) {
            g_stLoaderManager->m_loaderPlayers[1]->removeEntity();
            ((unsigned char*)g_stLoaderManager->m_loaderPlayers[1])[0x55] = 0;
            *(unsigned char*)data1 = self->second;
            *(short*)((char*)data1 + 0x20) = 0;
            *(short*)((char*)data1 + 0x22) = 0;
        }
        self->state = 2; break;
    }
    case 2:
        if (loaderState(g_stLoaderManager->m_loaderPlayers[0]) == 3)
            g_stLoaderManager->m_loaderPlayers[0]->entryEntity();
        if (two && loaderState(g_stLoaderManager->m_loaderPlayers[1]) == 3)
            g_stLoaderManager->m_loaderPlayers[1]->entryEntity();
        if (loaderState(g_stLoaderManager->m_loaderPlayers[0]) == 4) {
            if (!two || loaderState(g_stLoaderManager->m_loaderPlayers[1]) == 4) {
                self->state = 3; self->d0 = 0;
            } else {
                fn_27_10A1AC(g_ftManager, 0); self->d1 = 0;
            }
        }
        break;
    }
}