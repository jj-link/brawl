#include <types.h>
#pragma force_active on
struct Player { char pad[0x25]; u8 type; char pad26[3]; u8 value; char pad2a[9]; u8 rank; char rest[0x278]; };
struct Mode { char pad[5]; u8 mode; };
struct Global { char pad[0x18]; Player* players; Mode* mode; };
extern "C" Global* g_GameGlobal;
extern "C" u16* fn_8004DA14(void*, int, int);
extern "C" void fn_80053C34() {
    Player* players = g_GameGlobal->players;
    if (g_GameGlobal->mode->mode == 1) {
        int count = 0;
        Player* p = players;
        u16* scores[4] = {0, 0, 0, 0};
        u16** score = scores;
        int order[4];
        int* out = order;
        for (int i = 0; i < 4; i++, p++, score++) {
            if (p->type != 3) {
                count++;
                *score = fn_8004DA14(g_GameGlobal, i, p->value);
                if (p->rank != 0) *out++ = i;
            }
        }
        int exempt = -1;
        if (count == 4) {
            if (*scores[order[0]] < *scores[order[1]]) { int temp = order[0]; order[0] = order[1]; order[1] = temp; }
            if (*scores[order[0]] < *scores[order[2]]) { int temp = order[0]; order[0] = order[2]; order[2] = temp; }
            if (*scores[order[1]] < *scores[order[2]]) { int temp = order[1]; order[1] = order[2]; order[2] = temp; }
            if (*scores[order[0]] == *scores[order[1]] && players[order[0]].rank < players[order[1]].rank) { int temp = order[0]; order[0] = order[1]; order[1] = temp; }
            if (*scores[order[0]] == *scores[order[2]] && players[order[0]].rank < players[order[2]].rank) { int temp = order[0]; order[0] = order[2]; order[2] = temp; }
            if (*scores[order[1]] == *scores[order[2]] && players[order[1]].rank < players[order[2]].rank) { int temp = order[1]; order[1] = order[2]; order[2] = temp; }
            exempt = order[2];
        }
        score = scores;
        for (int i = 0; i < 4; players++, score++, i++) {
            u16* entry;
            if (players->type != 3 && (entry = *score) != 0) {
                u16 value = *entry;
                if (players->rank == 0) {
                    value += 20;
                    if (value > 300) value = 300;
                } else {
                    switch (count) {
                    case 2:
                        if (value >= 20) value -= 20;
                        else value = 0;
                        break;
                    case 3:
                    case 4:
                        if (i != exempt) value = value >= 10 ? (u16)(value - 10) : 0;
                        break;
                    }
                }
                *entry = value;
            }
        }
    }
}