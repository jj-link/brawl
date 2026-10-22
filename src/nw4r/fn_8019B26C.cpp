#pragma force_active on

typedef unsigned short u16;
inline void* nameAddress(int* base, int offset) {
    return (void*)(offset + (unsigned int)base);
}
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
    char pad14[0xA];
    u16 count;
    TableRef getTable() {
        if (tableOffset) return TableRef((Table*)((char*)this + tableOffset));
        return TableRef(0);
    }
    int getCount() const { return count; }
};
struct Node {
    char pad[0x14];
    u16* indices;
    char pad18[0x14];
    Resource* resource;
};
struct Entry {
    char pad[0xC];
    int index;
    int getIndex() const { return this ? index : 0; }
};
struct Name {
    void* data;
    Name(int* p) { data = (char*)nameAddress(p, *p) - 4; }
};
extern "C" Entry* fn_8018ED54(void*, Name*);
extern "C" void fn_8019DA5C(Node*, int, int);

extern "C" bool fn_8019B26C(Node* self, void* arg) {
    bool result = false;
    int count = self->resource->getCount();
    u16 i = 0;
    for (; i < count; i++) {
            Name name(self->resource->getTable().getData(i));
            Entry* entry = fn_8018ED54(arg, &name);
            if (entry) {
                self->indices[entry->getIndex()] = i;
                result = true;
            }
    }
    fn_8019DA5C(self, 4, 1);
    return result;
}
