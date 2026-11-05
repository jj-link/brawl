#pragma force_active on
extern "C" {
short* fn_94_E37C(short*, const short*);
short* fn_94_EAC8(short*, const short*);
void fn_94_EA30(void*, const short*, void*);
void fn_94_E948(void*, const short*, void*);
void fn_94_E860(void*, const short*, void*);
void fn_94_E778(void*, const short*, void*);
void fn_94_E690(void*, const short*, void*);
void fn_94_E5A8(void*, const short*, void*);
void fn_94_E4C0(void*, const short*, void*);
void fn_94_E3D8(void*, const short*, void*);
}
extern "C" void fn_94_E140(unsigned char* object, void* argument, const short* index) {
    short operation;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;
    fn_94_E37C(&operation, &value);
    fn_94_EAC8(&first, &operation);
    fn_94_EA30(object + 0x208, &first, argument);
    fn_94_EAC8(&second, &operation);
    fn_94_E948(object + 0x1CC, &second, argument);
    fn_94_EAC8(&third, &operation);
    fn_94_E860(object + 0x180, &third, argument);
    fn_94_EAC8(&fourth, &operation);
    fn_94_E778(object + 0x138, &fourth, argument);
    fn_94_EAC8(&fifth, &operation);
    fn_94_E690(object + 0xF0, &fifth, argument);
    fn_94_EAC8(&sixth, &operation);
    fn_94_E5A8(object + 0x98, &sixth, argument);
    fn_94_EAC8(&seventh, &operation);
    fn_94_E4C0(object + 0x64, &seventh, argument);
    fn_94_EAC8(&eighth, &operation);
    fn_94_E3D8(object + 8, &eighth, argument);
}