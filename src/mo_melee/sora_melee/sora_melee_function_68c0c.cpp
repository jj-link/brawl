#pragma force_active on

struct Entry {
    unsigned char flag80 : 1;
    unsigned char flags : 7;
    char pad[7];
    int value;
    unsigned char state;
};

class Class_CF8 {
public:
    virtual void fn_27_1000C();
    virtual Entry* fn_27_100D0(int);
    virtual void fn_27_100CC();
    virtual int fn_27_10094();
};

struct Self {
    char pad[0x14];
    Class_CF8* array;
    int current;
};

extern "C" void fn_27_68C0C(Self* self) {
    int n = self->array->fn_27_10094();
    for (int i = 0; i < n; ++i) {
        Entry* entry = self->array->fn_27_100D0(i);
        entry->value = 0;
        entry->state = 0;
        entry->flag80 = 0;
    }
    self->current = -1;
}
