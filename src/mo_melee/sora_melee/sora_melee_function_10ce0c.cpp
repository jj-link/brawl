#pragma force_active on
class ftOwner {
public:
    int getStockCount();
};

struct Item {
    char pad0[4];
    int id;
    char pad1[0x20];
    ftOwner* owner;
};

class Member {
public:
    virtual void f0();
    virtual Item** getItem(int index);
    virtual void f4();
    virtual int getCount();
};

class Manager {
public:
    char pad[8];
    Member mem;
};

class Owner {
public:
    char pad[0x6A];
    unsigned char flag;
    char pad2[0x154 - 0x6B];
    Manager* mgr;
    inline int getCount() { return mgr->mem.getCount(); }
    inline Item* getItem(int i) { return *mgr->mem.getItem(i); }
};

extern "C" {
unsigned int fn_27_111A08(void*);
unsigned short fn_27_111AEC(void*);
unsigned int fn_27_111A7C(void*);
}

extern "C" int fn_27_10CE0C(Owner* self, int id) {
    if (self->flag == 1) {
        int own;
        int maxOther = 0;
        own = 0;
        int count = self->getCount();
        for (int i = 0; i < count; i++) {
            Item* item = self->getItem(i);
            int stocks = item->owner->getStockCount();
            if (id != item->id) {
                if (maxOther < stocks) {
                    maxOther = stocks;
                }
            } else {
                own = stocks;
            }
        }
        return maxOther - own;
    }

    int maxOther = 0;
    ftOwner* owner;
    int own = 0;
    int count = self->getCount();
    for (int i = 0; i < count; i++) {
        Item* item = self->getItem(i);
        owner = item->owner;
        int a = fn_27_111A08(owner);
        int b = a - fn_27_111AEC(owner);
        int c = fn_27_111A7C(item->owner) - b;
        if (id != item->id) {
            if (maxOther < c) {
                maxOther = c;
            }
        } else {
            own = c;
        }
    }
    return maxOther - own;
}
