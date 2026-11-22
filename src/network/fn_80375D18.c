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
    int arg;
    u16 seq;
} Entry;

typedef struct State {
    int unk0;
    u16 unk4;
    char pad6[2];
    Config *config;
    int unkC;
    int unk10;
    int unk14;
    char pad18[0x44 - 0x18];
    char *buffer;
    char pad48[0x5C - 0x48];
    void *table;
    char pad60[6];
    u16 seq;
    char pad68[0x90 - 0x68];
    int status;
    u32 time;
} State;

extern s16 lbl_8059F980;
extern void fn_80374778(State *);
extern int fn_80373AA0(State *, int, int, int);
extern int fn_80373C54(State *, int);
extern int fn_80374C30(State *, int);
extern u32 fn_8035D728(void);
extern int fn_8037539C(State *, int, void *, int);
extern int fn_8035A590(void *);
extern Entry *fn_8035A598(void *, int);
extern void fn_8035A918(void *, int);
extern void fn_803738B8(void *, int, int);
extern int fn_80375B6C(State *, int, int, void *, int, int *);
extern int fn_803783C4(Config *, int, u16, u8 *, int);
extern void *memcpy(void *, const void *, u32);

int fn_80375D18(State *self, int arg1, u8 *data, int len)
{
    u8 buf[8];
    int done;
    s16 sp;
    int flag;
    u8 *p;
    int size;
    int offset;
    int start, n, high, count, j, idx;
    int payload_len;
    u8 *payload;
    u16 seq;
    u16 ack;
    Entry *entry;
    int tmp;
    u16 port;
    Config *cfg;

    cfg = self->config;
    size = cfg->size + 7;
    if (len < size) {
        int state = self->unkC;
        if (state < 5) {
            if (self->unk10 != 0) {
                fn_80374778(self);
                if (fn_80373AA0(self, 7, 0, 0) == 0) {
                    flag = 0;
                    goto end1;
                }
            } else {
                if (state == 4)
                    self->unk14 = 1;
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
        return flag != 0;
    }

    p = data + cfg->size;
    seq = (p[3] << 8) | p[4];
    ack = (p[5] << 8) | p[6];
    if (cfg->mode == 2 && arg1 == 0) {
        p[5] = data[0];
        ((u8 *)((u32)self->config->size + (u32)data))[6] = data[1];
        offset = size - self->config->size;
        payload = data + offset;
        payload_len = len - offset;
    } else {
        payload = data + size;
        payload_len = len - size;
    }

    if (fn_80374C30(self, ack) == 0)
        return 0;

    if (seq == self->seq) {
        if (self->status == 0) {
            self->status = 1;
            self->time = fn_8035D728();
        }
        if (fn_8037539C(self, arg1, payload, payload_len) == 0)
            return 0;

again:
        idx = fn_8035A590(self->table) - 1;
        while (idx >= 0) {
            entry = fn_8035A598(self->table, idx);
            if (entry->seq == self->seq) {
                if (fn_8037539C(self, entry->arg,
                                self->buffer + entry->offset,
                                entry->size) == 0) {
                    flag = 0;
                    goto end2;
                }
                start = entry->offset;
                n = entry->size;
                high = 0;
                fn_8035A918(self->table, idx);
                count = fn_8035A590(self->table);
                for (j = 0; j < count; j++) {
                    entry = fn_8035A598(self->table, j);
                    if (entry->offset > start) {
                        entry->offset -= n;
                        tmp = entry->offset + entry->size;
                        if (high > tmp)
                            tmp = high;
                        high = tmp;
                    }
                }
                fn_803738B8(&self->buffer, start, n);
                goto again;
            }
            idx--;
        }
        flag = 1;
end2:
        if (flag == 0)
            return 0;
        return 1;
    }

    if ((s16)(seq - self->seq) < 0) {
        if (self->status == 0) {
            self->status = 1;
            self->time = fn_8035D728();
        }
        return 1;
    }

    if (fn_80375B6C(self, arg1, seq, payload, payload_len, &done) == 0)
        return 0;

    if (done != 0) {
        Config *cfg = self->config;
        int send_tmp;
        u16 send_port;
        offset = 0;
        send_port = self->unk4;
        send_tmp = self->unk0;
        if (cfg->mode == 2) {
            sp = 3;
            memcpy(buf, &sp, 2);
            offset = 2;
        }
        memcpy(buf + offset, &lbl_8059F980, 2);
        buf[offset += 2] = 0x68;
        n = fn_803783C4(cfg, send_tmp, send_port, buf, offset + 1);
        if (((u32)(-n | n) >> 31) == 0) {
            flag = 0;
        } else {
            int state = self->unkC;
            if (state < 5) {
                if (self->unk10 != 0) {
                    fn_80374778(self);
                    if (fn_80373AA0(self, 1, 0, 0) == 0) {
                        flag = 0;
                        goto end3;
                    }
                } else {
                    if (state == 4)
                        self->unk14 = 1;
                    fn_80374778(self);
                }
            } else if (state != 7) {
                fn_80374778(self);
                if (fn_80373C54(self, 4) == 0) {
                    flag = 0;
                    goto end3;
                }
            }
            flag = 1;
        }
end3:
        if (flag == 0)
            return 0;
    }
    return 1;
}
