#pragma force_active on
typedef unsigned long long u64;

struct Id {
    int kind;
    unsigned int index;
};

union IdValue {
    Id id;
    u64 value;
};

extern "C" Id lbl_27_bss_6490;
extern "C" Id lbl_27_bss_6498;

struct Entry {
    int unk;
    Id id;

    IdValue getId() const {
        IdValue v;
        v.id = id;
        return v;
    }
};

struct Array {
    virtual void v0();
    virtual void v1();
    virtual Entry*& at(int);
    virtual int size();
};

struct Object {
    char pad0[0x50];
    int state;
    char pad1[0x1170 - 0x54];
    Array array;
    char pad2[0x14B0 - 0x1174];
    int extra;
};

extern "C" bool fn_27_2B2A9C(Entry*);
extern "C" bool fn_27_2B2BA4(Entry*, int, int);

extern "C" u64 fn_27_2A904C(Object* self) {
    IdValue result;
    result.id = lbl_27_bss_6490;
    int extra = self->extra;

    if (self->state == 2)
        result.id = lbl_27_bss_6498;
    else
        extra = 0;

    if (self->array.size() > 1) {
        for (int i = 0; i < self->array.size(); ++i) {
            Entry* entry = self->array.at(i);
            if (entry && fn_27_2B2A9C(entry)) {
                IdValue temp = entry->getId();
                Id& id = temp.id;

                if ((id.kind != lbl_27_bss_6490.kind ||
                     id.index != lbl_27_bss_6490.index) &&
                    (id.kind != lbl_27_bss_6498.kind ||
                     id.index != lbl_27_bss_6498.index)) {
                    if (fn_27_2B2BA4(entry, 10000, extra)) {
                        result.id = id;
                        break;
                    }
                }
            }
        }
    }

    return result.value;
}
