#include <types.h>
#pragma force_active on

typedef struct Config {
    char pad[0x44];
    int size;
} Config;

typedef struct State {
    char pad0[8];
    Config *config;
    int unkC;
    int unk10;
    int unk14;
    char pad18[0x34 - 0x18];
    int unk34;
} State;

extern void fn_80374778(State *);
extern int fn_80373AA0(State *, int, int, int);
extern int fn_80373C54(State *, int);
extern int fn_80373D10(State *, int);
extern int fn_8037442C(State *, void *, int);
extern int fn_80374C30(State *, int);
extern int fn_80376168(State *, void *, int);
extern u32 fn_8035D728(void);
extern int fn_803F6150(const void *, const void *, unsigned long);
extern void *memcpy(void *, const void *, unsigned long);
extern s8 lbl_8059F984;

static inline int reset_state(State *self, int state, int mode)
{
    int is_six = state == 6;

    if (state < 5) {
        if (self->unk10 != 0) {
            fn_80374778(self);
            if (fn_80373AA0(self, mode, 0, 0) == 0) {
                return 0;
            }
        } else {
            if (state == 4) {
                self->unk14 = 1;
            }
            fn_80374778(self);
        }
    } else if (state != 7) {
        fn_80374778(self);
        if (fn_80373C54(self, mode == 2 ? !is_six : 2) == 0) {
            return 0;
        }
    }
    return 1;
}

int fn_80376350(State *arg0, int cmd, u8 *buf, int len) {
    State *self;
    u8 *ptr;
    int remaining;
    int state;
    int flag;
    int result;
    int local;

    self = arg0;
    ptr = buf + (self->config->size + 3);
    remaining = len - (self->config->size + 3);

    if (cmd == 0x64) {
        if (remaining != 2) {
            state = self->unkC;
            if (state < 5) {
                if (self->unk10 != 0) {
                    fn_80374778(self);
                    if (fn_80373AA0(self, 7, 0, 0) == 0) {
                        flag = 0;
                        goto end1;
                    }
                } else {
                    if (state == 4) {
                        self->unk14 = 1;
                    }
                    fn_80374778(self);
                }
            } else if (state != 7) {
                fn_80374778(self);
                if (fn_80373C54(self, 2) == 0) {
                    flag = 0;
                    goto end1;
                }
            }
            flag = 1;
        end1:
            if (flag == 0) {
                result = 0;
            } else {
                result = 1;
            }
        } else {
            result = (fn_80374C30(self, (ptr[0] << 8) | ptr[1]) != 0);
        }
        if (result == 0) {
            return 0;
        }
    } else if (cmd == 0x65) {
        if (fn_80376168(self, ptr, remaining) == 0) {
            return 0;
        }
    } else if (cmd == 0x66) {
        buf[2] = 0x67;
        if (fn_8037442C(self, buf, len) == 0) {
            return 0;
        }
    } else if (cmd == 0x67) {
        if (self->unk34 == 0) {
            result = 1;
        } else if ((u32)remaining != 8) {
            result = 1;
        } else if (fn_803F6150(ptr, &lbl_8059F984, 4) != 0) {
            result = 1;
        } else {
            memcpy(&local, ptr + 4, 4);
            result = (fn_80373D10(self, fn_8035D728() - local) != 0);
        }
        if (result == 0) {
            return 0;
        }
    } else if (cmd == 0x68) {
        state = self->unkC;
        if (state == 7) {
            result = 1;
        } else {
            result = (reset_state(self, state, 2) != 0);
        }
        if (result == 0) {
            return 0;
        }
    }
    return 1;
}
