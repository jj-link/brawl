#pragma force_active on
struct Data;
struct Matrix { float x[12]; };
struct Item { char x[0x10c]; };
class Class_80466278 {
public:
    virtual void fn_801AC270();
    virtual void fn_801AB9D8(int, int, Matrix*);
    char pad[0xf0];
    unsigned char index;
    char pad3[3];
    Item items[1];
};
extern "C" void fn_801F0248();
extern "C" Data** fn_801A7550(Data**, void*);
extern "C" void fn_801A7DBC(Data**, Matrix*);
extern "C" void fn_801ACBEC(Class_80466278* self) {
    fn_801F0248();
    Data* data;
    Data* tmp;
    data = *fn_801A7550(&tmp, &self->items[self->index]);
    Matrix matrix;
    fn_801A7DBC(&data, &matrix);
    self->fn_801AB9D8(4, 0, &matrix);
}