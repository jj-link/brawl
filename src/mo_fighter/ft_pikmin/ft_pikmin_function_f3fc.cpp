#pragma force_active on
struct PikminTraversalIndex { short value; };
extern "C" {
short* fn_113_F638(short*, const short*);
void fn_113_FD84(PikminTraversalIndex*, const PikminTraversalIndex*);
void fn_113_FCEC(void*, const PikminTraversalIndex*, void*);
void fn_113_FC04(void*, const PikminTraversalIndex*, void*);
void fn_113_FB1C(void*, const PikminTraversalIndex*, void*);
void fn_113_FA34(void*, const PikminTraversalIndex*, void*);
void fn_113_F94C(void*, const PikminTraversalIndex*, void*);
void fn_113_F864(void*, const PikminTraversalIndex*, void*);
void fn_113_F77C(void*, const PikminTraversalIndex*, void*);
void fn_113_F694(void*, const PikminTraversalIndex*, void*);
}
extern "C" void fn_113_F3FC(unsigned char* object, void* argument, const short* index) {
    PikminTraversalIndex operation;
    short value = *index;
    PikminTraversalIndex second, fourth, sixth, eighth;
    PikminTraversalIndex seventh, fifth, third, first;
    fn_113_F638(&operation.value, &value);
    fn_113_FD84(&first, &operation);
    fn_113_FCEC(object + 0x208, &first, argument);
    fn_113_FD84(&second, &operation);
    fn_113_FC04(object + 0x1cc, &second, argument);
    fn_113_FD84(&third, &operation);
    fn_113_FB1C(object + 0x180, &third, argument);
    fn_113_FD84(&fourth, &operation);
    fn_113_FA34(object + 0x138, &fourth, argument);
    fn_113_FD84(&fifth, &operation);
    fn_113_F94C(object + 0xf0, &fifth, argument);
    fn_113_FD84(&sixth, &operation);
    fn_113_F864(object + 0x98, &sixth, argument);
    fn_113_FD84(&seventh, &operation);
    fn_113_F77C(object + 0x64, &seventh, argument);
    fn_113_FD84(&eighth, &operation);
    fn_113_F694(object + 8, &eighth, argument);
}