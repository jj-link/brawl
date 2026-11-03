#pragma force_active on
extern "C" {
short* fn_93_E200(short*, const short*);
short* fn_93_E94C(short*, const short*);
void fn_93_E8B4(void*, const short*, void*);
void fn_93_E7CC(void*, const short*, void*);
void fn_93_E6E4(void*, const short*, void*);
void fn_93_E5FC(void*, const short*, void*);
void fn_93_E514(void*, const short*, void*);
void fn_93_E42C(void*, const short*, void*);
void fn_93_E344(void*, const short*, void*);
void fn_93_E25C(void*, const short*, void*);
}

extern "C" void fn_93_DFC4(unsigned char* object, void* argument, const short* index) {
    short operation;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;
    fn_93_E200(&operation, &value);
    fn_93_E94C(&first, &operation);
    fn_93_E8B4(object + 0x208, &first, argument);
    fn_93_E94C(&second, &operation);
    fn_93_E7CC(object + 0x1CC, &second, argument);
    fn_93_E94C(&third, &operation);
    fn_93_E6E4(object + 0x180, &third, argument);
    fn_93_E94C(&fourth, &operation);
    fn_93_E5FC(object + 0x138, &fourth, argument);
    fn_93_E94C(&fifth, &operation);
    fn_93_E514(object + 0xF0, &fifth, argument);
    fn_93_E94C(&sixth, &operation);
    fn_93_E42C(object + 0x98, &sixth, argument);
    fn_93_E94C(&seventh, &operation);
    fn_93_E344(object + 0x64, &seventh, argument);
    fn_93_E94C(&eighth, &operation);
    fn_93_E25C(object + 8, &eighth, argument);
}