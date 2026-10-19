#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Entry {
    u8 flags : 1;
    u8 rest : 7;

    bool enabled() const { return flags; }
};

struct Array {
    virtual void dummy();
    virtual Entry* at(int);
};

struct Object {
    u8 pad[0x10];
    u32 value;
    u8 flags : 1;
    u8 rest : 7;
    u8 pad15[3];
    Array* entries;

    bool enabled() const { return flags; }
};

extern "C" void fn_27_B180C(Entry*, int, int, u32, bool);

extern "C" void fn_27_B2668(Object* self, int index, int a, int b) {
    if (self->enabled()) {
        bool flag = false;
        if (self->enabled() == true &&
            self->entries->at(index)->enabled() == true) {
            flag = true;
        }
        fn_27_B180C(self->entries->at(index), a, b, self->value, flag);
    }
}
