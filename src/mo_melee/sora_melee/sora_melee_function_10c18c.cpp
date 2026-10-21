#pragma force_active on

struct Vec2 {
    float x;
    float y;
};

struct Obj;
struct Object;

struct Entry {
    char pad[0x28];
    Obj** destination;
    Object* source;
};

struct Container {
    virtual void v0();
    virtual Entry*& get(int index);
    virtual void v2();
    virtual int count();
};

struct Collection {
    char pad[8];
    Container entries;
};

struct Pad {
    unsigned int value;
};

struct Provider : Pad {
    virtual void v0();
    virtual void v1();
    virtual unsigned long long first();
    virtual unsigned long long second();
    virtual void* argument();
};

struct Owner {
    char pad0[0x6C];
    unsigned char flags;
    char pad1[0x154 - 0x6D];
    Collection* collection;
};

extern "C" Provider* fn_27_1240B8(Object* self);
extern "C" void fn_27_112158(Obj** p, void* arg, const Vec2* a, const Vec2* b);

extern "C" void fn_27_10C18C(Owner* self) {
    int count = self->collection->entries.count();
    for (int i = 0; i < count; ++i) {
        Entry* entry = self->collection->entries.get(i);
        Provider* provider = fn_27_1240B8(entry->source);
        unsigned long long first;
        unsigned long long second = provider->second();
        first = provider->first();
        entry = reinterpret_cast<Entry*>(entry->destination);
        fn_27_112158(reinterpret_cast<Obj**>(entry), provider->argument(),
                      reinterpret_cast<const Vec2*>(&first),
                      reinterpret_cast<const Vec2*>(&second));
    }
    self->flags |= 0x10;
}
