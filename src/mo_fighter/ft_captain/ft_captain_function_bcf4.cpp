#pragma force_active on
class soModuleAccesser;

extern "C" {
void fn_100_BF34(short* dst, const short* src);
void fn_100_C648(short* dst, const short* src);
void fn_100_C5B0(unsigned char* self, const short* src, soModuleAccesser* accesser);
void fn_100_C4C8(unsigned char* self, const short* flags, soModuleAccesser* accesser);
void fn_100_C3E0(unsigned char* object, const short* flags, soModuleAccesser* accesser);
void fn_100_C2F8(unsigned char* object, short* source, soModuleAccesser* accesser);
void fn_100_C210(unsigned char* self, short* flags, soModuleAccesser* accesser);
void fn_100_C128(unsigned char* self, short* arg, void* p);
void fn_100_C078(unsigned char* object, short* source, soModuleAccesser* accesser);
void fn_100_BF90(unsigned char* object, const short* flags, soModuleAccesser* accesser);
}

extern "C" void fn_100_BCF4(unsigned char* object, soModuleAccesser* accesser, const short* index) {
    short operation;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;

    fn_100_BF34(&operation, &value);
    fn_100_C648(&first, &operation);
    fn_100_C5B0(object + 0x208, &first, accesser);
    fn_100_C648(&second, &operation);
    fn_100_C4C8(object + 0x1CC, &second, accesser);
    fn_100_C648(&third, &operation);
    fn_100_C3E0(object + 0x180, &third, accesser);
    fn_100_C648(&fourth, &operation);
    fn_100_C2F8(object + 0x138, &fourth, accesser);
    fn_100_C648(&fifth, &operation);
    fn_100_C210(object + 0xF0, &fifth, accesser);
    fn_100_C648(&sixth, &operation);
    fn_100_C128(object + 0x98, &sixth, accesser);
    fn_100_C648(&seventh, &operation);
    fn_100_C078(object + 0x64, &seventh, accesser);
    fn_100_C648(&eighth, &operation);
    fn_100_BF90(object + 8, &eighth, accesser);
}