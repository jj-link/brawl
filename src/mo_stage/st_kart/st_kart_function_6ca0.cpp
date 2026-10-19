#pragma force_active on
struct Elem {
    unsigned char data[0x38];
};

struct Owner {
    unsigned int pad[2];
    int count;
    Elem elems[1];
};

extern "C" Elem* fn_49_6CA0(Owner* self, int index) {
    int i = (self->count >> 30) + index;
    if (i >= 1) {
        i -= 1;
    }
    return &self->elems[i];
}
