#pragma force_active on
extern "C" {
void fn_96_12C6C(short* dst, const short* src);
void fn_96_13310(short* dst, const short* src);
void fn_96_13278(unsigned char* object, short* source, void* argument);
void fn_96_13190(unsigned char* object, const short* source, void* arg);
void fn_96_130A8(unsigned char* self, const short* src, void* arg);
void fn_96_12FC0(void* object, const short* source, void* argument);
void fn_96_12ED8(unsigned char* self, short* source, void* arg);
void fn_96_12E28(void* object, const short* index, void* argument);
void fn_96_12D78(void* object, short* source, void* argument);
void fn_96_12CC8(void* object, short* source, void* argument);
}

extern "C" void fn_96_12A30(unsigned char* object, void* argument, const short* index) {
    short operation;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;

    fn_96_12C6C(&operation, &value);
    fn_96_13310(&first, &operation);
    fn_96_13278(object + 0x208, &first, argument);
    fn_96_13310(&second, &operation);
    fn_96_13190(object + 0x1CC, &second, argument);
    fn_96_13310(&third, &operation);
    fn_96_130A8(object + 0x180, &third, argument);
    fn_96_13310(&fourth, &operation);
    fn_96_12FC0(object + 0x138, &fourth, argument);
    fn_96_13310(&fifth, &operation);
    fn_96_12ED8(object + 0xF0, &fifth, argument);
    fn_96_13310(&sixth, &operation);
    fn_96_12E28(object + 0x98, &sixth, argument);
    fn_96_13310(&seventh, &operation);
    fn_96_12D78(object + 0x64, &seventh, argument);
    fn_96_13310(&eighth, &operation);
    fn_96_12CC8(object + 8, &eighth, argument);
}