#include <types.h>
#pragma force_active on
extern "C" int fn_8027C83C(int);
extern "C" void fn_8027D0B8(void*, u32, int);
extern "C" int fn_803318EC(void*, u32);
struct Class_entry { int* ptr; int key; };
struct Class_inner { char pad[0x30]; Class_entry* list; int count; };
class Class_80488E98 {
public:
    virtual void fn_8032FBA0();
    virtual void fn_80080A64();
    virtual void fn_80331770();
    virtual void fn_803316E8();
    virtual void fn_803301B0();
    virtual void fn_803315C8();
    virtual void fn_8033026C(int, int);
    virtual void fn_803315C0(u32);
    void* pad4;
    Class_inner* sub8;
    Class_entry* entries;
    char pad10[8];
    char map18[0x1c];
    u32 key34;
    int val38;
};
inline void replace(Class_80488E98* self, u32 key, int val) {
    int idx = fn_803318EC(&self->entries, key);
    if (val != 0) {
        fn_8027D0B8(&self->map18, val, idx);
    }
    while (idx != -1) {
        *self->entries[idx].ptr = val;
        idx = self->entries[idx].key;
    }
    int i = 0;
    Class_entry* e;
    int off = 0;
    while (i < self->sub8->count) {
        e = (Class_entry*)((char*)self->sub8->list + off);
        if ((u32)e->key == key) {
            e->key = val;
        }
        off += 8;
        i++;
    }
}
extern "C" void fn_803315C8(Class_80488E98* self, u32 key, int val, int tmp) {
    if (key == self->key34) {
        self->key34 = val;
        self->val38 = fn_8027C83C(tmp);
    }
    replace(self,key,val);
    self->fn_803315C0(key);
    if (tmp != 0) {
        self->fn_8033026C(val, fn_8027C83C(tmp));
    }
}