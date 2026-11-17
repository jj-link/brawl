#include <types.h>
#include <sr/sr_common.h>
#pragma force_active on

struct Elem {
    s32 key;
    void* data;
};

struct Vec;
inline void remove(Vec*, const s32&);

struct Vec {
    Elem* elems;
    s32 count;
    u32 flags;

    bool isOwned() const {
        return (flags & 0x80000000) == 0;
    }

    bool isLast(s32 found) const {
        return found == count - 1;
    }

    void clearElements() {
        for (s32 i = 0; i < count; i++)
            remove(this, elems[i].key);
    }
};

extern "C" void fn_80096048(void*, s32);
extern "C" void fn_8027EABC(void*, void*, u32, s32);
extern "C" void* lbl_805A0EC8;
extern "C" void __dl__FPv(void*);

inline int find(Vec* v, const s32& key) {
    int i;
    for (i = 0; i < v->count; i++) {
        if (key == v->elems[i].key)
            return i;
    }
    return -1;
}

inline void erase(Vec* v, s32 found) {
    if (found >= 0) {
        if (v->isLast(found)) {
            v->count--;
        } else {
            v->count--;
            v->elems[found] = v->elems[v->count];
        }
    }
}

inline void remove(Vec* v, const s32& key) {
    s32 found = find(v, key);
    if (v->elems[found].data) {
        fn_80096048(v->elems[found].data, 1);
        v->elems[found].data = 0;
    }
    erase(v, found);
}

inline void destroy(Vec* v) {
    if (v && v->isOwned())
        fn_8027EABC(lbl_805A0EC8, v->elems, v->flags << 3, 0x15);
}

extern "C" Vec* fn_80099994(Vec* self, s32 destroyFlag) {
    s32 i;
    s32 found;
    Vec* v = self;
    s32 flag = destroyFlag;

    if (v) {
        s32 offset;
        for (i = 0, offset = 0; i < v->count; offset += sizeof(Elem), i++) {
            if (((Elem*)((u8*)v->elems + offset))->data) {
                fn_80096048(((Elem*)((u8*)v->elems + offset))->data, 1);
                ((Elem*)((u8*)v->elems + offset))->data = 0;
            }
        }

        v->clearElements();

        if (v->isOwned())
            fn_8027EABC(lbl_805A0EC8, v->elems, v->flags << 3, 0x15);

        v->elems = 0;
        v->count = 0;
        v->flags = (v->flags & 0x40000000) | 0x80000000;
        destroy(v);

        if (flag > 0)
            __dl__FPv(v);
    }

    return self;
}
