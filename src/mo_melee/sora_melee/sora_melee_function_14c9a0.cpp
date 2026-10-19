#pragma force_active on
extern "C" float fn_27_195370(int);

struct Input {
    char pad[8];
    float value1;
    float value2;
    char pad2[4];
    int argument;
};

extern "C" float fn_27_14C9A0(Input* input) {
    float product = input->value1 * input->value2;
    return product * fn_27_195370(input->argument);
}
