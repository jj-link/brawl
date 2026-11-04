#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
extern void *memcpy(void *, const void *, u32);
extern s32 strlen(const char *);
extern u16 SONtoHs(u16);
extern void fn_803876B0(void *, void *, s32);
extern void fn_8038795C(void *, u8 *, s32);
extern s32 fn_8035A460(s32, s32, s32);
extern s32 fn_8035A590(s32);
extern void fn_8035A5C8(s32, void *);
extern s32 fn_80388590(void *);
extern s32 *fn_8035B1C4(s32, void *);
extern void fn_8035B078(s32, void *);
extern s8 *fn_8035D654(const s8 *);
extern s32 fn_8038B680(void *, u8 *, s32);
extern void fn_803F602C(void *, const void *, s32);
extern s32 lbl_805A1128;
typedef struct Obj {
    s32 state;
    s32 unk4;
    s32 entries;
    u8 padC[0x54 - 0xC];
    s8 key[0x20];
    s8 seed[8];
    u8 *buffer;
    s32 length;
    s8 *names[255];
    s32 nameCount;
    s32 expected;
    void (*callback)(void *, s32, s32, s32);
    u8 pad48C[8];
    s32 user;
    u8 pad498[0x6A4 - 0x498];
    s32 word;
    s32 pad6A8;
    u16 value;
    u16 pad6AE;
    s8 *message;
    u8 pad6B4[0x6C0 - 0x6B4];
    u8 cipher[0x108];
    u32 flags;
    s32 phase;
    u16 port;
} Obj;
static inline s32 findNul(const s8 *q, s32 len) {
    s32 i = 0;
    for (; i < len; i++, q++) {
        if (*q == 0) return i + 1;
    }
    return -1;
}
static inline s8 *intern(Obj *self, const s8 *name) {
    s32 local[2];
    s32 *p;
    local[0] = (s32)name;
    p = fn_8035B1C4(fn_80388590(self), local);
    if (p) {
        p[1]++;
        return (s8 *)p[0];
    }
    local[0] = (s32)fn_8035D654(name);
    local[1] = 1;
    fn_8035B078(fn_80388590(self), local);
    return (s8 *)local[0];
}
static inline void mix(Obj *self, u8 *p, s32 start, s32 n) {
    s32 keylen;
    s32 i;
    s8 *key;
    keylen = strlen((char *)self->key);
    key = self->key;
    for (i = 0; i < n; i++) {
        s8 c = self->seed[i % 8] ^ p[start + i];
        self->seed[(i * key[i % keylen]) % 8] ^= c;
    }
}
s32 fn_8038B83C(Obj *self) {
    s32 used;
    s32 start;
    s32 n;
    u8 *p = self->buffer;
    s32 len = self->length;
    switch (self->phase) {
    case 0: {
        if (len < 1) break;
        used = (*p ^ 0xEC) + 2;
        if (len < used) break;
        start = used;
        n = p[used - 1] ^ 0xEA;
        used += n;
        if (len < used) break;
        mix(self, p, start, n);
        fn_803876B0(self->cipher, self->seed, 8);
        self->phase = 1;
        memcpy(&self->port, p + 1, 2);
        self->port = SONtoHs(self->port);
        p += used;
        len -= used;
        fn_8038795C(self->cipher, p, len);
    }
    case 1: {
        if (len < 6) break;
        memcpy(&self->word, p, 4);
        self->callback(self, 6, lbl_805A1128, self->user);
        memcpy(&self->value, p + 4, 2);
        if (self->value == 0xFFFF) {
            s32 n;
            s32 j;
            for (j = 0; j < len - 6; j++) {
                if (((s8 *)p)[(u32)j + 6] == 0) {
                    n = j + 1;
                    goto messageFound;
                }
            }
            n = -1;
messageFound:
            if (n == -1) break;
            self->message = (s8 *)p + 6;
            self->callback(self, 5, lbl_805A1128, self->user);
            if (!self->buffer) break;
        }
        p += 6;
        len -= 6;
        if ((self->flags & 2) || self->value == 0xFFFF) {
            self->phase = 5;
            self->state = 2;
            break;
        }
        self->phase = 2;
        self->expected = -1;
    }
    case 2: {
        if (self->expected == -1) {
            if (len < 1) break;
            self->expected = *p;
            self->entries = fn_8035A460(8, self->expected, 0);
            if (!self->entries) return 5;
            p++;
            len--;
        }
        while (self->expected > fn_8035A590(self->entries)) {
            s32 n;
            struct { s8 *name; s32 type; } entry;
            if (len < 2) break;
            {
                s32 j;
                for (j = 0; j < len - 1; j++) {
                    if (((s8 *)p)[(u32)j + 1] == 0) {
                        n = j + 1;
                        goto entryFound;
                    }
                }
                n = -1;
            }
entryFound:
            if (n == -1) break;
            entry.type = *p;
            {
                s32 local[2];
                s32 *found;
                s8 *name;
                local[0] = (s32)((s8 *)p + 1);
                found = fn_8035B1C4(fn_80388590(self), local);
                if (found) {
                    found[1]++;
                    name = (s8 *)found[0];
                } else {
                    local[0] = (s32)fn_8035D654((s8 *)p + 1);
                    local[1] = 1;
                    fn_8035B078(fn_80388590(self), local);
                    name = (s8 *)local[0];
                }
                entry.name = name;
            }
            fn_8035A5C8(self->entries, &entry);
            p += n + 1;
            len -= n + 1;
        }
        if (self->expected > fn_8035A590(self->entries)) break;
        self->phase = 3;
        self->expected = -1;
    }
    case 3: {
        if (self->expected == -1) {
            if (len < 1) break;
            self->expected = *p;
            p++;
            len--;
            self->nameCount = 0;
        }
        while (self->expected > self->nameCount) {
            s32 n = findNul((s8 *)p, len);
            s8 *name;
            if (n == -1) break;
            name = intern(self, (s8 *)p);
            p += n;
            len -= n;
            self->names[self->nameCount++] = name;
        }
        if (self->expected > self->nameCount) break;
        self->phase = 4;
    }
    case 4: {
        s32 n;
        if (len < 5) break;
        do {
            n = fn_8038B680(self, p, len);
            if (n == -2) return 5;
            if (n == -1) {
                self->phase = 5;
                self->state = 2;
                len -= 5;
                p += 5;
                self->callback(self, 3, lbl_805A1128, self->user);
                break;
            }
            p += n;
            len -= n;
            if (!self->buffer) n = 0;
        } while (n);
    }
    }
    if (!self->buffer) return 0;
    if (len != 0) fn_803F602C(self->buffer, p, len);
    self->length = len;
    return 0;
}
