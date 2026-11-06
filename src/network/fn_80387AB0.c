#include <string.h>
#include <revolution/SO/SOBasic.h>
#pragma force_active on

extern unsigned int fn_8035D728(void);
extern int sendto(int, const void *, unsigned int, int, const void *, unsigned int);
extern char lbl_80490D18[];
extern char lbl_80490D28[];

typedef struct Entry Entry;
struct Entry {
    unsigned int ip;
    unsigned short port;
    char pad06[2];
    unsigned int altip;
    unsigned short altport;
    char pad0e[6];
    unsigned char flags;
    unsigned char flags2;
    char pad16[6];
    unsigned int time;
    unsigned int value;
    Entry *next;
};
typedef struct Context {
    int mode;
    char pad04[4];
    Entry *head;
    Entry *tail;
    int count;
    char pad14[12];
    int socket;
    char pad24[4];
    unsigned int ip;
    unsigned char data[20];
    int datalen;
} Context;
typedef struct Address {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int ip;
} Address;

void fn_80387AB0(Context *ctx, Entry *entry) {
    int sent = 0;
    Address addr;
    unsigned char buf[256];
    unsigned int val;
    int len, i;
    addr.family = 2;
    entry->time = fn_8035D728();
    if (!(entry->flags & 0x20)) {
        if (ctx->mode == 1) {
            if (entry->flags & 0x80) {
                len = 0;
                buf[len++] = 0xfe;
                buf[len++] = 0xfd;
                buf[len++] = 9;
                memcpy(buf + len, &entry->time, 4);
                len += 4;
            } else {
                int pos;
                val = SOHtoNl(entry->value);
                pos = 0;
                buf[pos++] = 0xfe;
                buf[pos++] = 0xfd;
                buf[pos++] = 0;
                memcpy(buf + pos, &entry->time, 4);
                pos += 4;
                if (val != 0) {
                    memcpy(buf + pos, &val, 4);
                    pos += 4;
                }
                if (entry->flags & 4) {
                    buf[pos++] = ctx->datalen;
                    for (i = 0; i < ctx->datalen; i++) {
                        buf[pos++] = ctx->data[i];
                    }
                    buf[pos++] = 0;
                    buf[pos++] = 0;
                    len = pos;
                } else {
                    buf[pos++] = 0xff;
                    buf[pos++] = 0xff;
                    buf[pos++] = 0xff;
                    buf[pos++] = 1;
                    len = pos;
                }
            }
        } else if (entry->flags & 4) {
            memcpy(buf, lbl_80490D18, 13);
            len = 13;
        } else {
            memcpy(buf, lbl_80490D28, 8);
            len = 8;
        }
        if (entry->ip == ctx->ip && (entry->flags2 & 2)) {
            addr.ip = entry->altip;
            addr.port = entry->altport;
        } else {
            addr.ip = entry->ip;
            addr.port = entry->port;
        }
        sendto(ctx->socket, buf, len, 0, &addr, 8);
        sent = 1;
    }
    if (sent) {
        if (ctx->tail != 0)
            ctx->tail->next = entry;
        ctx->tail = entry;
        entry->next = 0;
        if (ctx->head == 0)
            ctx->head = entry;
        ctx->count++;
    } else {
        entry->time = 0;
    }
}