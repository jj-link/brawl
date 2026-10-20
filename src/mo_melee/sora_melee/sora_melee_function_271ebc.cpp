#pragma force_active on
struct Input {
    int padding[6];
    int kind;
};
extern "C" void fn_27_2720E8(void*, const Input*);
extern "C" void fn_27_271EBC(unsigned char* self, const Input* input)
{
    if (input->kind == 0)
        fn_27_2720E8(self + 4, input);
    if (input->kind == 1)
        fn_27_2720E8(self + 0x20, input);
}
