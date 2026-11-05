#pragma force_active on
extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" void fn_8006BCA8(char*, const void*);
extern "C" int strcmp(const char*, const char*);
struct NameSlot { unsigned char pad0[0xE0]; unsigned short used; unsigned char raw[10]; unsigned char pad1[0x38]; };
struct RawName { unsigned short chars[6]; };
struct Manager { unsigned char pad[0x28]; NameSlot* slots; unsigned char pad2[4]; unsigned char* data; };
struct Input { int name; int data; };
static inline int getName(NameSlot* slot, void* out) {
    if (slot->used == 0) return 0;
    memcpy(out, &slot->used, 12);
    return 1;
}
struct Work { RawName raw; char buf[24]; char name[32]; };
static inline int findName(Manager* mgr, Work& work, int& count, int& index, int& off) {
    while (index < count) {
        NameSlot* slot = (NameSlot*)((char*)mgr->slots + off);
        if (getName(slot, &work.raw)) fn_8006BCA8(work.buf, &work.raw);
        if (strcmp(work.name, work.buf) == 0) return index;
        off += 0x124;
        ++index;
    }
    return -1;
}
extern "C" void fn_8004EFA8(Manager* mgr, Input* input) {
    memcpy(mgr->data, (char*)input + input->data, 0x4910);
    Work work;
    fn_8006BCA8(work.name, (char*)input + input->name + 6);
    int count = 0;
    int i;
    NameSlot* p = mgr->slots;
    for (i = 0; i < 120; ++p, ++i) { if (p->used) ++count; }
    int index;
    int off;
    index = 0;
    off = 0;
    index = findName(mgr, work, count, index, off);
    int result = 0x78;
    if (index >= 0) result = index;
    mgr->data[0x600] = result;
}