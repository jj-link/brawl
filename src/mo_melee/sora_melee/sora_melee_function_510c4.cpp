#include <types.h>
#pragma force_active on
#pragma inline_depth(4)

struct Elem { int pad; int val; };
struct Pair { u32 a; u32 b; };
class ListObj {
public:
    virtual void v0();
    virtual Elem* v1(int);
    virtual void v2();
    virtual int v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(int, Pair*);
    virtual void v12();
    virtual void v13();
    virtual u32 v14();
};
class Sub {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int s4();
    int pad;
};
class Outer {
public:
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual u32 o5();
    virtual u32 o6(int);
    int pad;
    Sub sub;
    ListObj* list;
};
extern "C" void fn_27_557EC(Pair*, const Pair*, u32);
extern "C" int fn_27_5252C(Outer*, int, int, int);
#define FIND_BODY(next) \
    int mid = lo + (hi - lo) / 2; \
    int value = self->list->v1(mid)->val; \
    if (value == key) return -1; \
    if (value < key) { \
        if (lo == hi) return mid + 1; \
        return next(self, key, mid + 1, hi); \
    } \
    if (value > key) { \
        if (lo == hi) return mid; \
        return next(self, key, lo, mid); \
    } \
    return -1;
inline int find3(Outer* self, int key, int lo, int hi) { FIND_BODY(fn_27_5252C) }
inline int find2(Outer* self, int key, int lo, int hi) { FIND_BODY(find3) }
inline int findleft(Outer* self, int key, int hi) { return find2(self, key, 0, hi); }
inline int find1(Outer* self, int key, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;
    int value = self->list->v1(mid)->val;
    if (value == key) return -1;
    if (value < key) {
        if (lo == hi) return mid + 1;
        return find2(self, key, mid + 1, hi);
    }
    if (value > key) {
        if (lo == hi) return mid;
        return findleft(self, key, mid);
    }
    return -1;
}
inline int lastIndex(ListObj* list) { return list->v3() - 1; }
inline int insertion(Outer* self, int key) { return find1(self, key, 0, self->sub.s4() - 1); }
inline int findFree(Outer* self) {
    if (self->list->v14() == 1U) return 0x7fff;
    if (self->o5() == 1U) return 0;
    ListObj* list = self->list;
    if (list->v1(list->v3() - 1)->val < 0x7fff)
        return list->v1(list->v3() - 1)->val + 1;
    int i = list->v3() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (list->v1(i)->val == 0) return -1;
            return list->v1(i)->val - 1;
        }
        int prev = list->v1(i - 1)->val;
        if (list->v1(i)->val - 1 > prev) return list->v1(i)->val - 1;
        return -1;
    }
    return -1;
}
extern "C" int fn_27_510C4(Outer* self, const Pair* src, int key) {
    ListObj* list = self->list;
    if (list->v14() == 1U || self->o6(key) == 1U) return -1;
    if (key <= -1) {
        if (self->list->v14() == 1U) key = 0x7fff;
        else if (self->o5() == 1U) key = 0;
        else {
            ListObj* current = self->list;
            if (current->v1(lastIndex(current))->val < 0x7fff)
                key = current->v1(lastIndex(current))->val + 1;
            else {
                key = current->v3() - 1;
                while (key >= 0) {
                    if (key == 0) {
                        if (current->v1(key)->val == 0) key = -1;
                        else key = current->v1(key)->val - 1;
                        goto found;
                    }
                    int prev = current->v1(key - 1)->val;
                    if (current->v1(key)->val - 1 > prev) key = current->v1(key)->val - 1;
                    else key = -1;
                    goto found;
                }
                key = -1;
                found:;
            }
        }
        if (key <= -1) return -1;
    }
    int idx;
    if (self->o5() == 1U) idx = 0;
    else idx = insertion(self, key);
    if (idx < 0) return -1;
    Pair p;
    fn_27_557EC(&p, src, key);
    list->v11(idx, &p);
    return key;
}
