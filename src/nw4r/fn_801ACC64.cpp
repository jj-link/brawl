#pragma force_active on
struct Data {
    char pad[0x70];
    unsigned int flags;
    char pad2[0x38];
    float a, b, c, d, e, f, g, h;
};
struct Matrix { float x[12]; };
struct Output { char x[0xf0]; };
struct Item { char x[0x10c]; };
class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
};
class Class_80466278 {
public:
    virtual void fn_801AC270();
    virtual void fn_801AB9D8(int, int, Class_8042B6D0*);
    virtual void fn_801AC1AC();
    char pad[0xe4];
    Class_8042B6D0* object;
    char pad2[8];
    unsigned char index;
    char pad3[3];
    Item items[1];
};
extern "C" Data** fn_801A7550(Data**, void*);
extern "C" void fn_801A7DBC(Data**, Matrix*);
extern "C" void fn_80162FD0(Output*, Matrix*, float, float, float, float);
extern "C" void fn_80163084(Output*, Matrix*, float, float, float, float, float, float);
extern Output* lbl_805A0558;
extern "C" void fn_801ACC64(Class_80466278* self) {
    self->object->fn_80046A28();
    Data* data;
    Data* tmp;
    data = *fn_801A7550(&tmp, &self->items[self->index]);
    Matrix matrix;
    fn_801A7DBC(&data, &matrix);
    Output out;
    if (data->flags & 0x20)
        fn_80162FD0(&out, &matrix, data->a, data->b, data->c, data->d);
    else
        fn_80163084(&out, &matrix, data->e, data->f, data->g, data->h, data->c, data->d);
    lbl_805A0558 = &out;
    self->fn_801AB9D8(5, 0, self->object);
    lbl_805A0558 = 0;
}