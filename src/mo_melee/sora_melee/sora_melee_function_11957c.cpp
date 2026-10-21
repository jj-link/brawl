#pragma force_active on

struct Item {
    unsigned char pad[0x28];
    unsigned int id;
};

struct Entry {
    Item* item;
    unsigned int unknown;
};

struct Group {
    unsigned int unknown;
    int value;
    unsigned char count;
    unsigned char pad[0x2B];
    Entry entries[1];

    bool find(unsigned int id, int* index) {
        Item* item;
        int n = count;
        for (int i = 0; i < n; ++i) {
            item = entries[i].item;
            if (item && id == item->id) {
                if (index)
                    *index = i;
                return true;
            }
        }
        return false;
    }
};

struct Container {
    virtual void slot08();
    virtual void slot0C();
    virtual Group** get(int index);
    virtual int size();
};

struct Outer {
    unsigned char pad[8];
    Container container;
};

extern "C" int fn_27_11957C(Outer* self, unsigned int id, int* index) {
    int count = self->container.size();
    for (int i = 0; i < count; ++i) {
        if ((*self->container.get(i))->find(id, index) == true) {
            return (*self->container.get(i))->value;
        }
    }
    return -1;
}
