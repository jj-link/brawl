#pragma force_active on

typedef unsigned char u8;

extern "C" int fn_27_8CC68(void*, int);

struct Entry {
    int unk;
    void* object;
};

struct Item {
    int unk;
    int id;
    u8 count;
    u8 pad[0x27];
    Entry entries[1];

    bool find(int key, int* out) {
        Item* entry = this;
        int n = count;
        for (int i = 0; i < n;
             entry = (Item*)((char*)entry + 8), ++i) {
            if (entry->entries[0].object &&
                fn_27_8CC68(entry->entries[0].object, key) != -1) {
                if (out) {
                    *out = i;
                }
                return true;
            }
        }
        return false;
    }
};

struct List {
    virtual void f0();
    virtual void f1();
    virtual Item** get(int);
    virtual int size();
};

struct Owner {
    u8 pad[8];
    List list;
};

extern "C" int fn_27_11947C(Owner* self, int key, int* out) {
    int count = self->list.size();
    for (int i = 0; i < count; ++i) {
        if ((*self->list.get(i))->find(key, out) == true) {
            return (*self->list.get(i))->id;
        }
    }
    return -1;
}
