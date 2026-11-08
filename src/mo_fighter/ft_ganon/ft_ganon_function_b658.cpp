#pragma force_active on
extern "C" {
short* fn_109_B894(short*, const short*);
void fn_109_BFA8(short*, const short*);
void fn_109_BF10(void*, const short*, void*);
void fn_109_BE28(void*, const short*, void*);
void fn_109_BD40(void*, const short*, void*);
void fn_109_BC58(void*, const short*, void*);
void fn_109_BB70(void*, const short*, void*);
void fn_109_BA88(void*, const short*, void*);
void fn_109_B9D8(void*, const short*, void*);
void fn_109_B8F0(void*, const short*, void*);
}
extern "C" void fn_109_B658(unsigned char* object, void* argument, const short* index) {
    short operation;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;
    fn_109_B894(&operation, &value);
    fn_109_BFA8(&first, &operation);
    fn_109_BF10(object + 0x208, &first, argument);
    fn_109_BFA8(&second, &operation);
    fn_109_BE28(object + 0x1cc, &second, argument);
    fn_109_BFA8(&third, &operation);
    fn_109_BD40(object + 0x180, &third, argument);
    fn_109_BFA8(&fourth, &operation);
    fn_109_BC58(object + 0x138, &fourth, argument);
    fn_109_BFA8(&fifth, &operation);
    fn_109_BB70(object + 0xf0, &fifth, argument);
    fn_109_BFA8(&sixth, &operation);
    fn_109_BA88(object + 0x98, &sixth, argument);
    fn_109_BFA8(&seventh, &operation);
    fn_109_B9D8(object + 0x64, &seventh, argument);
    fn_109_BFA8(&eighth, &operation);
    fn_109_B8F0(object + 8, &eighth, argument);
}