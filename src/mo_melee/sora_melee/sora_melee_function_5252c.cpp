#pragma force_active on
#pragma inline_depth(4)

struct Entry {
    int pad;
    int key;
};

class Lookup {
public:
    virtual void slot0();
    virtual Entry* get(int idx);
};

struct Owner {
    char pad[0x10];
    Lookup* lookup;
};

extern "C" int fn_27_5252C(Owner* self, int key, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;
    int value = self->lookup->get(mid)->key;
    if (value == key) {
        return -1;
    }
    if (value < key) {
        if (lo == hi) {
            return mid + 1;
        }
        return fn_27_5252C(self, key, mid + 1, hi);
    }
    if (value > key) {
        if (lo == hi) {
            return mid;
        }
        return fn_27_5252C(self, key, lo, mid);
    }
    return -1;
}