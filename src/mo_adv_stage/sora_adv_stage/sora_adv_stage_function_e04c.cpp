#pragma force_active on
struct Pair {
    unsigned int first;
    unsigned int second;
};

struct Base {
    unsigned int unk0;
};

struct Object : Base {
    virtual void unused0();
    virtual void unused1();
    virtual void* get();

    unsigned char unk8[0x14];
    unsigned int active;
    unsigned char unk20[0x1c];
    Pair value;
};

extern "C" void fn_27_234DDC(Object*, unsigned int, Pair*);
extern "C" void fn_80010F70(void*, Pair*);

extern "C" void fn_40_E04C(Object* self, unsigned int arg, const Pair* value)
{
    Pair copy = *value;
    fn_27_234DDC(self, arg, &copy);
    if (self->active != 0) {
        fn_80010F70(self->get(), &self->value);
    }
}
