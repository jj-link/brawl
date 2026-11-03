#pragma force_active on
extern "C" {
void fn_121_E1FC(short* destination, const short* source);
void fn_121_E948(short* dest, const short* source);
void fn_121_E8B0(void* object, const short* operation, void* argument);
void fn_121_E7C8(void* object, const short* operation, void* argument);
void fn_121_E6E0(void* object, const short* operation, void* argument);
void fn_121_E5F8(void* object, const short* operation, void* argument);
void fn_121_E510(void* object, const short* operation, void* argument);
void fn_121_E428(void* object, const short* operation, void* argument);
void fn_121_E340(void* object, const short* operation, void* argument);
void fn_121_E258(void* object, const short* operation, void* argument);
}

extern "C" void fn_121_DFC0(void* object, void* argument, const short* index) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    short operation;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;

    fn_121_E1FC(&operation, &value);
    fn_121_E948(&first, &operation);
    fn_121_E8B0(composite + 0x208, &first, argument);
    fn_121_E948(&second, &operation);
    fn_121_E7C8(composite + 0x1CC, &second, argument);
    fn_121_E948(&third, &operation);
    fn_121_E6E0(composite + 0x180, &third, argument);
    fn_121_E948(&fourth, &operation);
    fn_121_E5F8(composite + 0x138, &fourth, argument);
    fn_121_E948(&fifth, &operation);
    fn_121_E510(composite + 0xF0, &fifth, argument);
    fn_121_E948(&sixth, &operation);
    fn_121_E428(composite + 0x98, &sixth, argument);
    fn_121_E948(&seventh, &operation);
    fn_121_E340(composite + 0x64, &seventh, argument);
    fn_121_E948(&eighth, &operation);
    fn_121_E258(composite + 8, &eighth, argument);
}