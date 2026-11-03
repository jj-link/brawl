#pragma force_active on

typedef unsigned short u16;

struct DictEntry {
    int offset;
    char pad[0xC];
};

struct DictTable {
    char pad[0x24];
    DictEntry items[1];
};

struct TableRef {
    DictTable* ptr;

    TableRef(DictTable* p) : ptr(p) {}

    int* getData(u16 i) const {
        if (ptr) {
            int off = ptr->items[i].offset;
            if (off)
                return (int*)((char*)ptr + off);
            else
                return 0;
        } else {
            return 0;
        }
    }
};

struct Resource {
    char pad0[0x10];
    int dictionaryOffset;
    char pad14[0xA];
    u16 count;

    TableRef getTable() {
        if (dictionaryOffset)
            return TableRef((DictTable*)((char*)this + dictionaryOffset));
        return TableRef(0);
    }
};

struct Object {
    char pad0[0x14];
    u16* indices;
    char pad18[0x14];
    Resource* resource;
};

struct Match {
    char pad[0xC];
    int index;
};

extern "C" Match* fn_8018F29C(void*, void**, void*);
extern "C" void fn_8019DA5C(Object*, int, int);

static inline Match* Find(void* arg, int* entry) {
    char* data = (char*)(*entry + (unsigned int)entry);
    void* name = data - 4;
    return fn_8018F29C(arg, &name, data);
}

extern "C" bool fn_80199778(Object* self, void* arg) {
    int count = self->resource->count;
    bool result = false;
    u16 i = 0;
    for (; i < count; ++i) {
        Match* found = Find(arg, self->resource->getTable().getData(i));
        if (found) {
            result = true;
            self->indices[found->index] = i;
        }
    }
    fn_8019DA5C(self, 4, 1);
    return result;
}