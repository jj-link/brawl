#pragma force_active on
extern "C" {
void fn_91_D36C(short*, const short*);
void fn_91_DAB8(short*, const short*);
void fn_91_DA20(unsigned char*, short*, void*);
void fn_91_D938(unsigned char*, const short*, void*);
void fn_91_D850(unsigned char*, const short*, void*);
void fn_91_D768(unsigned char*, short*, void*);
void fn_91_D680(unsigned char*, short*, void*);
void fn_91_D598(void*, const short*, void*);
void fn_91_D4B0(void*, const short*, void*);
void fn_91_D3C8(void*, const short*, void*);
}

extern "C" void fn_91_D130(unsigned char* object, void* argument, const short* index) {
    short operation;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;

    fn_91_D36C(&operation, &value);
    fn_91_DAB8(&first, &operation);
    fn_91_DA20(object + 0x208, &first, argument);
    fn_91_DAB8(&second, &operation);
    fn_91_D938(object + 0x1CC, &second, argument);
    fn_91_DAB8(&third, &operation);
    fn_91_D850(object + 0x180, &third, argument);
    fn_91_DAB8(&fourth, &operation);
    fn_91_D768(object + 0x138, &fourth, argument);
    fn_91_DAB8(&fifth, &operation);
    fn_91_D680(object + 0xF0, &fifth, argument);
    fn_91_DAB8(&sixth, &operation);
    fn_91_D598(object + 0x98, &sixth, argument);
    fn_91_DAB8(&seventh, &operation);
    fn_91_D4B0(object + 0x64, &seventh, argument);
    fn_91_DAB8(&eighth, &operation);
    fn_91_D3C8(object + 8, &eighth, argument);
}
