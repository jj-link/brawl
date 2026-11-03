#pragma force_active on
extern "C" {
void fn_124_A9C4(short*, const short*);
void fn_124_B110(short*, short*);
void fn_124_B078(unsigned char*, short*, int);
void fn_124_AF90(unsigned char*, short*, int);
void fn_124_AEA8(unsigned char*, short*, int);
void fn_124_ADC0(unsigned char*, short*, int);
void fn_124_ACD8(unsigned char*, short*, int);
void fn_124_ABF0(unsigned char*, short*, int);
void fn_124_AB08(unsigned char*, short*, int);
void fn_124_AA20(unsigned char*, short*, int);
}

extern "C" void fn_124_A788(unsigned char* object, int argument, const short* index) {
    short operation;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;
    fn_124_A9C4(&operation, &value);
    fn_124_B110(&first, &operation);
    fn_124_B078(object + 0x208, &first, argument);
    fn_124_B110(&second, &operation);
    fn_124_AF90(object + 0x1CC, &second, argument);
    fn_124_B110(&third, &operation);
    fn_124_AEA8(object + 0x180, &third, argument);
    fn_124_B110(&fourth, &operation);
    fn_124_ADC0(object + 0x138, &fourth, argument);
    fn_124_B110(&fifth, &operation);
    fn_124_ACD8(object + 0xF0, &fifth, argument);
    fn_124_B110(&sixth, &operation);
    fn_124_ABF0(object + 0x98, &sixth, argument);
    fn_124_B110(&seventh, &operation);
    fn_124_AB08(object + 0x64, &seventh, argument);
    fn_124_B110(&eighth, &operation);
    fn_124_AA20(object + 8, &eighth, argument);
}