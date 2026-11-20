#include <types.h>
#pragma force_active on

struct ScnMdlIface {
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void v7(void);
    virtual void v8(void);
    virtual void v9(void);
    virtual void v10(void);
    virtual void v11(void);
    virtual void v12(void);
    virtual void v13(void);
    virtual void remove(void* res);
};

struct Slot {
    char pad[0x10];
    void* res;
};

struct Entry {
    int key;
    char* str;
};

struct Menu {
    int pad0;
    char* name;             /* 0x04 */
    int capacity;           /* 0x08 */
    char pad1[0x2c];
    int count;              /* 0x38 */
    int state;              /* 0x3c */
    int difficulty;         /* 0x40 */
    char pad2[0x1c];
    void* object;           /* 0x60 */
    void* message;          /* 0x64 */
    char pad4[4];
    ScnMdlIface* scene;     /* 0x6c */
    u32 msgIndex;           /* 0x70 */
    int field74;            /* 0x74 */
    Slot* field78;          /* 0x78 */
    unsigned char flag;     /* 0x7c */
    char pad5[7];
    int cursor;             /* 0x84 */
};

extern "C" {
int fn_16_1670(void* m);
int fn_8006CEEC(char* s, int n);
void fn_8006BAB0(char* dst, char* src, int a, int b);
void fn_16_8D0(void* m, char* out, char* src, char* extra);
int fn_16_1568(void* m, char* a, char* b);
void* __nwa__FUlQ25Heaps8HeapType(u32 size, int heap);
void __dl__FPv(void* p);
char* strcpy(char* dst, const char* src);
int sprintf(char* buf, const char* fmt, ...);
void playSE__9sndSystemF5SndIDiiii(void* snd, int id, int a, int b, int c, int d);
void printf__5MuMsgFUlPCce(void* msg, u32 idx, const char* fmt, ...);
void setFrameNode__8MuObjectFf(void* obj, float f);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void* scn, void* res, char* s);
extern void* g_sndSystem;
extern char lbl_16_data_3308[];
extern char lbl_16_data_490[];
}

static inline void truncateName(Menu* m, int n) {
    char* buf = (char*)__nwa__FUlQ25Heaps8HeapType(m->capacity * 4 + 1, 0x2a);
    *buf = 0;
    fn_8006BAB0(buf, m->name, 0, n - 1);
    strcpy(m->name, buf);
    __dl__FPv(buf);
}

static inline void printMsg(Menu* m) {
    if (m->message)
        printf__5MuMsgFUlPCce(m->message, m->msgIndex, m->name);
}

static inline void updateCursor(Menu* m) {
    int c = fn_8006CEEC(m->name, 0x7fff);
    if (!m->flag) {
        c--;
        if (c < 0)
            c = 0;
    }
    int max = m->capacity - 1;
    if (c > max)
        c = max;
    if (m->object)
        setFrameNode__8MuObjectFf(m->object, (float)(c + 1));
    m->cursor = c;
}

static inline void changePage(Menu* m, char* sp18) {
    m->state++;
    if (m->state >= m->count)
        m->state = 0;
    int t = *(int*)((char*)m + m->state * 4 + 0x24);
    Slot* f78 = m->field78;
    if (f78) {
        m->scene->remove(f78->res);
        m->field78 = 0;
    }
    Slot* option = *(Slot**)((char*)m + t * 4 + 0x48);
    sprintf(sp18, lbl_16_data_3308, m->field74 + 1);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(m->scene, option->res, sp18);
    m->field78 = option;
}

static inline int lastChar(Menu* m, char* out) {
    int length = fn_8006CEEC(m->name, 0x7fff);
    if (length <= 0)
        return 0;
    out[0] = 0;
    fn_8006BAB0(out, m->name, length - 1, 1);
    return 1;
}

extern "C" int fn_16_E18(void* arg0) {
            int found;
    int t;
    Menu* m = (Menu*)arg0;
    char sp10[8];
    char sp8[8];
    char sp18[0x10];
    int r;
    int pos;
    int n;

    r = fn_16_1670(arg0);
    if (r == 0)
        return 2;
    if ((u32)(r - 1) <= 1) {
        if (r == 1)
            return 0;
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 2, -1, 0, 0, -1);
        return 1;
    }

    if (r == 4) {
        pos = fn_8006CEEC(m->name, 0x7fff);
        if (pos > 0)
            truncateName(m, pos);
        printMsg(m);
        m->flag = 1;
        updateCursor(m);
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x204d, -1, 0, 0, -1);
        return 2;
    }

    if (r == 6) {
        if (fn_8006CEEC(m->name, 0x7fff) > 0) {
            m->name[0] = 0;
            printMsg(m);
            m->flag = 1;
            updateCursor(m);
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x204d, -1, 0, 0, -1);
        }
        return 2;
    }

    if (r == 5) {
        changePage(m, sp18);
        m->flag = 1;
        updateCursor(m);
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x23, -1, 0, 0, -1);
        return 2;
    }

    {
        Entry* entry;
        int tv = *(int*)((char*)m + m->state * 4 + 0x24);
        if (m->difficulty < 1 || m->difficulty > 0xb)
            entry = 0;
        else
            entry = (Entry*)((char*)lbl_16_data_490 + tv * 0x58 + (m->difficulty - 1) * 8);

        if (entry->key == 0) {
            pos = fn_8006CEEC(entry->str, 0x7fff);
            found = 1;
            n = fn_8006CEEC(m->name, 0x7fff);
            if (n > 0) {
                if ((!m->flag && pos > 1) || n >= m->capacity)
                    found = 0;
            }
            if (!found) {
                n = fn_8006CEEC(m->name, 0x7fff);
                if (n > 0) {
                    sp10[0] = 0;
                    fn_8006BAB0(sp10, m->name, n - 1, 1);
                }
            } else {
                sp10[0] = 0;
            }
            fn_16_8D0(m, sp8, entry->str, sp10);
            if (!found) {
                n = fn_8006CEEC(m->name, 0x7fff);
                if (n > 0)
                    truncateName(m, n);
            }
            n = fn_8006CEEC(m->name, 0x7fff);
            int d = m->capacity - n;
            if (d > 0)
                fn_8006BAB0(m->name, sp8, 0, d);
            printMsg(m);
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x204c, -1, 0, 0, -1);
            if (pos > 1)
                m->flag = 0;
            else
                m->flag = 1;
            updateCursor(m);
        } else {
            if (lastChar(m, sp10) && fn_16_1568(m, sp8, sp10)) {
                n = fn_8006CEEC(m->name, 0x7fff);
                if (n > 0)
                    truncateName(m, n);
                n = fn_8006CEEC(m->name, 0x7fff);
                int d = m->capacity - n;
                if (d > 0)
                    fn_8006BAB0(m->name, sp8, 0, d);
                printMsg(m);
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x204c, -1, 0, 0, -1);
            }
        }
        return 2;
    }
}
