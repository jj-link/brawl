#pragma force_active on

struct Id {
    int kind;
    unsigned int index;
};

struct Entry {
    int unk;
    Id id;

    Id getId() const {
        return id;
    }
};

struct Array {
    virtual void v0();
    virtual void v1();
    virtual Entry*& at(int);
    virtual int size();
};

struct Object {
    char pad[0x1170];
    Array array;

    Entry* find(Id id) {
        for (int i = 0; i < array.size(); ++i) {
            Entry* entry = array.at(i);
            if (entry && id.kind == entry->getId().kind &&
                id.index == entry->getId().index) {
                return entry;
            }
        }
        return 0;
    }
};

extern "C" bool fn_27_2B2A9C(Entry*);

extern "C" bool fn_27_2A8E3C(Object* self, const Id& id) {
    Entry* entry = self->find(id);
    if (!entry)
        return false;
    return fn_27_2B2A9C(entry);
}
