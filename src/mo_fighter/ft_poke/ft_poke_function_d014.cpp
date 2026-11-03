#pragma force_active on
extern "C" {
void fn_116_D250(short*, const short*);
void fn_116_D99C(short*, const short*);
void fn_116_D904(void*, const short*, void*);
void fn_116_D81C(void*, const short*, void*);
void fn_116_D734(void*, const short*, void*);
void fn_116_D64C(void*, const short*, void*);
void fn_116_D564(void*, const short*, void*);
void fn_116_D47C(void*, const short*, void*);
void fn_116_D394(void*, const short*, void*);
void fn_116_D2AC(void*, const short*, void*);
}
extern "C" void fn_116_D014(unsigned char* object, void* argument, const short* index) {
    short operation;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;
    fn_116_D250(&operation, &value);
    fn_116_D99C(&first, &operation);
    fn_116_D904(object + 0x208, &first, argument);
    fn_116_D99C(&second, &operation);
    fn_116_D81C(object + 0x1CC, &second, argument);
    fn_116_D99C(&third, &operation);
    fn_116_D734(object + 0x180, &third, argument);
    fn_116_D99C(&fourth, &operation);
    fn_116_D64C(object + 0x138, &fourth, argument);
    fn_116_D99C(&fifth, &operation);
    fn_116_D564(object + 0xF0, &fifth, argument);
    fn_116_D99C(&sixth, &operation);
    fn_116_D47C(object + 0x98, &sixth, argument);
    fn_116_D99C(&seventh, &operation);
    fn_116_D394(object + 0x64, &seventh, argument);
    fn_116_D99C(&eighth, &operation);
    fn_116_D2AC(object + 8, &eighth, argument);
}