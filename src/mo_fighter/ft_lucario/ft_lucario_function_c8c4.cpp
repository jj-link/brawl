#pragma force_active on
extern "C" {
void fn_118_CB00(short* dst, const short* src);
void fn_118_D24C(short* dst, short* src);
void fn_118_D1B4(void* self, short* src, void* c);
void fn_118_D0CC(unsigned char* self, short* src, void* arg);
void fn_118_CFE4(unsigned char* self, short* src, void* arg);
void fn_118_CEFC(unsigned char* self, short* src, void* arg);
void fn_118_CE14(unsigned char* self, short* flag, void* arg);
void fn_118_CD2C(unsigned char* self, short* flag, void* arg);
void fn_118_CC44(unsigned char* self, short* flag, void* arg);
void fn_118_CB5C(unsigned char* self, short* src, int arg);
}

extern "C" void fn_118_C8C4(void* object, void* argument, const short* index) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    short operation;
    short value = *index;
    short second;
    short fourth;
    short sixth;
    short eighth;
    short seventh;
    short fifth;
    short third;
    short first;

    fn_118_CB00(&operation, &value);
    fn_118_D24C(&first, &operation);
    fn_118_D1B4(composite + 0x208, &first, argument);
    fn_118_D24C(&second, &operation);
    fn_118_D0CC(composite + 0x1CC, &second, argument);
    fn_118_D24C(&third, &operation);
    fn_118_CFE4(composite + 0x180, &third, argument);
    fn_118_D24C(&fourth, &operation);
    fn_118_CEFC(composite + 0x138, &fourth, argument);
    fn_118_D24C(&fifth, &operation);
    fn_118_CE14(composite + 0xF0, &fifth, argument);
    fn_118_D24C(&sixth, &operation);
    fn_118_CD2C(composite + 0x98, &sixth, argument);
    fn_118_D24C(&seventh, &operation);
    fn_118_CC44(composite + 0x64, &seventh, argument);
    fn_118_D24C(&eighth, &operation);
    fn_118_CB5C(composite + 8, &eighth, (int)(unsigned long)argument);
}