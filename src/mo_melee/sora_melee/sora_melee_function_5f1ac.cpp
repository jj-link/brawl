#pragma force_active on
extern "C" float lbl_27_rodata_82C;

struct Entry {
    char padding[0x94];
    float value;
};

struct Array {
    virtual void unused();
    virtual Entry* at(int);
};

struct Prefix {
    char padding[8];
};

struct Object : Prefix {
    virtual void unused0(), unused1(), unused2(), unused3(), unused4();
    virtual void unused5(), unused6(), unused7(), unused8(), unused9();
    virtual void unused10(), unused11(), unused12(), unused13(), unused14();
    virtual void unused15(), unused16();
    virtual void set(int, float);
    virtual float get();

    char padding1[0x34];
    Array* array;
};

extern "C" void fn_27_5F1AC(Object* self, int index, float amount) {
    float value = self->get();
    if (value + amount < lbl_27_rodata_82C) {
        amount = -value;
    }
    if (amount + (value + self->array->at(index)->value) < lbl_27_rodata_82C) {
        Entry* entry = self->array->at(index);
        amount = -value - entry->value;
    }
    self->set(index, amount);
}
