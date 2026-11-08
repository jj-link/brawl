#pragma force_active on

#include <types.h>

typedef struct {
    char _0[0x8C0];
    int kind;
} BaseItem;

struct Info {
    char _0[4];
    unsigned char b;
    char _5[3];
    int kind;
};

class XList {
public:
    virtual void v2();
    virtual void* getAt(s32 idx);
    virtual void v4();
    virtual s32 size();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void removeAt(s32 idx);
};

typedef struct itMgr {
    char _0[0x4C];
    int numItems;
    char _50[0x78];
    XList list2;
    char _CC[0x60C];
    XList list1;
    char _6DC[0x9E0];
    int numAssists;
    int count10C0;
    int preloadTimer;
} itMgr;

extern int lbl_27_data_71BF0[];
extern "C" void* isCompItemKindArchive__9itManagerF6itKindUlb(void*, int, unsigned long, int);
extern "C" int fn_27_2A5BB4(void*, int, int);
extern "C" void fn_27_2A7970(void* self, void* item, s32 a, s32 b);
extern "C" void* preloadItemKindArchive__9itManagerF6itKindUlQ29itArchive4Typeb(void*, int, unsigned long, int, int);

extern "C" int preloadAssist__9itManagerF6itKind(itMgr* self, int kind) {
    int n = self->numItems;
    if ((unsigned)(n - 3) <= 1u) return 0;
    if (n == 7) return 0;

    int var;
    if (kind == -3) var = 1;
    else if (kind < 0 || kind >= 0xB2) var = -1;
    else var = lbl_27_data_71BF0[kind];
    if (var != 2) return 0;

    int na = self->numAssists;
    if (na != -1) {
        if (isCompItemKindArchive__9itManagerF6itKindUlb(self, na, 0, 1) == 0)
            return 0;
    }

    if (kind == 0xA1) {
        if (fn_27_2A5BB4(self, kind, 1) != 0)
            return 0;
    }

    if (self->count10C0 > 0) {
        int i = 0;
        while (i < self->list1.size()) {
            void** p = (void**)self->list1.getAt(i);
            void* item = *p;
            if (item != 0) {
                int ik = ((BaseItem*)item)->kind;
                int v;
                if (ik == -3) v = 1;
                else if (ik < 0 || ik >= 0xB2) v = -1;
                else v = lbl_27_data_71BF0[ik];
                if (v == 2 || ik == 0) {
                    self->list1.removeAt(i);
                    fn_27_2A7970(self, *p, 0, 1);
                    i--;
                }
            }
            i++;
        }
    }

    int found = 0;
    int i2 = 0;
    while (i2 < self->list2.size()) {
        void** p = (void**)self->list2.getAt(i2);
        Info* elem = (Info*)(*(void**)p);
        if (elem != 0) {
            int ik = elem->kind;
            int v;
            if (ik == -3) v = 1;
            else if (ik < 0 || ik >= 0xB2) v = -1;
            else v = lbl_27_data_71BF0[ik];
            if (v == 2) {
                elem->b = 1;
                found = 1;
            }
        }
        i2++;
    }

    self->numAssists = -1;
    if (found != 0) {
        if (self->preloadTimer <= 0) {
            self->preloadTimer = 0x10;
        }
        return 0;
    }
    if (preloadItemKindArchive__9itManagerF6itKindUlQ29itArchive4Typeb(self, kind, 0x1388, 1, 1) == 0)
        return 0;
    self->numAssists = kind;
    return 1;
}