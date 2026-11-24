#pragma force_active on
#include <types.h>
extern "C" void fn_8027CE3C(void*, int);
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;
class Class_802D7674 {
public:
    Class_802D7674() { data = buf; size = 0; capacity = 0x80000100; }
    ~Class_802D7674() {
        if (isOwned()) {
            dealloc();
        }
    }
    bool isOwned() const {
        return (capacity & 0x80000000) == 0;
    }
    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, (capacity * 2) & 0x7FFFFFFE, 0x15);
    }
    int find(u16 id) {
        for (int i = 0; i < size; i++) {
            if (id == data[i]) return i;
        }
        return -1;
    }
    u16* data;
    s32 size;
    s32 capacity;
    u16 buf[256];
};
struct Flag { s8 value; operator bool() const { return value != 0; } };
struct Sel { u16 flags; u16 id; };
struct Ent16 { s32 a0; s32 a4; s32 a8; u32 flags; };
struct Pair { u32 a; u32 b; };
struct PairArr { Pair* data; s32 size; s32 capacity; };
struct U16Arr { s32 unk0; u16* data; s32 size; s32 capacity; int find(const u16& id) { for (int i = 0; i < size; i++) { if (id == data[i]) return i; } return -1; } };
struct Obj {
    char pad0[0x70]; Ent16* table; char pad1[0x8]; Sel* begin;
    s32 count; char pad2[0x24]; char* lists;
};
template<class EntryPtr>
static inline void linkEntry(Obj* self, PairArr* out, Flag flag, EntryPtr e, Ent16* cur, U16Arr*& ua) {
    s32 curMax;
    s32 curMin;
    s32 otherMax;
    s32 otherMin;
    Ent16* owner;
    Ent16* idxEnt;
    owner = cur;
    curMax = cur->a4;
    curMin = cur->a0;
    otherMax = e->a4;
    idxEnt = e;
    otherMin = e->a0;
    otherMax -= curMin;
    curMax -= otherMin;
    otherMax |= curMax;
    if ((otherMax & 0x80008000) != 0) return;
    if (!(cur->flags & 1)) {
        if (!(e->flags & 1)) {
            if (out->size == (out->capacity & 0x3FFFFFFF)) fn_8027CE3C(out, 8);
            Pair* data;
            s32 n = out->size;
            data = out->data;
            out->size = n + 1;
            Pair* pair = data + n;
            pair->a = e->flags;
            pair->b = cur->flags;
            return;
        }
        Ent16* nextOwner = idxEnt;
        idxEnt = owner;
        owner = nextOwner;
    }
    s32 off = ((s32)((char*)idxEnt - (char*)self->table)) / 16;
    ua = (U16Arr*)(self->lists + (owner->flags & ~1u));
    if (flag) {
        u16 value = off;
        if (ua->size == (ua->capacity & 0x3FFFFFFF)) fn_8027CE3C(&ua->data, 2);
        ua->data[ua->size++] = value;
    } else {
        s32 idx = ua->find(off);
        ua->size--;
        ua->data[idx] = ua->data[ua->size];
    }
}
extern "C" void fn_8030D7C8(Obj* self, u32* masks, PairArr* out, Flag flag) {
    U16Arr* ua;
    Ent16* other;
    Class_802D7674 maskArr;
    Class_802D7674 localArr;
    Sel* end = self->begin + (self->count - 1);
    for (Sel* p = self->begin + 1; p < end; p++) {
        s32 id = p->id;
        u32 bit = 1u << (id & 31);
        u32 m = bit & masks[id >> 5];
        if (p->flags & 1) {
            Class_802D7674* t = m != 0 ? &maskArr : &localArr;
            s32 idx = t->find(id);
            t->size--;
            t->data[idx] = t->data[t->size];
        } else {
            Ent16* cur = (Ent16*)((char*)self->table + ((s32)id << 4));
            s32 offset;
            s32 i = 0;
            offset = 0;
            for (; i < maskArr.size; i++) {
                linkEntry(self, out, flag, self->table + *(u16*)((char*)maskArr.data + offset), cur, ua);
                offset += 2;
            }
            if (m != 0) {
                for (s32 i = 0; i < localArr.size; i++) {
                    other = self->table + localArr.data[i];
                    linkEntry<Ent16*&>(self, out, flag, other, cur, ua);
                }
                if (maskArr.size == (maskArr.capacity & 0x3FFFFFFF)) fn_8027CE3C(&maskArr, 2);
                maskArr.data[maskArr.size++] = id;
            } else {
                if (localArr.size == (localArr.capacity & 0x3FFFFFFF)) fn_8027CE3C(&localArr, 2);
                localArr.data[localArr.size++] = id;
            }
        }
    }
}
