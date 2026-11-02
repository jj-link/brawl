#pragma force_active on
extern "C" {
void fn_123_CD2C(short*, const short*);
void fn_123_ED34(short*, const short*);
void fn_123_EC9C(void*, const short*, void*);
void fn_123_E898(void*, const short*, void*);
void fn_123_E494(void*, const short*, void*);
void fn_123_E090(void*, const short*, void*);
void fn_123_DC8C(void*, const short*, void*);
void fn_123_D89C(void*, const short*, void*);
void fn_123_D4A0(void*, const short*, void*);
void fn_123_D0A4(void*, const short*, void*);
}

extern "C" void fn_123_C7EC(void* object, void* argument, const short* index) {
    unsigned char* self = static_cast<unsigned char*>(object);
    short converted;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;

    fn_123_CD2C(&converted, &value);
    fn_123_ED34(&first, &converted);
    fn_123_EC9C(self + 0x208, &first, argument);
    fn_123_ED34(&second, &converted);
    fn_123_E898(self + 0x1CC, &second, argument);
    fn_123_ED34(&third, &converted);
    fn_123_E494(self + 0x180, &third, argument);
    fn_123_ED34(&fourth, &converted);
    fn_123_E090(self + 0x138, &fourth, argument);
    fn_123_ED34(&fifth, &converted);
    fn_123_DC8C(self + 0xF0, &fifth, argument);
    fn_123_ED34(&sixth, &converted);
    fn_123_D89C(self + 0x98, &sixth, argument);
    fn_123_ED34(&seventh, &converted);
    fn_123_D4A0(self + 0x64, &seventh, argument);
    fn_123_ED34(&eighth, &converted);
    fn_123_D0A4(self + 8, &eighth, argument);
}
