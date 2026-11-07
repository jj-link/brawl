#pragma force_active on
extern "C" {
void fn_116_19D30(short*, const short*);
void fn_116_1A34C(short*, const short*);
void fn_116_1A2B4(void*, const short*, void*);
void fn_116_1A1E4(void*, const short*, void*);
void fn_116_1A114(void*, const short*, void*);
void fn_116_1A044(void*, const short*, void*);
void fn_116_19F74(void*, const short*, void*);
void fn_116_19EDC(void*, const short*, void*);
void fn_116_19E0C(void*, const short*, void*);
void fn_116_19D74(void*, const short*, void*);
}
extern "C" void fn_116_19AF4(unsigned char* object, void* argument, const short* index) {
    short operation;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;
    fn_116_19D30(&operation, &value);
    fn_116_1A34C(&first, &operation);
    fn_116_1A2B4(object + 0x208, &first, argument);
    fn_116_1A34C(&second, &operation);
    fn_116_1A1E4(object + 0x1CC, &second, argument);
    fn_116_1A34C(&third, &operation);
    fn_116_1A114(object + 0x180, &third, argument);
    fn_116_1A34C(&fourth, &operation);
    fn_116_1A044(object + 0x138, &fourth, argument);
    fn_116_1A34C(&fifth, &operation);
    fn_116_19F74(object + 0xF0, &fifth, argument);
    fn_116_1A34C(&sixth, &operation);
    fn_116_19EDC(object + 0x98, &sixth, argument);
    fn_116_1A34C(&seventh, &operation);
    fn_116_19E0C(object + 0x64, &seventh, argument);
    fn_116_1A34C(&eighth, &operation);
    fn_116_19D74(object + 8, &eighth, argument);
}