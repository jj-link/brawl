#pragma force_active on
struct Item1 {
    char pad[4];
    float a, b;
    char pad2[0x10];
    int id;
};
struct Item2 {
    char pad[0x14];
    float a, b;
    char pad2[0xc];
    int id;
};
class Class_CF8 {
public:
    virtual void fn_27_1000C();
    virtual Item1* fn_27_100D0(int);
    virtual void fn_27_100CC();
    virtual int fn_27_10094();
};
class Class_C80 {
public:
    virtual void fn_27_FEE4();
    virtual Item2* fn_27_FF68(int);
    virtual void fn_27_FFAC();
    virtual int fn_27_FFF0();
};
struct Owner {
    char pad[0x40];
    float a, b;
    char pad2[0x14];
    float c, d;
    char pad3[0xc];
    float e, f;
    char pad4[0x10];
    int id;
    Class_CF8* list1;
    Class_C80* list2;
    char pad5[0xd0];
    unsigned char flags1, flags2;
};
extern "C" void fn_27_191CC(Owner* self) {
    self->b = self->a;
    if (self->id != -1) {
        self->f = self->e;
        self->d = self->c;
    }
    int count = self->list1->fn_27_10094();
    for (int i = 0; i < count; ++i) {
        Item1* item = self->list1->fn_27_100D0(i);
        if (item->id != -1)
            item->b = item->a;
    }
    count = self->list2->fn_27_FFF0();
    for (int i = 0; i < count; ++i) {
        Item2* item = self->list2->fn_27_FF68(i);
        if (item->id != -1)
            item->b = item->a;
    }
    self->flags1 &= ~8;
    self->flags2 &= ~2;
}