#include <gf/gf_pad_system.h>
#pragma force_active on

struct Cursor;
struct TokenData { char pad[0x1b8]; int kind; };
struct Token { char pad[0x10]; Cursor* cursor; TokenData* data; };
struct Cursor {
    char pad[0x84];
    float x, y, z;
    float oldX, oldY, oldZ;
    char pad9c[4];
    Token* token;
    char pada4[0x28];
    float scale;
};
struct Player {
    char pad[0x1a8];
    Cursor* cursor;
    Token* token;
    int index;
    int state;
    char pad1b8[0x24];
    int controller;
};
struct Menu { char pad[0x44]; Player* players[1]; };

extern float lbl_10_rodata_74;
extern float lbl_10_rodata_0;
extern "C" int fn_10_14618(void*);
extern "C" void fn_10_148E8(void*, int);
extern "C" int fn_10_6BC8(void*);
extern "C" int fn_10_1BD70(void*);
extern "C" void fn_10_19F74(void*);
extern "C" void fn_10_1C3E8(void*, void*);
extern "C" void fn_10_DB04(void*, float*, int);
extern "C" void fn_10_1BBF4(void*, float*);
extern "C" void fn_10_869C(void*, int, int);
extern "C" void fn_10_95B8(void*, int, int);
extern "C" int fn_10_19D68(void*);
extern "C" int fn_10_1C3E0(void*);
extern "C" void fn_10_EFA0(void*, int);

extern "C" void fn_10_6914(Menu* self, int port) {
    Player** slot = &self->players[port];
    Cursor* cursor;
    Player* player = *slot;
    cursor = player->cursor;
    gfPadStatus status;
    float pos[2];
    if (player->controller >= 0) {
        if (fn_10_14618(player) == 4) {
            int available = fn_10_6BC8(self);
            if (available >= 0) {
                fn_10_148E8(player, available);
                return;
            }
            fn_10_148E8(player, -1);
            if (player->state != 0) {
                Token* token = cursor->token;
                if (token) {
                    int kind;
                    int owner = fn_10_1BD70(token);
                    if (port != owner || player->state == 2) {
                        cursor->token = 0;
                        cursor->scale = lbl_10_rodata_74;
                        fn_10_19F74(cursor);
                        fn_10_1C3E8(token, 0);
                        kind = token->data->kind;
                        if (kind == 0x28) {
                            kind = 0x29;
                            fn_10_DB04(self, pos, 0x29);
                            fn_10_1BBF4(token, pos);
                        }
                        fn_10_869C(self, owner, kind);
                    }
                }
                if (player->state == 1) {
                    fn_10_95B8(self, port, 0);
                    slot = (Player**)self->players[player->index]->token;
                    player = (Player*)((Token*)slot)->cursor;
                    if (player && port != fn_10_19D68(player)) {
                        ((Cursor*)player)->token = 0;
                        ((Cursor*)player)->scale = lbl_10_rodata_74;
                        fn_10_19F74(player);
                        fn_10_1C3E8(slot, 0);
                    }
                    cursor->token = (Token*)slot;
                    if (slot == 0) {
                        cursor->scale = lbl_10_rodata_74;
                        fn_10_19F74(cursor);
                    } else {
                        cursor->scale = lbl_10_rodata_0;
                        fn_10_19F74(cursor);
                    }
                    fn_10_1C3E8(slot, cursor);
                    fn_10_EFA0(self, fn_10_1C3E0(slot));
                }
            }
            return;
        } else if (fn_10_14618(player) != 0) {
            g_gfPadSystem->getSysPadStatus(port, &status);
            if (status.m_error == 0) {
                fn_10_148E8(player, port);
                return;
            }
        }
    }
    if (player->controller < 0) {
        g_gfPadSystem->getSysPadStatus(port, &status);
        if (status.m_error == 0) {
            fn_10_148E8(player, port);
            Cursor* c = (*slot)->cursor;
            c->oldX = c->x;
            c->oldY = c->y;
            c->oldZ = c->z;
        } else {
            int available = fn_10_6BC8(self);
            if (available >= 0)
                fn_10_148E8(player, available);
        }
    }
}
