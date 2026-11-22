#include <types.h>
#pragma force_active on

#pragma inline_depth(8)

struct FnPair {
    u32 value;
    s32 id;
};

struct Entry {
    int pad;
    int key;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Entry* slot1(s32);
    virtual void slot2();
    virtual s32 slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(s32, FnPair*);
    virtual void slot12();
    virtual void slot13();
    virtual u32 slot14();
};

class Class_90D8 {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual s32 fn_27_7B2EC();
};

class Outer {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual u32 slot5();
    virtual u32 slot6(s32);

    char pad[12];
    Object_vptr_0* inner;
};

extern "C" void fn_27_90D70(FnPair*, const FnPair*, u32);
extern "C" s32 fn_27_90938(Outer* self, s32 target, s32 lo, s32 hi);

static inline s32 search1(Outer* self, s32 target, s32 lo, s32 hi) {
    s32 mid = lo + (hi - lo) / 2;
    s32 key = self->inner->slot1(mid)->key;
    if (key == target) return -1;
    if (key < target) {
        if (lo == hi) return mid + 1;
        return fn_27_90938(self, target, mid + 1, hi);
    }
    if (key > target) {
        if (lo == hi) return mid;
        return fn_27_90938(self, target, lo, mid);
    }
    return -1;
}

static inline s32 search2(Outer* self, s32 target, s32 lo, s32 hi) {
    s32 mid = lo + (hi - lo) / 2;
    s32 key = self->inner->slot1(mid)->key;
    if (key == target) return -1;
    if (key < target) {
        if (lo == hi) return mid + 1;
        return search1(self, target, mid + 1, hi);
    }
    if (key > target) {
        if (lo == hi) return mid;
        return search1(self, target, lo, mid);
    }
    return -1;
}

static inline s32 searchLeft(Outer* self, s32 target, s32 hi) {
    return search2(self, target, 0, hi);
}

static inline s32 search3(Outer* self, s32 target, s32 lo, s32 hi) {
    s32 mid = lo + (hi - lo) / 2;
    s32 key = self->inner->slot1(mid)->key;
    if (key == target) return -1;
    if (key < target) {
        if (lo == hi) return mid + 1;
        return search2(self, target, mid + 1, hi);
    }
    if (key > target) {
        if (lo == hi) return mid;
        return searchLeft(self, target, mid);
    }
    return -1;
}

static inline s32 lastIdx(Object_vptr_0* l) {
    return l->slot3() - 1;
}

static inline s32 lastIdx2(Class_90D8* o) {
    return o->fn_27_7B2EC() - 1;
}

static inline s32 findPos(Outer* self, s32 id) {
    if (self->slot5() == 1U)
        return 0;
    return search3(self, id, 0, lastIdx2((Class_90D8*)((char*)self + 8)));
}

extern "C" s32 fn_27_90274(Outer* self, const FnPair* src, s32 id) {
    Object_vptr_0* inner = self->inner;

    if (inner->slot14() == 1U || self->slot6(id) == 1U)
        return -1;

    if (id <= -1) {
        if (self->inner->slot14() == 1U) {
            id = 0x7fff;
        } else if (self->slot5() == 1U) {
            id = 0;
        } else {
            Object_vptr_0* list = self->inner;
            if (list->slot1(lastIdx(list))->key < 0x7fff) {
                id = list->slot1(lastIdx(list))->key + 1;
            } else {
                id = lastIdx(list);
                while (id >= 0) {
                    if (id == 0) {
                        if (list->slot1(id)->key == 0)
                            id = -1;
                        else
                            id = list->slot1(id)->key - 1;
                    } else {
                        s32 prev = list->slot1(id - 1)->key;
                        if (list->slot1(id)->key - 1 > prev)
                            id = list->slot1(id)->key - 1;
                        else
                            id = -1;
                    }
                    goto done;
                }
                id = -1;
            }
        }
done:
        if (id <= -1)
            return -1;
    }

    s32 idx = findPos(self, id);
    if (idx < 0)
        return -1;

    FnPair pair;
    fn_27_90D70(&pair, src, id);
    inner->slot11(idx, &pair);
    return id;
}
