#pragma force_active on
extern "C" {
short* fn_92_C124(short*, const short*);
void fn_92_C870(short*, const short*);
void fn_92_C7D8(void*, const short*, void*);
void fn_92_C6F0(void*, const short*, void*);
void fn_92_C608(void*, const short*, void*);
void fn_92_C520(void*, const short*, void*);
void fn_92_C438(void*, const short*, void*);
void fn_92_C350(void*, const short*, void*);
void fn_92_C268(void*, const short*, void*);
void fn_92_C180(void*, const short*, void*);
}

extern "C" void fn_92_BEE8(unsigned char* object, void* argument, const short* index) {
    short operation;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;

    fn_92_C124(&operation, &value);
    fn_92_C870(&first, &operation);
    fn_92_C7D8(object + 0x208, &first, argument);
    fn_92_C870(&second, &operation);
    fn_92_C6F0(object + 0x1CC, &second, argument);
    fn_92_C870(&third, &operation);
    fn_92_C608(object + 0x180, &third, argument);
    fn_92_C870(&fourth, &operation);
    fn_92_C520(object + 0x138, &fourth, argument);
    fn_92_C870(&fifth, &operation);
    fn_92_C438(object + 0xF0, &fifth, argument);
    fn_92_C870(&sixth, &operation);
    fn_92_C350(object + 0x98, &sixth, argument);
    fn_92_C870(&seventh, &operation);
    fn_92_C268(object + 0x64, &seventh, argument);
    fn_92_C870(&eighth, &operation);
    fn_92_C180(object + 8, &eighth, argument);
}
