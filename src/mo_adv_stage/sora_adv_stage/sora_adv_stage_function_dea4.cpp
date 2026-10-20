#pragma force_active on
struct Pair {
    unsigned int x, y;
};

struct Object {
    unsigned int field_00;
    virtual void unused0();
    virtual void unused1();
    virtual void* get();
    unsigned char padding_08[0x14];
    int field_1c;
    unsigned char padding_20[0x1c];
    Pair field_3c;
};

extern "C" void fn_27_234DDC(Object*, int, Pair*);
extern "C" void fn_80010F70(void*, Pair*);

extern "C" void fn_40_DEA4(Object* self, int arg, const Pair* value) {
    Pair copy = *value;
    fn_27_234DDC(self, arg, &copy);
    if (self->field_1c != 0) {
        fn_80010F70(self->get(), &self->field_3c);
    }
}
