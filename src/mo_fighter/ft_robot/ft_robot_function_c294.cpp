#pragma force_active on
extern "C" {
void fn_120_C4D0(short* dst, const short* src);
short* fn_120_CC1C(short* dst, const short* src);
void fn_120_CB84(unsigned char* object, const short* operation, void* argument);
void fn_120_CA9C(unsigned char* object, const short* operation, void* argument);
void fn_120_C9B4(unsigned char* object, const short* operation, void* argument);
void fn_120_C8CC(unsigned char* object, const short* operation, void* argument);
void fn_120_C7E4(unsigned char* object, const short* operation, void* argument);
void fn_120_C6FC(unsigned char* object, const short* operation, void* argument);
void fn_120_C614(unsigned char* object, const short* operation, void* argument);
void fn_120_C52C(unsigned char* object, const short* operation, void* argument);
}

extern "C" void fn_120_C294(unsigned char* object, void* argument, const short* index) {
    short operation;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;

    fn_120_C4D0(&operation, &value);
    fn_120_CC1C(&first, &operation);
    fn_120_CB84(object + 0x208, &first, argument);
    fn_120_CC1C(&second, &operation);
    fn_120_CA9C(object + 0x1CC, &second, argument);
    fn_120_CC1C(&third, &operation);
    fn_120_C9B4(object + 0x180, &third, argument);
    fn_120_CC1C(&fourth, &operation);
    fn_120_C8CC(object + 0x138, &fourth, argument);
    fn_120_CC1C(&fifth, &operation);
    fn_120_C7E4(object + 0xF0, &fifth, argument);
    fn_120_CC1C(&sixth, &operation);
    fn_120_C6FC(object + 0x98, &sixth, argument);
    fn_120_CC1C(&seventh, &operation);
    fn_120_C614(object + 0x64, &seventh, argument);
    fn_120_CC1C(&eighth, &operation);
    fn_120_C52C(object + 8, &eighth, argument);
}
