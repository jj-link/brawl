#pragma force_active on
namespace {
typedef unsigned char Byte;
struct SnakeEventMask {
    short value;
};
}

extern "C" {
void fn_122_133D8(SnakeEventMask*, const short*);
void fn_122_13B24(SnakeEventMask*, const SnakeEventMask*);
void fn_122_13A8C(void*, SnakeEventMask*, void*);
void fn_122_139A4(void*, SnakeEventMask*, void*);
void fn_122_138BC(void*, SnakeEventMask*, void*);
void fn_122_137D4(void*, SnakeEventMask*, void*);
void fn_122_136EC(void*, SnakeEventMask*, void*);
void fn_122_13604(void*, SnakeEventMask*, void*);
void fn_122_1351C(void*, SnakeEventMask*, void*);
void fn_122_13434(void*, SnakeEventMask*, void*);
}

extern "C" void fn_122_1319C(Byte* object, void* argument, const short* index) {
    SnakeEventMask operation;
    short value = *index;
    SnakeEventMask second, fourth, sixth, eighth;
    SnakeEventMask seventh, fifth, third, first;

    fn_122_133D8(&operation, &value);
    fn_122_13B24(&first, &operation);
    fn_122_13A8C(object + 0x208, &first, argument);
    fn_122_13B24(&second, &operation);
    fn_122_139A4(object + 0x1CC, &second, argument);
    fn_122_13B24(&third, &operation);
    fn_122_138BC(object + 0x180, &third, argument);
    fn_122_13B24(&fourth, &operation);
    fn_122_137D4(object + 0x138, &fourth, argument);
    fn_122_13B24(&fifth, &operation);
    fn_122_136EC(object + 0xF0, &fifth, argument);
    fn_122_13B24(&sixth, &operation);
    fn_122_13604(object + 0x98, &sixth, argument);
    fn_122_13B24(&seventh, &operation);
    fn_122_1351C(object + 0x64, &seventh, argument);
    fn_122_13B24(&eighth, &operation);
    fn_122_13434(object + 8, &eighth, argument);
}
