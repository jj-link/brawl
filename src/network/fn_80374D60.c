#include <types.h>
#pragma force_active on

typedef struct Config {
    char pad[0x44];
    int size;
} Config;

typedef struct Entry {
    int offset;
    int size;
} Entry;

typedef struct State {
    char pad0[8];
    Config *config;
    int unkC;
    int unk10;
    int unk14;
    char pad18[0x38 - 0x18];
    void *unk38;
    int unk3C;
    char pad40[0x50 - 0x40];
    char *buffer;
    char pad54[0x60 - 0x54];
    void *table;
    char pad64[0x68 - 0x64];
    int unk68;
    char pad6C[0x90 - 0x6C];
    int status;
} State;

extern void fn_80374778(State *self);
extern int fn_80373AA0(State *self, int a1, int a2, int a3);
extern int fn_80373C54(State *self, int a1);
extern int fn_803736BC(int a1, void *a2);
extern char *fn_803734CC(char *out, char *in);
extern void fn_8037382C(void *buf, void *src, int len);
extern int fn_80377028(State *self, int a1, int a2, int *done);
extern int fn_8035A590(void *table);
extern Entry *fn_8035A598(void *table, int index);
extern int fn_8037442C(State *self, void *data, int size);
extern void fn_8035E00C(void *p);

int fn_80374D60(State *self, int param2, int param3) {
    char buf[0x20];
    int done;
    int flag;
    int state;
    void *ptr;
    int c;
    int result;
    Entry *entry;

    state = self->unkC;
    if (state != 0) {
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
        return (flag != 0);
    }

    if (param3 < 0x40) {
        if (state < 5) {
            if (self->unk10 != 0) {
                fn_80374778(self);
                if (fn_80373AA0(self, 7, 0, 0) == 0) {
                    flag = 0;
                    goto end2;
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
                goto end2;
            }
        }
        flag = 1;
    end2:
        return (flag != 0);
    }

    if (fn_803736BC(param2, (char *)self + 0x68) == 0) {
        state = self->unkC;
        if (state < 5) {
            if (self->unk10 != 0) {
                fn_80374778(self);
                if (fn_80373AA0(self, 7, 0, 0) == 0) {
                    flag = 0;
                    goto end3;
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
                goto end3;
            }
        }
        flag = 1;
    end3:
        return (flag != 0);
    }

    fn_803734CC(buf, (char *)param2 + 0x20);
    c = self->unk3C;
    ptr = self->unk38;

    if (fn_80377028(self, 3, c + self->config->size + 0x27, &done) == 0) {
        result = 0;
        goto test;
    }
    if (done != 0) {
        result = 1;
        goto test;
    }
    fn_8037382C(&self->buffer, buf, 0x20);
    fn_8037382C(&self->buffer, ptr, c);
    entry = fn_8035A598(self->table, fn_8035A590(self->table) - 1);
    if (fn_8037442C(self, self->buffer + entry->offset, entry->size) == 0) {
        flag = 0;
    } else {
        flag = 1;
        self->status = 0;
    }
    result = (flag != 0);
test:
    if (result == 0) {
        return 0;
    }
    if (self->unk38 != NULL) {
        fn_8035E00C(self->unk38);
        self->unk38 = NULL;
    }
    self->unkC = 1;
    return 1;
}
