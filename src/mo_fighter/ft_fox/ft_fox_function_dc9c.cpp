#pragma force_active on
extern "C" {
void fn_97_DED8(short* dst, const short* src);
void fn_97_E624(short* dst, const short* src);
void fn_97_E58C(void* object, const short* operation, void* argument);
void fn_97_E4A4(void* object, const short* operation, void* argument);
void fn_97_E3BC(void* object, const short* operation, void* argument);
void fn_97_E2D4(void* object, const short* operation, void* argument);
void fn_97_E1EC(void* object, short* operation, void* argument);
void fn_97_E104(void* object, const short* operation, void* argument);
void fn_97_E01C(void* object, const short* operation, void* argument);
void fn_97_DF34(void* object, const short* operation, void* argument);
}

extern "C" void fn_97_DC9C(unsigned char* object, void* argument, const short* index) {
    short operation;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;

    fn_97_DED8(&operation, &value);
    fn_97_E624(&first, &operation);
    fn_97_E58C(object + 0x208, &first, argument);
    fn_97_E624(&second, &operation);
    fn_97_E4A4(object + 0x1CC, &second, argument);
    fn_97_E624(&third, &operation);
    fn_97_E3BC(object + 0x180, &third, argument);
    fn_97_E624(&fourth, &operation);
    fn_97_E2D4(object + 0x138, &fourth, argument);
    fn_97_E624(&fifth, &operation);
    fn_97_E1EC(object + 0xF0, &fifth, argument);
    fn_97_E624(&sixth, &operation);
    fn_97_E104(object + 0x98, &sixth, argument);
    fn_97_E624(&seventh, &operation);
    fn_97_E01C(object + 0x64, &seventh, argument);
    fn_97_E624(&eighth, &operation);
    fn_97_DF34(object + 8, &eighth, argument);
}