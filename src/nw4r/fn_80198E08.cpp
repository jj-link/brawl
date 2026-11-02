#pragma force_active on

typedef unsigned short u16;

struct Item { int offset; char pad[0xC]; };
struct Table {
    char pad[0x24];
    Item items[1];
};
struct TableRef {
    Table* ptr;
    TableRef(Table* p) : ptr(p) {}
    int* getData(u16 i) const {
        if (ptr) {
            int off = ptr->items[i].offset;
            if (off) return (int*)((char*)ptr + off);
            return 0;
        }
        return 0;
    }
};
struct Resource {
    char pad[0x10];
    int tableOffset;
    char pad14[0x1A];
    u16 count;
    TableRef getTable() {
        if (tableOffset) return TableRef((Table*)((char*)this + tableOffset));
        return TableRef(0);
    }
};
struct Node {
    char pad[0x14];
    u16* indices;
    char pad18[0x14];
    Resource* resource;
};
struct Name {
    void* data;
    Name(int* p) { data = (char*)(*(int*)p + (unsigned int)p) - 4; }
};
struct Result {
    char pad[0xC];
    int index;
};
extern "C" Result* fn_8018F29C(void*, Name*);
extern "C" void fn_8019DA5C(Node*, int, int);

extern "C" bool fn_80198E08(Node* self, void* arg) {
    int count = self->resource->count;
    bool found = false;
    u16 i = 0;
    for (; i < count; i++) {
        Name name(self->resource->getTable().getData(i));
        Result* result = fn_8018F29C(arg, &name);
        if (result) {
            found = true;
            self->indices[result->index] = i;
        }
    }
    fn_8019DA5C(self, 4, 1);
    return found;
}
