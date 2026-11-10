#include <string.h>
#include <stdlib.h>
#pragma force_active on

typedef struct Profile {
    char *nick, *unique, *email, *a, *b, *homepage;
    int n;
    char zip[11], country[3];
    float lon, lat;
    char loc[128];
    int year, month, day, sex, pmask;
    char *aim;
    int pic, occ, ind, inc, mar, chc, i1, o1, extra;
} Profile;

typedef struct Entry {
    char pad0[12];
    Profile *profile;
    char pad10[8];
    char *value;
} Entry;

typedef struct Node {
    int type;
    char pad4[8];
    int id;
    char pad10[0x30];
    struct Node *next;
} Node;

typedef struct Context {
    char pad0[0x100];
    int active;
    char pad104[0x34c];
    Node *nodes;
} Context;

typedef struct Request {
    char pad[12];
    int callback;
    int param;
} Request;

typedef struct Pair {
    int a, b;
} Pair;

extern int fn_80372E1C(Context **, const char *, int);
extern int fn_80372F14(const char *, const char *, void *, int);
extern void fn_80373290(void *, int, const char *);
extern void fn_803732E0(void *, const char *);
extern void fn_8036AAF0(void *, int, int);
extern int fn_80370758(void *, int, Entry **);
extern Entry *fn_80370684(void *, int);
extern int fn_8036C554(unsigned int, unsigned char, unsigned short);
extern double fn_803FBBF8(const char *);
extern void fn_8035E00C(void *);
extern char *fn_8035D654(const char *);
extern void *fn_8035DFE8(int);
extern void fn_8036E918(Entry *);
extern void fn_8036C6B8(Profile *, void *);
extern int fn_8036ABB0(void *, Pair *, void *, void *, int);
extern void fn_8036EEE4(void *, void *);

extern char jumptable_8048F1C0[];
extern char lbl_8059F748[8];
extern char lbl_8059F750[8];
extern char lbl_8059F758[8];
extern char lbl_8059F760[8];
extern char lbl_8059F768[8];
extern char lbl_8059F770[8];
extern char lbl_8059F778[8];
extern char lbl_8059F780[8];
extern char lbl_8059F788[8];
extern char lbl_8059F790[8];
extern char lbl_8059F798[8];
extern char lbl_8059F7A0[8];
extern char lbl_8059F7A8[8];
extern char lbl_8059F7B0[8];
extern char lbl_8059F7B8[8];
extern char lbl_8059F7C0[8];
extern char lbl_8059F7C8[8];
extern char lbl_8059F7D0[8];
extern char lbl_8059F7D8[8];
extern float lbl_805A4990;

int fn_8036C8F4(Context **ctx, Request *req, const char *input)
{
    Entry *entry;
    Pair pair, copy;
    char homepage[80], buf[64], email[52], aim[52];
    char nick[32], unique[24], a[32], b[32];
    Profile p;
    const char *base = jumptable_8048F1C0;
    Context *data = *ctx;
    int id, result;
    unsigned int value, day, month, year;
    Node *node;
    void *out;
    int changed;

    if (fn_80372E1C(ctx, input, 1))
        return 4;

    if (strncmp(input, lbl_8059F748, 4)) {
        fn_80373290(ctx, 1, base + 0x34);
        fn_8036AAF0(ctx, 3, 1);
        return 3;
    }

    if (!fn_80372F14(input, base + 0x64, buf, 64)) {
        fn_80373290(ctx, 1, base + 0x34);
        fn_8036AAF0(ctx, 3, 1);
        return 3;
    }

    id = atoi(buf);
    fn_80370758(ctx, id, &entry);
    memset(&p, 0, 0xf0);

    p.nick = nick;
    p.unique = unique;
    p.email = email;
    p.a = a;
    p.b = b;
    p.homepage = homepage;
    p.aim = aim;

    if (!fn_80372F14(input, lbl_8059F750, p.nick, 31))
        *p.nick = 0;
    if (!fn_80372F14(input, base + 0x70, p.unique, 21))
        *p.unique = 0;
    if (!fn_80372F14(input, lbl_8059F758, p.email, 51))
        *p.email = 0;
    if (!fn_80372F14(input, base + 0x80, p.a, 31))
        *p.a = 0;
    if (!fn_80372F14(input, base + 0x8c, p.b, 31))
        *p.b = 0;

    if (!fn_80372F14(input, base + 0x98, buf, 64))
        p.n = -1;
    else
        p.n = atoi(buf);

    if (!fn_80372F14(input, base + 0xa4, p.homepage, 76))
        *p.homepage = 0;
    if (!fn_80372F14(input, base + 0xb0, p.zip, 11))
        p.zip[0] = 0;
    if (!fn_80372F14(input, base + 0xbc, p.country, 3))
        p.country[0] = 0;

    if (!fn_80372F14(input, lbl_8059F760, buf, 64))
        p.lon = lbl_805A4990;
    else
        p.lon = (float)fn_803FBBF8(buf);

    if (!fn_80372F14(input, lbl_8059F768, buf, 64))
        p.lat = lbl_805A4990;
    else
        p.lat = (float)fn_803FBBF8(buf);

    if (!fn_80372F14(input, lbl_8059F770, p.loc, 128))
        p.loc[0] = 0;

    if (!fn_80372F14(input, base + 0xcc, buf, 64)) {
        p.year = 0;
        p.month = 0;
        p.day = 0;
    } else {
        value = atoi(buf);
        month = (unsigned char)(value >> 16);
        day = (unsigned short)value;
        year = value >> 24;
        if (!fn_8036C554(year, month, day)) {
            fn_803732E0(ctx, base + 0xd8);
            result = 2;
        } else {
            p.year = year;
            p.month = month;
            p.day = day;
            result = 0;
        }
        if (result)
            return result;
    }

    if (!fn_80372F14(input, lbl_8059F778, buf, 64))
        p.sex = 0x502;
    else if (buf[0] == '0')
        p.sex = 0x500;
    else if (buf[0] == '1')
        p.sex = 0x501;
    else
        p.sex = 0x502;

    if (!fn_80372F14(input, lbl_8059F780, buf, 64))
        p.pmask = -1;
    else
        p.pmask = atoi(buf);

    if (!fn_80372F14(input, lbl_8059F788, p.aim, 51))
        *p.aim = 0;

    if (!fn_80372F14(input, lbl_8059F790, buf, 64))
        p.pic = 0;
    else
        p.pic = atoi(buf);
    if (!fn_80372F14(input, lbl_8059F798, buf, 64))
        p.occ = 0;
    else
        p.occ = atoi(buf);
    if (!fn_80372F14(input, lbl_8059F7A0, buf, 64))
        p.ind = 0;
    else
        p.ind = atoi(buf);
    if (!fn_80372F14(input, lbl_8059F7A8, buf, 64))
        p.inc = 0;
    else
        p.inc = atoi(buf);
    if (!fn_80372F14(input, lbl_8059F7B0, buf, 64))
        p.mar = 0;
    else
        p.mar = atoi(buf);
    if (!fn_80372F14(input, lbl_8059F7B8, buf, 64))
        p.chc = 0;
    else
        p.chc = atoi(buf);
    if (!fn_80372F14(input, lbl_8059F7C0, buf, 64))
        p.i1 = 0;
    else
        p.i1 = atoi(buf);
    if (!fn_80372F14(input, lbl_8059F7C8, buf, 64))
        p.o1 = 0;
    else
        p.o1 = atoi(buf);
    if (!fn_80372F14(input, lbl_8059F7D0, buf, 64))
        p.extra = 0;
    else
        p.extra = atoi(buf);

    if (!fn_80372F14(input, lbl_8059F7D8, buf, 64)) {
        fn_80373290(ctx, 1, base + 0x34);
        fn_8036AAF0(ctx, 3, 1);
        return 3;
    }

    changed = data->active;
    node = data->nodes;
    while (node) {
        if (node->id == id && node->type == 0x65) {
            if (!entry)
                entry = fn_80370684(ctx, id);
            node->type = 0x66;
            changed = 1;
        }
        node = node->next;
    }

    if (!entry && data->active)
        entry = fn_80370684(ctx, id);

    if (changed) {
        fn_8035E00C(entry->value);
        entry->value = 0;
        entry->value = fn_8035D654(buf);
    }

    if (data->active) {
        Entry *selected = entry;
        if ((*ctx)->active) {
            fn_8036E918(selected);
            selected->profile = fn_8035DFE8(0xf0);
            if (selected->profile) {
                *selected->profile = p;
                selected->profile->nick = fn_8035D654(p.nick);
                selected->profile->unique = fn_8035D654(p.unique);
                selected->profile->email = fn_8035D654(p.email);
                selected->profile->a = fn_8035D654(p.a);
                selected->profile->b = fn_8035D654(p.b);
                selected->profile->homepage = fn_8035D654(p.homepage);
                selected->profile->aim = fn_8035D654(p.aim);
            }
        }
    }

    pair.a = req->callback;
    pair.b = req->param;
    if (pair.a) {
        out = fn_8035DFE8(0x204);
        if (!out) {
            fn_803732E0(ctx, base + 0xe8);
            return 1;
        }
        fn_8036C6B8(&p, out);
        ((int *)out)[0] = 0;
        ((int *)out)[1] = id;
        copy = pair;
        result = fn_8036ABB0(ctx, &copy, out, req, 0);
        if (result)
            return result;
    }

    fn_8036EEE4(ctx, req);
    return 0;
}
