#include <mu/menu.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" int getLanguage__10GameGlobalFv(GameGlobal*);
struct Pair { int id; int length; };
extern "C" Pair lbl_13_rodata_0[];
struct Player { int kind; int type; };
struct Self {
    char pad[0xb0];
    int mode;
    int count;
    Player players[10];
    char pad2[4];
    Pair sounds[16];
    int soundCount;
};

extern "C" void fn_13_620(Self* self) {
    int mode = self->mode;
    int modeIndex = -1;
    if (mode >= 2) modeIndex = mode - 2;
    if (modeIndex < 0) {
        Pair* slot = &self->sounds[self->soundCount];
        slot->id = 0x203e;
        slot->length = 60;
        self->soundCount++;
        Self* player;
        int i;
        int count;
        if (self->mode == 1) {
            Pair* slot = &self->sounds[self->soundCount];
            slot->id = 0x203c;
            slot->length = 30;
            self->soundCount++;
            count = 1;
        } else if (self->mode >= 2) {
            count = -1;
        } else {
            count = self->count;
        }
        player = self;
        for (i = 0; i < count; player = (Self*)((char*)player + 8), i++) {
            if (i > 0) {
                if (i < count - 1) {
                    Pair* slot = &self->sounds[self->soundCount];
                    slot->id = -1;
                    slot->length = 10;
                    self->soundCount++;
                } else {
                    Pair* slot = &self->sounds[self->soundCount];
                    slot->id = 0x203d;
                    slot->length = 43;
                    self->soundCount++;
                }
            }
            int type;
            if (i < 0 && i >= (self->mode >= 2 ? -1 : self->count)) {
                type = 4;
            } else {
                switch (self->mode) {
                case 0: type = player->players[0].type; break;
                case 1: type = 0; break;
                default: type = 4; break;
                }
            }
            int id = lbl_13_rodata_0[type].id;
            int length = lbl_13_rodata_0[type].length;
            if ((unsigned)(id + 0x10000) != 0xffffU) {
                Pair* slot = &self->sounds[self->soundCount];
                slot->id = id;
                slot->length = length;
                self->soundCount++;
            }
            int voice = muMenu::exchangeSelchkind2SelCharVoice(player->players[0].kind);
            if ((unsigned)(voice + 0x10000) != 0xffffU) {
                int voiceLength;
                if (getLanguage__10GameGlobalFv(g_GameGlobal) == 0)
                    voiceLength = muMenu::exchangeSelCharVoice2SelCharVoiceLengthE(player->players[0].kind);
                else
                    voiceLength = muMenu::exchangeSelCharVoice2SelCharVoiceLengthJ(player->players[0].kind);
                Pair* slot = &self->sounds[self->soundCount];
                slot->id = voice;
                slot->length = voiceLength;
                self->soundCount++;
            }
        }
    } else {
        Pair* slot = &self->sounds[self->soundCount];
        slot->id = 0x2035;
        slot->length = 90;
        self->soundCount++;
    }
}