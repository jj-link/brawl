#pragma force_active on
extern "C" {
short* fn_103_C888(short* destination, const short* source);
short* fn_103_CF2C(short* destination, const short* source);
int fn_103_CE94(void*, const short*, void*);
int fn_103_CDAC(void*, const short*, void*);
int fn_103_CCC4(void*, const short*, void*);
int fn_103_CBDC(void*, const short*, void*);
int fn_103_CAF4(void*, const short*, void*);
int fn_103_CA44(void*, const short*, void*);
int fn_103_C994(void*, const short*, void*);
int fn_103_C8AC(void*, const short*, void*);
}

extern "C" void fn_103_C64C(unsigned char* object, void* argument, const short* index) {
    short operation;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;

    fn_103_C888(&operation, &value);
    fn_103_CF2C(&first, &operation);
    fn_103_CE94(object + 0x208, &first, argument);
    fn_103_CF2C(&second, &operation);
    fn_103_CDAC(object + 0x1CC, &second, argument);
    fn_103_CF2C(&third, &operation);
    fn_103_CCC4(object + 0x180, &third, argument);
    fn_103_CF2C(&fourth, &operation);
    fn_103_CBDC(object + 0x138, &fourth, argument);
    fn_103_CF2C(&fifth, &operation);
    fn_103_CAF4(object + 0xF0, &fifth, argument);
    fn_103_CF2C(&sixth, &operation);
    fn_103_CA44(object + 0x98, &sixth, argument);
    fn_103_CF2C(&seventh, &operation);
    fn_103_C994(object + 0x64, &seventh, argument);
    fn_103_CF2C(&eighth, &operation);
    fn_103_C8AC(object + 8, &eighth, argument);
}
