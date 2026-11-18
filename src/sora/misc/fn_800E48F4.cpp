#include <types.h>
#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(void*);
};
struct E { char pad[0x10]; void* f; };
struct Entry { unsigned char id; int active; E* obj; };
struct Pair { int active; E* obj; };
struct Temp { unsigned char id; Pair pair; Temp(const Entry& e) : id(e.id), pair(*(const Pair*)&e.active) {} };
struct Main { char pad0[0xF4]; Object_vptr_0* manager; char pad1[0x170]; Entry entries[3]; };
extern "C" void fn_801B4CB0(Object_vptr_0*, void*, int);
extern "C" void fn_800B22B8(E*);
extern "C" unsigned char fn_800E48F4(char* self, int index) {
    int offset = index * 12;
    unsigned char result;
    Object_vptr_0* manager;
    Entry* selected;
    char* q;
    char* p;
    int k;
    int j;
    int i;
    manager = *(Object_vptr_0**)(self + 0xF4);
    selected = &((Main*)self)->entries[index];
    if (selected->active == 0)
        return 0xFF;
    result = selected->id;
    p = self;
    for (j = 0; j < 3; j++, p += 0xC) {
        if (*(int*)(p + 0x26C) == 0) break;
        manager->slot13((*(E**)(p + 0x270))->f);
    }
    Temp temp(*(Entry*)(self + offset + 0x268));
    unsigned char tid = selected->id;
    for (i = index; i < 2; i++) {
        ((Main*)self)->entries[i].id = ((Main*)self)->entries[i + 1].id;
        ((Main*)self)->entries[i].active = ((Main*)self)->entries[i + 1].active;
        ((Main*)self)->entries[i].obj = ((Main*)self)->entries[i + 1].obj;
    }
    ((Main*)self)->entries[2].id = tid;
    ((Main*)self)->entries[2].obj = temp.pair.obj;
    ((Main*)self)->entries[2].active = 0;
    q = self;
    for (k = 0; k < 3; k++, self += 0xC, q += 4) {
        if (*(int*)(self + 0x26C) == 0) break;
        fn_801B4CB0(manager, (*(E**)(self + 0x270))->f, *(int*)(q + 0x5C4));
        fn_800B22B8(*(E**)(self + 0x270));
    }
    return result;
}