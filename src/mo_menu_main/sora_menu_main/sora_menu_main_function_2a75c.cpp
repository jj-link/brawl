#include <snd/snd_system.h>
#pragma force_active on

struct MenuBase {
    char pad0[0x668];
};
struct Menu : MenuBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void reset(int);
    char pad66C[8];
    int state;
    char pad678[8];
    void* object;
    char pad684[0x10];
    int selection;
    int scroll;
    int cursor;
    int mode;
    int count;
};

extern "C" {
unsigned fn_18_12E0(Menu*);
void fn_800B330C(void*, void*, int);
void fn_2_2A97C(Menu*, int);
void fn_2_2A3B8(Menu*, int);
extern char lbl_2_data_33D0[];

int fn_2_2A75C(Menu* self) {
    int changed = 0;
    unsigned flags = fn_18_12E0(self);
    if ((flags & 8) && self->mode == 0) {
        self->mode = 1;
        changed = 1;
    }
    if ((flags & 4) && self->mode == 1) {
        changed = 1;
        self->mode = 0;
    }
    if (self->mode == 0) {
        if ((flags & 2) && self->selection < self->count - 1) {
            self->selection++;
            changed = 1;
            fn_800B330C(self->object, lbl_2_data_33D0 + 0x28, 0);
            self->reset(0);
            self->state = 1;
            fn_2_2A97C(self, self->selection);
        }
        if ((flags & 1) && self->selection > 0) {
            self->selection--;
            changed = 1;
            fn_800B330C(self->object, lbl_2_data_33D0 + 0x14, 0);
            self->reset(0);
            self->state = 2;
            fn_2_2A97C(self, self->selection);
        }
    } else {
        if (flags & 2) {
            if (self->cursor < 6 && self->cursor < 0x1A) {
                changed = 1;
                self->cursor++;
            } else if (self->scroll + 7 < 0x1B) {
                changed = 1;
                self->scroll++;
            }
        }
        if (flags & 1) {
            if (self->cursor > 0) {
                changed = 1;
                self->cursor--;
            } else if (self->scroll > 0) {
                changed = 1;
                self->scroll--;
            }
        }
    }
    if (changed) {
        fn_2_2A3B8(self, 1);
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
    }
    return 1;
}
}
