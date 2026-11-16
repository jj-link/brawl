#pragma force_active on

extern "C" void fn_8027CE3C(void*, int);
extern "C" void fn_802EA268(void*, void*);

struct Entry {
    unsigned char pad0[4];
    unsigned short flag4;
    short counter6;
    unsigned char pad8[4];
    void* owner;
};

struct Obj {
    unsigned char pad0[0x22];
    unsigned short index;
    unsigned char pad24[2];
    unsigned char hi : 2;
    unsigned char mode : 2;
    unsigned char lo : 4;
};

struct Self {
    unsigned char pad0[0x20];
    Obj* obj;
    unsigned char pad24[0x1C];
    Obj** objs;
    int objCount;
    unsigned int objCap;
};

struct List {
    Entry** data;
    int size;
    unsigned int cap;
};

struct Arg1 {
    unsigned char pad0[0x1D8];
    Entry** entries;
    int count;
};

extern "C" void fn_802F88CC(Self* self, Arg1* arg1, List* list) {
    Entry* entry;
    int offset;
    int i;
    int e;
    Obj* obj;

    for (i = 0, offset = 0; i < arg1->count; offset += 4, i++) {
        entry = *(Entry**)((char*)arg1->entries + offset);
        if (entry->owner == self->obj) {
            if (list->size == (int)(list->cap & 0x3FFFFFFF)) {
                fn_8027CE3C(list, 4);
            }
            list->data[list->size++] = entry;
            if (entry->flag4 != 0) {
                entry->counter6++;
            }
            fn_802EA268(self->obj, entry);
            self->obj->mode = 1;
            obj = self->obj;
            if (obj->index == 0xFFFF) {
                obj->index = (unsigned short)self->objCount;
                if (self->objCount == (int)(self->objCap & 0x3FFFFFFF)) {
                    fn_8027CE3C(&self->objs, 4);
                }
                self->objs[self->objCount++] = obj;
            }
        }
    }
}