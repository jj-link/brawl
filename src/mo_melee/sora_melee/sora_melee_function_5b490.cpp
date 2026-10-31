#pragma force_active on
struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void notify(int, int);
    unsigned char padding[0x20];
    signed char* values;
    unsigned int unused;
    unsigned char changed;
};
extern "C" void fn_27_5B490(Object* self, int index, signed char value, unsigned int notify) {
    self->values[index * 3] = value;
    self->changed = 1;
    if (notify == 1) {
        return self->notify(index, self->values[index * 3]);
    }
}
