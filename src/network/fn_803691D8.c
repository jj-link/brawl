#include <types.h>
#include <string.h>
#include <stdlib.h>
#pragma force_active on

typedef struct Pair {
    s32 a;
    s32 b;
} Pair;

/* The shared context combines the fields used by all six members. */
typedef struct Context {
    u8 pad0[0x100];
    s32 field100;
    u8 pad104[0x94];
    s32 field198;
    u8 pad19C[0x14];
    Pair pair1B0;
    Pair pair1B8;
    Pair pair1C0;
    Pair pair1C8;
    Pair pair1D0;
    u8 pad1D8[8];
    Pair pair1E0;
    Pair pair1E8;
    u8 pad1F0[0x20];
    char field210[0x44C - 0x210];
    s32 field44C;
} Context;

/* Inner also supplies the formerly separate Info and Node layouts. */
typedef struct Inner {
    s32 field0;
    s32 field4;
    char *field8;
    char *fieldC;
    s32 field10;
    s32 field14;
} Inner;

/* Entry includes the fields formerly described by Obj. */
typedef struct Entry {
    s32 field0;
    s32 field4;
    Inner *inner;
    s32 fieldC;
    char *field10;
    s32 field14;
    s32 field18;
} Entry;

typedef struct Node8 {
    s32 unk0;
    s32 unk4;
} Node8;

typedef struct Node0C {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Node0C;

typedef struct NodeStr40C {
    s32 unk0;
    s32 unk4;
    char str[0x404];
} NodeStr40C;

typedef struct NodeStr108 {
    s32 unk0;
    s32 unk4;
    char str[0x100];
} NodeStr108;

extern char lbl_8059F640[5];
extern char lbl_8059F648[4];
extern char lbl_8059F64C[7];
extern char lbl_8059F654[6];
extern char lbl_8059F65C[4];
extern char lbl_8059F660[5];
extern char lbl_8059F668[5];
extern char lbl_8059F670[5];
extern char lbl_8059F678[4];
extern char lbl_8059F67C[4];
extern char lbl_8059F680[2];
extern char lbl_8059F684[4];
extern char lbl_8059F688[8];
extern char lbl_8059F690[6];

extern int fn_80372F14(const char *, const char *, char *, int);
extern void fn_80373290(void **, int, const char *);
extern void fn_8036AAF0(void **, int, int);
extern u64 fn_8035D258(int);
extern void *fn_8035DFE8(int);
extern void fn_8035E00C(void *);
extern char *fn_8035D654(const char *);
extern int fn_8036ABB0(void **, Pair *, void *, int, int);
extern Entry *fn_80370684(void **, int);
extern void fn_803732E0(void **, const char *);
extern void fn_80372DD8(char *, const char *, unsigned long);
extern void fn_8036A328(void **, void *, const char *);
extern void fn_8036A384(void **, void *, int);
extern void *fn_8036FD58(void *, int);
extern int fn_80370758(void *, int, Entry **);
extern void *fn_8036FDC8(void *, int, int);
extern int fn_8036FE98(void *, void *);
extern int fn_8036FF20(void *, void *);
extern int fn_80370118(void *, void *, int, const char *);
extern int fn_80370B4C(Entry *);
extern void fn_80370938(void **, Entry *);
extern s32 fn_80370A78(void **, s32, s32);
extern s32 SOHtoNl(s32);
extern s32 SOHtoNs(u16);

/* Profile IDs are integers; message payloads are character pointers. */
int fn_80369C64(void **, int, int, const char *);
int fn_80369D58(void **, int, int, const char *, int);
int fn_8036A000(int, int *, int);

#define FAIL_SEND() do { fn_80373290(arg0, 1, "Unexpected data was received from the server."); fn_8036AAF0(arg0, 3, 1); return 3; } while (0)
#define FAIL_ALLOC() do { fn_803732E0(arg0, "Out of memory."); return 1; } while (0)

int fn_803691D8(void **arg0, const char *arg1)
{
    char buf[0x1000];
    char buf2[0x100];
    char buf3[0x10];
    Pair p1;
    Pair q1;
    Pair q5;
    Pair q2;
    Pair q4;
    Pair q6;
    Pair q64;
    Pair q65;
    Pair p65;
    Pair p64;
    Pair p6;
    Pair p4;
    Pair p2;
    Pair p5;
    s32 type;
    s32 val;
    s32 extra;
    Context *ctx;
    int ret;

    ctx = (Context *)*arg0;
    if (fn_80372F14(arg1, lbl_8059F640, buf, 0x1000) == 0) {
        FAIL_SEND();
    }
    type = atoi(buf);
    if (fn_80372F14(arg1, lbl_8059F648, buf, 0x1000) == 0) {
        FAIL_SEND();
    }
    val = atoi(buf);
    if (fn_80372F14(arg1, lbl_8059F64C, buf, 0x1000) != 0) {
        extra = atoi(buf);
    } else {
        extra = (s32)fn_8035D258(0);
    }

    switch (type) {
    case 1: {
        Node0C *node;
        char *str;
        p1 = ctx->pair1C0;
        if (p1.a != 0) {
            node = fn_8035DFE8(0xC);
            if (node == NULL) {
                FAIL_ALLOC();
            }
            if (fn_80372F14(arg1, lbl_8059F654, buf, 0x1000) == 0) {
                FAIL_SEND();
            }
            str = fn_8035DFE8(strlen(buf) + 1);
            node->unk8 = (s32)str;
            if (str == NULL) {
                FAIL_ALLOC();
            }
            strcpy(str, buf);
            node->unk0 = val;
            node->unk4 = extra;
            q1 = p1;
            ret = fn_8036ABB0(arg0, &q1, node, 0, 2);
            if (ret != 0) {
                return ret;
            }
        }
        break;
    }
    case 5: {
        Node0C *node;
        char *str;
        p5 = ctx->pair1C8;
        if (p5.a != 0) {
            node = fn_8035DFE8(0xC);
            if (node == NULL) {
                FAIL_ALLOC();
            }
            if (fn_80372F14(arg1, lbl_8059F654, buf, 0x1000) == 0) {
                FAIL_SEND();
            }
            str = fn_8035DFE8(strlen(buf) + 1);
            node->unk8 = (s32)str;
            if (str == NULL) {
                FAIL_ALLOC();
            }
            strcpy(str, buf);
            node->unk0 = val;
            node->unk4 = extra;
            q5 = p5;
            ret = fn_8036ABB0(arg0, &q5, node, 0, 0xB);
            if (ret != 0) {
                return ret;
            }
        }
        break;
    }
    case 2: {
        Entry *obj;
        char *cs;
        NodeStr40C *n2;
        obj = fn_80370684(arg0, val);
        if (obj == NULL) {
            FAIL_ALLOC();
        }
        if (fn_80372F14(arg1, lbl_8059F654, buf, 0x1000) == 0) {
            FAIL_SEND();
        }
        cs = strstr(buf, "|signed|");
        if (cs == NULL) {
            FAIL_SEND();
        }
        *cs = 0;
        if (strlen(cs + 8) != 0x20) {
            FAIL_SEND();
        }
        fn_8035E00C(obj->field10);
        obj->field10 = 0;
        obj->field10 = fn_8035D654(cs + 8);
        obj->field14 = obj->field14 + 1;
        p2 = ctx->pair1B0;
        if (p2.a != 0) {
            n2 = fn_8035DFE8(0x40C);
            if (n2 == NULL) {
                FAIL_ALLOC();
            }
            fn_80372DD8(n2->str, buf, 0x401);
            n2->unk0 = val;
            n2->unk4 = extra;
            q2 = p2;
            ret = fn_8036ABB0(arg0, &q2, n2, 0, 6);
            if (ret != 0) {
                return ret;
            }
        }
        break;
    }
    case 4: {
        Node8 *node;
        p4 = ctx->pair1E0;
        if (p4.a != 0) {
            node = fn_8035DFE8(8);
            if (node == NULL) {
                FAIL_ALLOC();
            }
            node->unk0 = val;
            node->unk4 = extra;
            q4 = p4;
            ret = fn_8036ABB0(arg0, &q4, node, 0, 0xA);
            if (ret != 0) {
                return ret;
            }
        }
        break;
    }
    case 6: {
        Node8 *node;
        p6 = ctx->pair1E8;
        if (p6.a != 0) {
            node = fn_8035DFE8(8);
            if (node == NULL) {
                FAIL_ALLOC();
            }
            node->unk0 = val;
            node->unk4 = extra;
            q6 = p6;
            ret = fn_8036ABB0(arg0, &q6, node, 0, 0xC);
            if (ret != 0) {
                return ret;
            }
        }
        break;
    }
    case 0x64: {
        Entry *obj;
        Inner *t2;
        Inner *info;
        Node0C *node3;
        char *t;
        obj = fn_80370684(arg0, val);
        if (obj == NULL) {
            FAIL_ALLOC();
        }
        if (obj->inner == NULL) {
            t2 = fn_8035DFE8(0x18);
            obj->inner = t2;
            if (t2 == NULL) {
                FAIL_ALLOC();
            }
            memset(t2, 0, 0x18);
            obj->inner->field0 = ctx->field44C++;
        }
        info = obj->inner;
        if (fn_80372F14(arg1, lbl_8059F654, buf, 0x1000) == 0) {
            FAIL_SEND();
        }
        if (fn_80372F14(buf, lbl_8059F65C, buf3, 0x10) == 0) {
            FAIL_SEND();
        }
        info->field4 = atoi(buf3);
        fn_8035E00C(info->field8);
        info->field8 = 0;
        if (fn_80372F14(buf, lbl_8059F660, buf2, 0x100) == 0) {
            buf2[0] = 0;
        }
        t = fn_8035D654(buf2);
        info->field8 = t;
        if (t == 0) {
            FAIL_ALLOC();
        }
        fn_8035E00C(info->fieldC);
        info->fieldC = 0;
        if (fn_80372F14(buf, lbl_8059F668, buf2, 0x100) == 0) {
            buf2[0] = 0;
        }
        t = fn_8035D654(buf2);
        info->fieldC = t;
        if (t == 0) {
            FAIL_ALLOC();
        }
        if (fn_80372F14(buf, lbl_8059F670, buf3, 0x10) == 0) {
            info->field10 = 0;
        } else {
            info->field10 = SOHtoNl(atoi(buf3));
        }
        if (fn_80372F14(buf, lbl_8059F678, buf3, 0x10) == 0) {
            info->field14 = 0;
        } else {
            info->field14 = (u16)SOHtoNs((u16)atoi(buf3));
        }
        p64 = ctx->pair1B8;
        if (p64.a != 0) {
            node3 = fn_8035DFE8(0xC);
            if (node3 == NULL) {
                FAIL_ALLOC();
            }
            node3->unk0 = val;
            node3->unk8 = info->field0;
            node3->unk4 = extra;
            q64 = p64;
            ret = fn_8036ABB0(arg0, &q64, node3, 0, 5);
            if (ret != 0) {
                return ret;
            }
        }
        break;
    }
    case 0x65: {
        char *cq;
        char *cq2;
        s32 n;
        NodeStr108 *node;
        if (fn_80372F14(arg1, lbl_8059F654, buf, 0x1000) == 0) {
            FAIL_SEND();
        }
        cq = strstr(buf, lbl_8059F678);
        if (cq == NULL) {
            FAIL_SEND();
        }
        if (cq[3] == 0) {
            FAIL_SEND();
        }
        n = atoi(cq + 3);
        cq2 = strstr(buf, lbl_8059F67C);
        if (cq2 != NULL) {
            fn_80372DD8(buf2, cq2 + 3, 0x100);
        } else {
            buf2[0] = 0;
        }
        p65 = ctx->pair1D0;
        if (p65.a != 0) {
            node = fn_8035DFE8(0x108);
            if (node == NULL) {
                FAIL_ALLOC();
            }
            node->unk0 = val;
            node->unk4 = n;
            strcpy(node->str, buf2);
            q65 = p65;
            ret = fn_8036ABB0(arg0, &q65, node, 0, 0);
            if (ret != 0) {
                return ret;
            }
        }
        break;
    }
    case 0x66:
        if (fn_80372F14(arg1, lbl_8059F654, buf, 0x1000) == 0) {
            FAIL_SEND();
        }
        fn_80369D58(arg0, val, 0x67, lbl_8059F680, 0);
        break;
    default:
        break;
    }
    return 0;
}

int fn_80369C64(void **arg0, int arg1, int arg2, const char *arg3)
{
    char buffer[0xDAD];
    char *data = (char *)*arg0;

    fn_80372DD8(buffer, arg3, 0xDAD);
    fn_8036A328(arg0, data + 0x210, lbl_8059F640);
    fn_8036A384(arg0, data + 0x210, arg2);
    fn_8036A328(arg0, data + 0x210, "\\sesskey\\");
    fn_8036A384(arg0, data + 0x210, *(int *)(data + 0x198));
    fn_8036A328(arg0, data + 0x210, lbl_8059F684);
    fn_8036A384(arg0, data + 0x210, arg1);
    fn_8036A328(arg0, data + 0x210, lbl_8059F654);
    fn_8036A328(arg0, data + 0x210, buffer);
    fn_8036A328(arg0, data + 0x210, lbl_8059F688);
    return 0;
}

int fn_80369D58(void **a, int b, int c, const char *d, int e)
{
    Entry *entry;
    void *p;
    int result;
    int out;
    p = fn_8036FD58(a, b);
    if (p == 0) {
        if (!fn_80370758(a, b, &entry) || !entry->inner || !entry->inner->field14) {
            if (e == 0xb00) return 3;
            return fn_80369C64(a, b, c, d);
        }
        p = fn_8036FDC8(a, b, 1);
        if (!p) return 1;
        if (!entry->field18) {
            result = fn_8036FE98(a, p);
            if (result) return result;
        } else {
            result = fn_8036FF20(a, p);
            if (result) return result;
        }
    }
    result = fn_80370118(a, p, c, d);
    out = 0;
    if (result) out = result;
    return out;
}

typedef enum GPResult {
    GP_NO_ERROR,
    GP_MEMORY_ERROR,
    GP_PARAMETER_ERROR,
    GP_NETWORK_ERROR,
    GP_SERVER_ERROR
} GPResult;

static inline GPResult command_result(void)
{
    return GP_NO_ERROR;
}

int fn_80369E90(void **arg0, int arg1)
{
    Entry *entry;
    Context *data;
    const Entry *p;
    Context *ctx = (Context *)*arg0;

    if (fn_80370758(arg0, arg1, &entry) == 0) {
        fn_803732E0(arg0, "Invalid profile.");
        return 2;
    }
    p = entry;
    if (p->field10 == 0) {
        fn_803732E0(arg0, "Invalid profile.");
        return 2;
    }
    data = (Context *)*arg0;
    fn_8036A328(arg0, data->field210, "\\authadd\\");
    fn_8036A328(arg0, data->field210, "\\sesskey\\");
    fn_8036A384(arg0, data->field210, data->field198);
    fn_8036A328(arg0, data->field210, "\\fromprofileid\\");
    fn_8036A384(arg0, data->field210, p->field0);
    fn_8036A328(arg0, data->field210, lbl_8059F690);
    fn_8036A328(arg0, data->field210, p->field10);
    fn_8036A328(arg0, data->field210, lbl_8059F688);
    {
        GPResult result = command_result();
        if (result != GP_NO_ERROR) {
            return result;
        }
    }
    --entry->field14;
    if (ctx->field100 == 0 && entry->field14 <= 0) {
        fn_8035E00C(entry->field10);
        entry->field10 = 0;
        if (fn_80370B4C(entry) != 0) {
            fn_80370938(arg0, entry);
        }
    }
    return 0;
}

int fn_8036A000(int unused, int *arg1, int arg2)
{
    arg1 = *(int **)((char *)arg1 + 8);
    if (arg1 != 0) {
        int v = *arg1;
        if (v > arg2) {
            *arg1 = v - 1;
        }
    }
    return 1;
}

s32 fn_8036A028(void **arg0, int arg1, s32 arg2)
{
    char *data;
    Entry *entry;
    s32 value;
    s32 count;

    data = (char *)*arg0;
    if (fn_80370758(arg0, arg1, &entry) == 0) {
        fn_803732E0(arg0, "Invalid profile.");
        return 2;
    }
    if (arg2 == 1) {
        fn_8036A328(arg0, data + 0x210, "\\delbuddy\\");
        fn_8036A328(arg0, data + 0x210, "\\sesskey\\");
        fn_8036A384(arg0, data + 0x210, *(s32 *)(data + 0x198));
        /* Preserve the unused zero tail of the original string pool. */
        fn_8036A328(arg0, data + 0x210, "\\delprofileid\\\0\0\0\0\0");
        fn_8036A384(arg0, data + 0x210, entry->field0);
        fn_8036A328(arg0, data + 0x210, lbl_8059F688);
    }
    if (entry->inner != 0) {
        value = entry->inner->field0;
        fn_8035E00C(entry->inner->field8);
        entry->inner->field8 = 0;
        fn_8035E00C(entry->inner->fieldC);
        entry->inner->fieldC = 0;
        fn_8035E00C(entry->inner);
        entry->inner = 0;
        if (fn_80370B4C(entry) != 0) {
            fn_80370938(arg0, entry);
        }
        count = *(s32 *)(data + 0x44C);
        *(s32 *)(data + 0x44C) = count - 1;
        fn_80370A78(arg0, (s32)fn_8036A000, value);
    }
    return 0;
}
