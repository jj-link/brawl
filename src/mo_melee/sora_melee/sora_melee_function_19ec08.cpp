#pragma force_active on
struct BitField {
    unsigned int : 6;
    unsigned int b : 1;
    unsigned int : 25;
};

extern "C" {
unsigned int fn_27_19EC08(void *obj) {
    BitField *bf = (BitField *)((char *)obj + 8);
    return bf->b;
}
}
