#pragma force_active on
typedef short s16;

extern "C" {
s16* fn_119_BDE0(s16* destination, const s16* source);
void fn_119_C52C(s16* dst, const s16* src);
void fn_119_C494(void* object, const s16* operation, void* argument);
void fn_119_C3AC(void* object, const s16* operation, void* argument);
void fn_119_C2C4(void* object, const s16* source, void* argument);
void fn_119_C1DC(void* object, const s16* operation, void* argument);
void fn_119_C0F4(void* object, const s16* index, void* argument);
void fn_119_C00C(unsigned char* self, const s16* src, void* arg);
void fn_119_BF24(unsigned char* self, s16* p, void* arg);
void fn_119_BE3C(unsigned char* self, s16* idx, void* arg);
}

extern "C" void fn_119_BBA4(void* object, void* argument, const s16* index) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    s16 operation;
    s16 value = *index;
    s16 second;
    s16 fourth;
    s16 sixth;
    s16 eighth;
    s16 seventh;
    s16 fifth;
    s16 third;
    s16 first;

    fn_119_BDE0(&operation, &value);
    fn_119_C52C(&first, &operation);
    fn_119_C494(composite + 0x208, &first, argument);
    fn_119_C52C(&second, &operation);
    fn_119_C3AC(composite + 0x1CC, &second, argument);
    fn_119_C52C(&third, &operation);
    fn_119_C2C4(composite + 0x180, &third, argument);
    fn_119_C52C(&fourth, &operation);
    fn_119_C1DC(composite + 0x138, &fourth, argument);
    fn_119_C52C(&fifth, &operation);
    fn_119_C0F4(composite + 0xF0, &fifth, argument);
    fn_119_C52C(&sixth, &operation);
    fn_119_C00C(composite + 0x98, &sixth, argument);
    fn_119_C52C(&seventh, &operation);
    fn_119_BF24(composite + 0x64, &seventh, argument);
    fn_119_C52C(&eighth, &operation);
    fn_119_BE3C(composite + 0x8, &eighth, argument);
}
