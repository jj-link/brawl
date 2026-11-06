#include <gm/gm_global.h>
#include <ms/ms_message.h>
#include <mt/mt_prng.h>
#include <mu/menu.h>
#include <string.h>
#pragma force_active on

extern "C" int exchangeMuSelchkind2GmCharacterKind__6muMenuFiii(int);
extern "C" unsigned int fn_8004DA94(GameGlobal*, int);
extern "C" unsigned int fn_8004D9A8(GameGlobal*, int);
struct PlayerFlag { unsigned char : 1; unsigned char value : 1; unsigned char : 6; };
struct ChoiceBytes { unsigned char v[3]; };
extern ChoiceBytes lbl_3_rodata_85CC;

extern "C" void fn_3_EA40(unsigned char* self) {
    gmSelCharData* data = g_GameGlobal->m_selCharData;
    ((unsigned char*)data)[0x33] = 0;
    gmPlayerInitData* player = data->m_playersInitData;
    unsigned char* kind = (unsigned char*)data + 0xa;
    unsigned char* entry = self;
    char* text = (char*)self + 0x108;
    unsigned char* controller = self;
    unsigned int i;
    for (i = 0; i < *(unsigned int*)(self + 0x300); ++i) {
        *kind = *(int*)(entry + 0x120);
        if (*(int*)(entry + 0x120) == 0x1b) {
            ChoiceBytes choices = lbl_3_rodata_85CC;
            *kind = choices.v[randi(2)];
        }
        *(unsigned char*)player = exchangeMuSelchkind2GmCharacterKind__6muMenuFiii(*kind);
        switch (*(int*)(entry + 0x104)) {
        case 0: player->m_state = 0; break;
        case 1:
            player->m_state = 1;
            player->m_cpuRank = entry[0x12c];
            break;
        case 2: player->m_state = 3; break;
        }
        player->m_colorFileNo = entry[0x124];
        *(unsigned short*)player->_0x26 = *(unsigned short*)(entry + 0x12e);
        wchar_t name[6];
        Message::utf8to16(name, text);
        player->m_nameIndex = entry[0x11d];
        memcpy(player->m_name, name, 12);
        player->m_controllerNo = *(int*)(controller + 0x320) + 1;
        unsigned int nameIndex = entry[0x11d];
        if (nameIndex == 0x78) {
            if (player->m_state == 0) {
                unsigned int flag = fn_8004DA94(g_GameGlobal, (unsigned char)player->m_controllerNo - 1);
                ((PlayerFlag*)((unsigned char*)player + 0x1b))->value = flag;
            } else {
                ((unsigned char*)player)[0x1b] &= ~0x40;
            }
        } else {
            unsigned int flag = fn_8004D9A8(g_GameGlobal, nameIndex);
            ((PlayerFlag*)((unsigned char*)player + 0x1b))->value = flag;
        }
        ++player;
        kind += 4;
        entry += 0x2c;
        text += 0x2c;
        controller += 4;
    }
    for (unsigned int j = *(unsigned int*)(self + 0x300); j < 4; ++j) {
        data->m_playersInitData[j].m_state = 3;
    }
}
