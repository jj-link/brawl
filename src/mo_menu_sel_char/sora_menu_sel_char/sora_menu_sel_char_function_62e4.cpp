#include <gm/gm_global.h>
#include <snd/snd_system.h>
#pragma force_active on

struct Cursor;
struct Player { char pad[0x1a8]; Cursor* cursor; };
struct Menu { char pad[0x44]; Player* players[0x181]; int count; };

extern "C" {
int fn_10_A880(Menu*);
void fn_10_6914(Menu*, int);
void fn_10_1AA34(Cursor*);
void fn_10_6C84(Menu*, int);
void fn_10_6EDC(Menu*);
void fn_10_6FFC(Menu*, int);
void fn_10_9788(Menu*, int);
void fn_10_1B410(Cursor*);
void fn_10_9A2C(Menu*);
void fn_10_9F40(Menu*);
void fn_10_A400(Menu*);
void fn_10_F194(Menu*);
int fn_10_AEA0(Menu*);
void fn_10_4A54(Menu*, int, int, int);
void fn_10_F13C(Menu*);
}

extern "C" void fn_10_62E4(Menu* self) {
    int i;
    if (fn_10_A880(self) != 0) {
        return;
    }
    {
    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];

    int c1;
    if (state >= 0 && state < 4) c1 = 1; else c1 = 0;
    if (c1 != 0) {
        c1 = 0;
    } else {
        if (state >= 4 && state < 0xc) c1 = 1; else c1 = 0;
        if (c1 != 0) {
            c1 = 1;
        } else {
            int t;
            if (state >= 0xc && state < 0x10) t = 1; else t = 0;
            c1 = 3;
            if (t != 0) c1 = 2;
        }
    }
    int g;
    if (c1 != 1) {
        int c2;
        if (state >= 0 && state < 4) c2 = 1; else c2 = 0;
        if (c2 != 0) {
            c2 = 0;
        } else {
            if (state >= 4 && state < 0xc) c2 = 1; else c2 = 0;
            if (c2 != 0) {
                c2 = 1;
            } else {
                int t;
                if (state >= 0xc && state < 0x10) t = 1; else t = 0;
                c2 = 3;
                if (t != 0) c2 = 2;
            }
        }
        int r13;
        if (c2 != 0) {
            int c3;
            if (state >= 0 && state < 4) c3 = 1; else c3 = 0;
            if (c3 != 0) {
                c3 = 0;
            } else {
                if (state >= 4 && state < 0xc) c3 = 1; else c3 = 0;
                if (c3 != 0) {
                    c3 = 1;
                } else {
                    int t;
                    if (state >= 0xc && state < 0x10) t = 1; else t = 0;
                    c3 = 3;
                    if (t != 0) c3 = 2;
                }
            }
            if (c3 != 1) goto nonstandard1;
        }
        r13 = 0;
        goto classified1;
    nonstandard1:
        r13 = 1;
    classified1:
        if (r13 == 0 && state != 1) goto allowed1;
    }
    g = 0;
    goto classified2;
allowed1:
    g = 1;
classified2:
    if (g != 0) {
        for (i = 0; i < self->count; i++) {
            fn_10_6914(self, i);
        }
    }
    }
    for (i = 0; i < self->count; i++) {
        fn_10_1AA34(self->players[i]->cursor);
    }
    for (i = 0; i < self->count; i++) {
        fn_10_6C84(self, i);
    }
    if ((int)((unsigned char*)g_GameGlobal->m_selCharData)[4] == 0xc) {
        fn_10_6EDC(self);
    }
    for (i = 0; i < self->count; i++) {
        fn_10_6FFC(self, i);
    }

    {
    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    int c4;
    if (state >= 0 && state < 4) c4 = 1; else c4 = 0;
    if (c4 != 0) {
        c4 = 0;
    } else {
        if (state >= 4 && state < 0xc) c4 = 1; else c4 = 0;
        if (c4 != 0) {
            c4 = 1;
        } else {
            int t;
            if (state >= 0xc && state < 0x10) t = 1; else t = 0;
            c4 = 3;
            if (t != 0) c4 = 2;
        }
    }
    int g3;
    if (c4 != 0) {
        int c5;
        if (state >= 0 && state < 4) c5 = 1; else c5 = 0;
        if (c5 != 0) {
            c5 = 0;
        } else {
            if (state >= 4 && state < 0xc) c5 = 1; else c5 = 0;
            if (c5 != 0) {
                c5 = 1;
            } else {
                int t;
                if (state >= 0xc && state < 0x10) t = 1; else t = 0;
                c5 = 3;
                if (t != 0) c5 = 2;
            }
        }
        if (c5 != 1) goto nonstandard3;
    }
    g3 = 0;
    goto classified3;
nonstandard3:
    g3 = 1;
classified3:
    if (g3 != 0) {
        for (i = 0; i < self->count; i++) {
            fn_10_9788(self, i);
        }
    }
    }
    {
        int n = 0;
        Menu* p = self;
        for (; n < self->count; n++) {
            fn_10_1B410(p->players[0]->cursor);
            p = (Menu*)((char*)p + 4);
        }
    }
    fn_10_9A2C(self);
    fn_10_9F40(self);
    fn_10_A400(self);
    fn_10_F194(self);

    int t3 = fn_10_AEA0(self);
    if (t3 < 0) {
        return;
    }
    g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);

    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    int c6;
    if (state >= 0 && state < 4) c6 = 1; else c6 = 0;
    if (c6 != 0) {
        c6 = 0;
    } else {
        if (state >= 4 && state < 0xc) c6 = 1; else c6 = 0;
        if (c6 != 0) {
            c6 = 1;
        } else {
            int t;
            if (state >= 0xc && state < 0x10) t = 1; else t = 0;
            c6 = 3;
            if (t != 0) c6 = 2;
        }
    }
    int g4;
    if (c6 != 0) {
        int c7;
        if (state >= 0 && state < 4) c7 = 1; else c7 = 0;
        if (c7 != 0) {
            c7 = 0;
        } else {
            if (state >= 4 && state < 0xc) c7 = 1; else c7 = 0;
            if (c7 != 0) {
                c7 = 1;
            } else {
                int t;
                if (state >= 0xc && state < 0x10) t = 1; else t = 0;
                c7 = 3;
                if (t != 0) c7 = 2;
            }
        }
        if (c7 != 1) goto nonstandard4;
    }
    g4 = 0;
    goto classified4;
nonstandard4:
    g4 = 1;
classified4:
    if (g4 != 0) {
        fn_10_4A54(self, 6, 0, 0);
    } else {
        fn_10_4A54(self, 3, t3, 0);
        fn_10_F13C(self);
    }
}
