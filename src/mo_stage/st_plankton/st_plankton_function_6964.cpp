#pragma force_active on
struct Plankton {
    int a;
    int b;
    int rest : 2;
    int value : 2;
    int rest2 : 28;
};

extern "C" void fn_74_6964(void* p, unsigned int v) {
    struct Plankton* self = (struct Plankton*)p;
    self->value = v;
}