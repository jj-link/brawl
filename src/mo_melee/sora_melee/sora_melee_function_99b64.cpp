#pragma force_active on
typedef unsigned char u8;

struct Entry {
    char pad[0x28];
    u8 state;
};

class Class_CF8 {
public:
    virtual void fn_27_1000C();
    virtual Entry* fn_27_100D0(int);
    virtual void fn_27_100CC();
    virtual int fn_27_10094();
};

struct Self {
    char pad[0x4c];
    Class_CF8* array;
};

extern "C" void fn_27_99B64(Self* self) {
    int n = self->array->fn_27_10094();
    for (int i = 0; i < n; ++i) {
        if (self->array->fn_27_100D0(i)->state == 1)
            self->array->fn_27_100D0(i)->state = 0;
    }
}
