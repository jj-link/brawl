#pragma force_active on
typedef unsigned char u8;

void *memcpy(void *, const void *, unsigned long);
unsigned long strlen(const char *);

extern char lbl_80490080[];
extern char *lbl_804901F0[];

typedef enum { key_server, key_player, key_team, key_type_count } qr2_key_type;

typedef struct qr2_buffer_s {
    char buffer[0x578];
    int len;
} *qr2_buffer_t;

typedef struct qr2_keybuffer_s {
    u8 keys[0x100];
    int numkeys;
} *qr2_keybuffer_t;

typedef struct qr2_implementation_s {
    u8 pad[0x88];
    void (*server_key_callback)(int, qr2_buffer_t, void *);
    void (*player_key_callback)(int, int, qr2_buffer_t, void *);
    void (*team_key_callback)(int, int, qr2_buffer_t, void *);
    void (*key_list_callback)(qr2_key_type, qr2_keybuffer_t, void *);
    int (*playerteam_count_callback)(qr2_key_type, void *);
    u8 pad2[0x10C - 0x9C];
    void *udata;
} *qr2_t;

typedef struct SplitState {
    qr2_key_type keytype;
    int packetnum;
    int keyindex;
    int count;
    int index;
    struct qr2_keybuffer_s keys;
} SplitState;

static inline int qr2_buffer_add(qr2_buffer_t buf, const char *value) {
    int copylen;
    copylen = (int)strlen(value) + 1;
    if (copylen > 0x578 - buf->len)
        copylen = 0x578 - buf->len;
    if (copylen <= 0)
        return 0;
    memcpy(buf->buffer + buf->len, value, (unsigned long)copylen);
    buf->len += copylen;
    buf->buffer[buf->len - 1] = 0;
    return 1;
}

int fn_80379D50(qr2_t qrec, qr2_buffer_t buf, SplitState *st) {
    int flagpos;
    int len;
    const char *s;
    int copylen;
    int avail;
    u8 keyid;
    const char *keyname;

    if ((int)st->keytype < 0 || (int)st->keytype >= 3)
        return 0;
    len = buf->len;
    avail = 0x578 - len;
    if (avail < 32)
        return 0;
    s = lbl_80490080;
    copylen = (int)strlen(s) + 1;
    if (copylen > avail)
        copylen = avail;
    if (copylen > 0) {
        memcpy(buf->buffer + len, s, (unsigned long)copylen);
        buf->len += copylen;
        buf->buffer[buf->len - 1] = 0;
    }
    flagpos = buf->len++;
    buf->buffer[flagpos] = (char)st->packetnum++;
    while ((int)st->keytype < 3) {
        if (st->keys.numkeys == 0)
            qrec->key_list_callback(st->keytype, &st->keys, qrec->udata);
        if (st->count == 0 && st->keytype != 0)
            st->count = qrec->playerteam_count_callback(st->keytype, qrec->udata);
        if (0x578 - buf->len < 100)
            return 1;
        buf->buffer[buf->len++] = (char)st->keytype;
        while (st->keyindex < st->keys.numkeys) {
            keyid = st->keys.keys[st->keyindex];
            keyname = lbl_804901F0[keyid];
            if (!qr2_buffer_add(buf, keyname))
                return 1;
            if (st->keytype == 0) {
                qrec->server_key_callback(keyid, buf, qrec->udata);
                if (0x578 - buf->len < 1)
                    return 1;
            } else {
                if (0x578 - buf->len < 1)
                    return 1;
                buf->buffer[buf->len++] = (char)st->index;
                while (st->index < st->count) {
                    if (st->keytype == 1)
                        qrec->player_key_callback(keyid, st->index, buf, qrec->udata);
                    else if (st->keytype == 2)
                        qrec->team_key_callback(keyid, st->index, buf, qrec->udata);
                    if (0x578 - buf->len < 1)
                        return 1;
                    st->index++;
                }
                if (0x578 - buf->len > 0)
                    buf->buffer[buf->len++] = 0;
            }
            st->index = 0;
            st->keyindex++;
        }
        if (0x578 - buf->len > 0)
            buf->buffer[buf->len++] = 0;
        st->keyindex = 0;
        st->keytype++;
        st->count = 0;
        st->index = 0;
        st->keys.numkeys = 0;
    }
    buf->buffer[flagpos] |= 0x80;
    return 1;
}
