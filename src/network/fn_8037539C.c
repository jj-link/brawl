#include <types.h>
#pragma force_active on

typedef struct Config {
    char pad[0x40];
    int mode;
    int size;
} Config;

typedef struct Entry {
    int offset;
    int size;
} Entry;

typedef struct State {
    int unk0;
    u16 unk4;
    char pad6[2];
    Config *config;
    int state;
    int unk10;
    int unk14;
    char pad18[0x50 - 0x18];
    char *buffer;
    char pad54[0x60 - 0x54];
    void *table;
    u16 unk64;
    u16 unk66;
    char unk68[0x20];
    int unk88;
    int unk8C;
    int status;
    char pad94[8];
    void *unk9C;
} State;

extern s16 lbl_8059F980;
extern void *memcpy(void *, const void *, unsigned long);
extern int fn_8035A590(void *);
extern Entry *fn_8035A598(void *, int);
extern void fn_803733BC(void *);
extern char *fn_803734CC(char *, char *);
extern void fn_8037382C(void *, void *, int);
extern int fn_80373AA0(State *, int, int, int);
extern int fn_80373B7C(State *, int, int, int);
extern int fn_80373C54(State *, int);
extern int fn_80373ED4(State *, int, int, int, int);
extern int fn_8037442C(State *, void *, int);
extern void fn_80374778(State *);
extern int fn_80374D60(State *, int, int);
extern int fn_80375094(State *, int, int);
extern int fn_80377028(State *, int, int, int *);
extern int fn_803783C4(Config *, int, u16, u8 *, int);

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

static inline int send_message(State *self, u8 *buf)
{
    int offset;
    u16 sequence;
    int id;
    Config *config;
    s16 prefix;
    int result;

    config = self->config;
    offset = 0;
    sequence = self->unk4;
    id = self->unk0;
    if (config->mode == 2) {
        prefix = 3;
        memcpy(buf, &prefix, 2);
        offset = 2;
    }
    memcpy(buf + offset, &lbl_8059F980, 2);
    buf[offset += 2] = 0x68;
    result = fn_803783C4(config, id, sequence, buf, offset + 1);
    return ((u32)(-result | result) >> 31);
}

int fn_8037539C(State *self, int action, int data, int size)
{
    char buf2[0x20];
    char buf1[0x20];
    u8 message1[8];
    u8 message2[8];
    int done;
    int state;
    int flag;
    int result;
    Entry *entry;

    self->unk66++;

    if (action == 0) {
        state = self->state;
        if (state != 5 && state != 6) {
            if (reset_state(self, state, 7) == 0) {
                flag = 0;
            } else {
                goto success0;
            }
        } else if (fn_8035A590(self->unk9C) != 0) {
            if (fn_80373ED4(self, 0, data, size, 1) == 0) {
                flag = 0;
            } else {
                flag = 1;
            }
        } else if (fn_80373B7C(self, data, size, 1) == 0) {
            flag = 0;
        } else {
        success0:
            flag = 1;
        }
        if (flag == 0) {
            return 0;
        }
    } else if (action == 1) {
        state = self->state;
        if (state != 2) {
            flag = reset_state(self, state, 7);
            if (flag == 0) {
                result = 0;
            } else {
                result = 1;
            }
        } else if (size < 0x20) {
            flag = reset_state(self, state, 7);
            if (flag == 0) {
                result = 0;
            } else {
                result = 1;
            }
        } else {
            fn_803734CC(buf1, (char *)data);
            fn_803733BC(buf2);
            fn_803734CC(self->unk68, buf2);

            if (fn_80377028(self, 2, self->config->size + 0x47, &done) == 0) {
                result = 0;
            } else if (done != 0) {
                result = 1;
            } else {
                fn_8037382C(&self->buffer, buf1, 0x20);
                fn_8037382C(&self->buffer, buf2, 0x20);
                entry = fn_8035A598(self->table, fn_8035A590(self->table) - 1);
                if (fn_8037442C(self, self->buffer + entry->offset, entry->size) == 0) {
                    flag = 0;
                } else {
                    flag = 1;
                    self->status = 0;
                }
                if (flag == 0) {
                    result = 0;
                } else {
                    result = 1;
                    self->unk8C = self->unk88;
                }
            }
            if (result == 0) {
                result = 0;
            } else {
                self->state = 3;
                result = 1;
            }
        }
        if (result == 0) {
            return 0;
        }
    } else if (action == 2) {
        if (fn_80374D60(self, data, size) == 0) {
            return 0;
        }
    } else if (action == 3) {
        if (fn_80375094(self, data, size) == 0) {
            return 0;
        }
    } else if (action == 4) {
        state = self->state;
        if (state != 1) {
            flag = reset_state(self, state, 7);
            if (flag == 0) {
                result = 0;
            } else {
                result = 1;
            }
        } else {
            self->state = 5;
            result = fn_80373AA0(self, 0, 0, 0) != 0;
        }
        if (result == 0) {
            return 0;
        }
    } else if (action == 5) {
        state = self->state;
        if (state != 1) {
            flag = reset_state(self, state, 7);
            if (flag == 0) {
                result = 0;
            } else {
                result = 1;
            }
        } else {
            fn_80374778(self);
            if (send_message(self, message1) == 0) {
                result = 0;
            } else {
                result = fn_80373AA0(self, 2, data, size) != 0;
            }
        }
        if (result == 0) {
            return 0;
        }
    } else if (action == 6) {
        if (send_message(self, message2) == 0) {
            result = 0;
        } else {
            state = self->state;
            flag = reset_state(self, state, 2);
            result = flag != 0;
        }
        if (result == 0) {
            return 0;
        }
    }
    return 1;
}
