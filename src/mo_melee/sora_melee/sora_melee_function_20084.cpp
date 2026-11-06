#pragma force_active on
class Class_CF8 {
public:
    virtual void fn_27_1000C();
    virtual void fn_27_100D0();
    virtual void fn_27_100CC();
    virtual void fn_27_10094();
    virtual void fn_27_100C8();
    virtual void fn_27_100C4(float);
};
struct Context {
    Class_CF8* objects[5];
    float value;
    char padding[12];
    unsigned char unused : 2;
    unsigned char disabled : 1;
    unsigned char remaining : 5;
};
extern "C" void fn_27_20084(Context* self, float value) {
    if (!self->disabled) {
        if (self->objects[0]) self->objects[0]->fn_27_100C4(value);
        if (self->objects[1]) self->objects[1]->fn_27_100C4(value);
        if (self->objects[2]) self->objects[2]->fn_27_100C4(value);
        if (self->objects[3]) self->objects[3]->fn_27_100C4(value);
        if (self->objects[4]) self->objects[4]->fn_27_100C4(value);
        self->value = value;
    }
}