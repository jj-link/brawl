#pragma force_active on
#include <types.h>

struct Item {
    int offset;
    char pad[0xC];
};

struct Table {
    char pad[4];
    u32 count;
    char pad2[0x1C];
    Item items[1];
};

struct Data {
    char pad[4];
    int offset;
};

struct TableRef {
    Table* ptr;
    TableRef(Table* p) : ptr(p) {}
    Data* getData(u16 i) const {
        if (ptr) {
            int off = ptr->items[i].offset;
            if (off)
                return (Data*)((char*)ptr + off);
            return 0;
        }
        return 0;
    }
    u32 getCount() const {
        if (ptr)
            return ptr->count;
        return 0;
    }
};

struct Resource {
    char pad[0x10];
    int tableOffset;
    int namesOffset;
    char pad18[0xA];
    u16 count;

    TableRef getTable() {
        if (tableOffset)
            return TableRef((Table*)((char*)this + tableOffset));
        return TableRef(0);
    }

    int* getNames() {
        if (namesOffset)
            return (int*)((char*)this + namesOffset);
        return 0;
    }
};

struct Result {
    char pad[0x10];
    int index;
};

struct Triple {
    Result* a;
    void* b;
    void* c;
};

struct Node {
    char pad[0x14];
    u16* indices;
    char pad18[0x14];
    Resource* resource;
    Triple* triples;
};

extern "C" Result* fn_8018EE80(void*, void**, void*);
extern "C" void* fn_8018EFAC(void*, void**);
extern "C" void* fn_8018F0D8(void*, void**);
extern "C" void fn_8019DA5C(Node*, int, int);

extern "C" bool fn_8019BFF4(Node* self, void* arg) {
    bool found = false;
    void* entry;
    int offset;
    int* cur;
    u32 count = self->resource->getTable().getCount();
    u16 i;
    for (i = 0; i < count; i++) {
        Data* d = self->resource->getTable().getData(i);
        char* data = (char*)(d->offset + (unsigned int)d);
        void* name = data - 4;
        Result* r = fn_8018EE80(arg, &name, data);
        if (r) {
            found = true;
            self->indices[r->index] = i;
        }
    }

    Resource* res = self->resource;
    u16 n = res->count;
    int* names = res->getNames();
    cur = names;
    int j = 0;
    offset = 0;
    for (; j < n; j++) {
        Triple* t = (Triple*)((char*)self->triples + offset);
        char* data = (char*)names + *cur;
        entry = data - 4;
        void* n1 = entry;
        t->a = fn_8018EE80(arg, &n1, data);
        void* n2 = entry;
        t->b = fn_8018EFAC(arg, &n2);
        void* n3 = entry;
        t->c = fn_8018F0D8(arg, &n3);
        offset += 12;
        cur++;
    }

    fn_8019DA5C(self, 4, 1);
    return found;
}
