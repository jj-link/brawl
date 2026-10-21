#pragma force_active on

struct Input {
    unsigned char padding[0x24];
    int value;
};

struct Output {
    int scaled;
    int value;
};

extern "C" void fn_802DBF54(Input* input, void* unused, Output* output) {
    int v = input->value;
    output->value = v;
    output->scaled = v << 3;
}
