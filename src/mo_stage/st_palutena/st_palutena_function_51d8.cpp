#pragma force_active on
struct Fn67Elem {
    unsigned char data[0x68];
};

struct Fn67Container {
    int header[2];
    int field;
    Fn67Elem elems[1];
};

extern "C" void* fn_67_51D8(Fn67Container* self, int index) {
    int i = (self->field >> 30) + index;
    if (i >= 1) {
        i = i - 1;
    }
    return &self->elems[i];
}
