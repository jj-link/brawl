#pragma force_active on
extern "C" {
void fn_102_B73C(short*, const short*);
void fn_102_BE88(short*, const short*);
void fn_102_BDF0(void*, const short*, void*);
void fn_102_BD08(void*, const short*, void*);
void fn_102_BC20(void*, const short*, void*);
void fn_102_BB38(void*, const short*, void*);
void fn_102_BA50(void*, const short*, void*);
void fn_102_B968(void*, const short*, void*);
void fn_102_B880(void*, const short*, void*);
void fn_102_B798(void*, const short*, void*);
}
extern "C" void fn_102_B500(unsigned char* object, void* argument, const short* index) {
    short operation;
    short value = *index;
    short second, fourth, sixth, eighth;
    short seventh, fifth, third, first;
    fn_102_B73C(&operation, &value);
    fn_102_BE88(&first, &operation);
    fn_102_BDF0(object + 0x208, &first, argument);
    fn_102_BE88(&second, &operation);
    fn_102_BD08(object + 0x1CC, &second, argument);
    fn_102_BE88(&third, &operation);
    fn_102_BC20(object + 0x180, &third, argument);
    fn_102_BE88(&fourth, &operation);
    fn_102_BB38(object + 0x138, &fourth, argument);
    fn_102_BE88(&fifth, &operation);
    fn_102_BA50(object + 0xF0, &fifth, argument);
    fn_102_BE88(&sixth, &operation);
    fn_102_B968(object + 0x98, &sixth, argument);
    fn_102_BE88(&seventh, &operation);
    fn_102_B880(object + 0x64, &seventh, argument);
    fn_102_BE88(&eighth, &operation);
    fn_102_B798(object + 8, &eighth, argument);
}