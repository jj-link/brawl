#pragma force_active on
class Entry {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int);
};
struct Object {
    char pad[0xE4];
    Entry** entries;
    int count;
};
extern "C" void fn_802F3D80(Object* self, int arg) {
    for (int i = self->count - 1; i >= 0; --i) {
        Entry* entry = self->entries[i];
        if (entry != 0) {
            entry->f3(arg);
        }
    }
    int j;
    int i = self->count - 1;
    int offset = i * 4;
    for (; i >= 0; offset -= 4, --i) {
        if (*(Entry**)((char*)self->entries + offset) == 0) {
            j = i;
            --self->count;
            unsigned shiftOffset = (unsigned)j * 4;
            for (; j < self->count; ++j, shiftOffset += 4) {
                Entry** p = (Entry**)((char*)self->entries + shiftOffset);
                p[0] = p[1];
            }
        }
    }
}
