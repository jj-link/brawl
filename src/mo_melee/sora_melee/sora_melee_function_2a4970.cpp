#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_2A5EE0(void* self, s32 a, s32 b, s32 c);
extern "C" void fn_27_2A7970(void* self, void* item, s32 a, s32 b);
extern "C" s32 fn_27_2B24C4(void* item);

extern s32 lbl_27_data_71BF0[];
extern const u8 lbl_27_data_71EB8[];

struct BaseItem {
    char _0[0x8C0];
    s32 kind;
};

struct ItemInfoBase {
    u32 _0;
    u8 unk4;
    char _5[3];
    s32 kind;
    s32 unkC;
    char _10[0x1C];
};

class ItemInfo : public ItemInfoBase {
public:
    virtual void fn(int);
};

template <class T>
class soArrayListX {
public:
    virtual void v0();
    virtual T& at(s32);
    virtual const T& at(s32) const;
    virtual s32 size() const;
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void erase(s32);
};

struct itMgr {
    char pad0[0x4C];
    s32 numItems;
    char pad1[0x78];
    soArrayListX<ItemInfo*> listB;
    char pad2[0x60C];
    soArrayListX<BaseItem*> listA;
    char pad3[0x9E0];
    s32 unk10BC;
    s32 unk10C0;
    s32 unk10C4;
    char pad4[0x3D8];
    u8 unk14A0;
};

static inline s32 query(itMgr* self) {
    if (self->unk14A0 != 0) {
        if (lbl_27_data_71EB8[0xa1] == 0)
            return -1;
        switch (lbl_27_data_71BF0[0xa1]) {
        case 1:
        case 6:
        case 7:
            return 0xa1;
        }
    }
    return -1;
}

static inline s32 removeKind(itMgr* self, s32 kind) {
    s32 cnt = 0;
    for (s32 i = 0; i < self->listA.size(); i++) {
        BaseItem*& item = self->listA.at(i);
        if (item != 0 && item->kind == kind) {
            self->listA.erase(i);
            fn_27_2A7970(self, item, 0, 1);
            i--;
            cnt++;
        }
    }
    return cnt;
}

static inline ItemInfo* findEntry(itMgr* self, s32 id) {
    for (s32 i = 0; i < ((const soArrayListX<ItemInfo*>&)self->listB).size(); i++) {
        ItemInfo* t = ((const soArrayListX<ItemInfo*>&)self->listB).at(i);
        if (t != 0 && id == t->kind && t->unkC == 0)
            return t;
    }
    return 0;
}

static inline bool searchEntry(itMgr* self) {
    s32 id = 0xA1;
    if (query(self) >= 0)
        id = -3;
    return findEntry(self, id) != 0;
}

extern "C" s32 fn_27_2A4970(itMgr* self, s32 arg1) {
    s32 n = self->numItems;
    if ((u32)(n - 3) <= 1u)
        return 1;
    if (n == 7)
        return 1;

    s32 flag = 0;
    s32 flag2 = 0;

    switch (arg1) {
    case 0x37:
        flag2 = 1;
        if (removeKind(self, 0x14) > 0)
            flag = 1;
        break;
    case 0x14:
        flag2 = 1;
        if (removeKind(self, 0x37) > 0)
            flag = 1;
        break;
    case 0:
        if (self->unk10BC == 0xA1) {
            if (removeKind(self, 0x37) > 0)
                flag = 1;
            if (removeKind(self, 0x14) > 0)
                flag = 1;
        }
        break;
    }

    if (flag2 != 0) {
        if (self->unk10BC == 0xA1) {
            if (self->unk10C0 > 0) {
                for (s32 i = 0; i < self->listA.size(); i++) {
                    BaseItem*& item = self->listA.at(i);
                    if (item != 0) {
                        s32 kind = item->kind;
                        s32 v;
                        if (kind == -3)
                            v = 1;
                        else if (kind < 0 || kind >= 0xB2)
                            v = -1;
                        else
                            v = lbl_27_data_71BF0[kind];
                        if (v == 2 || kind == 0) {
                            self->listA.erase(i);
                            fn_27_2A7970(self, item, 0, 1);
                            i--;
                        }
                    }
                }
            }

            s32 found = 0;
            s32 blocked = 0;
            for (s32 j = 0; j < self->listB.size(); j++) {
                ItemInfo*& slot = self->listB.at(j);
                ItemInfo* info = slot;
                if (info != 0) {
                    s32 kind = info->kind;
                    s32 v;
                    if (kind == -3)
                        v = 1;
                    else if (kind < 0 || kind >= 0xB2)
                        v = -1;
                    else
                        v = lbl_27_data_71BF0[kind];
                    if (v == 2) {
                        if (fn_27_2B24C4(info) != 0) {
                            self->listB.erase(j);
                            ItemInfo* e2 = slot;
                            if (e2 != 0)
                                e2->fn(1);
                            found = 1;
                            j--;
                        } else {
                            slot->unk4 = 1;
                            blocked = 1;
                        }
                    }
                }
            }
            if (found != 0 || blocked != 0) {
                self->unk10BC = -1;
                self->unk10C4 = -1;
                if (blocked != 0)
                    return 0;
            }
        }

        if (self->unk10BC == -1) {
            if (searchEntry(self))
                return 0;
        }
    } else {
        if (self->unk10BC == -1) {
            if (self->unk10C4 < 0)
                self->unk10C4 = 0x10;
            flag = 1;
        }
    }

    if (flag != 0)
        return 0;

    s32 value = fn_27_2A5EE0(self, arg1, 0, 1);
    s32 result = 1;
    if (value != 0)
        result = 2;
    return result;
}
