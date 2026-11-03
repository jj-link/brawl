#pragma force_active on

struct Element {
    float x;
    float y;
    float z;
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
};

struct Container {
    virtual void slot0();
    virtual Element* at(int index);
    virtual void slot2();
    virtual int size();
};

extern "C" void fn_27_1B7B2C(Container* self, int start, const Element* value,
                             unsigned int countArg) {
    int count = static_cast<int>(countArg);
    if (count + start >= self->size())
        count = self->size() - start;
    for (int i = 0; i < count; ++i) {
        Element* dst = self->at(start + i);
        dst->x = value->x;
        dst->y = value->y;
        dst->z = value->z;
        dst->b0 = value->b0;
        dst->b1 = value->b1;
        dst->b2 = value->b2;
        dst->b3 = value->b3;
        dst->b4 = value->b4;
    }
}