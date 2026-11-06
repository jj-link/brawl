#pragma force_active on
struct PikminTraversalIndex { short value; };
extern "C" {
short* fn_113_1CFD8(short*, const short*);
void fn_113_1D4E4(PikminTraversalIndex*, const PikminTraversalIndex*);
void fn_113_1D44C(void*, const PikminTraversalIndex*, void*);
void fn_113_1D364(void*, const PikminTraversalIndex*, void*);
void fn_113_1D27C(void*, const PikminTraversalIndex*, void*);
void fn_113_1D194(void*, const PikminTraversalIndex*, void*);
void fn_113_1D0AC(void*, const PikminTraversalIndex*, void*);
void fn_113_1CFFC(void*, const PikminTraversalIndex*, void*);
}

extern "C" void fn_113_1CDE4(unsigned char* object, void* argument, const short* index) {
    PikminTraversalIndex operation;
    short value = *index;
    PikminTraversalIndex second, fourth, sixth, fifth, third, first;

    fn_113_1CFD8(&operation.value, &value);
    fn_113_1D4E4(&first, &operation);
    fn_113_1D44C(object + 0x110, &first, argument);
    fn_113_1D4E4(&second, &operation);
    fn_113_1D364(object + 0xF0, &second, argument);
    fn_113_1D4E4(&third, &operation);
    fn_113_1D27C(object + 0xA4, &third, argument);
    fn_113_1D4E4(&fourth, &operation);
    fn_113_1D194(object + 0x68, &fourth, argument);
    fn_113_1D4E4(&fifth, &operation);
    fn_113_1D0AC(object + 0x48, &fifth, argument);
    fn_113_1D4E4(&sixth, &operation);
    fn_113_1CFFC(object + 8, &sixth, argument);
}
