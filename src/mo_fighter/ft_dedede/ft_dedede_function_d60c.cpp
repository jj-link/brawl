namespace {
typedef unsigned char Byte;
struct DededeEventMask { short value; };
}
extern "C" {
void fn_117_D848(DededeEventMask*, const short*);
void fn_117_DF94(DededeEventMask*, const DededeEventMask*);
void fn_117_DEFC(void*, DededeEventMask*, void*);
void fn_117_DE14(void*, DededeEventMask*, void*);
void fn_117_DD2C(void*, DededeEventMask*, void*);
void fn_117_DC44(void*, DededeEventMask*, void*);
void fn_117_DB5C(void*, DededeEventMask*, void*);
void fn_117_DA74(void*, DededeEventMask*, void*);
void fn_117_D98C(void*, DededeEventMask*, void*);
void fn_117_D8A4(void*, DededeEventMask*, void*);
}

// Pass an independent mask copy to each embedded event array, in dispatch order.
extern "C" void fn_117_D60C(Byte* object, void* event, const short* bits) {
    DededeEventMask mask;
    short value = *bits;
    DededeEventMask second, fourth, sixth, eighth;
    DededeEventMask seventh, fifth, third, first;
    fn_117_D848(&mask, &value);
    fn_117_DF94(&first, &mask);
    fn_117_DEFC(object + 0x208, &first, event);
    fn_117_DF94(&second, &mask);
    fn_117_DE14(object + 0x1CC, &second, event);
    fn_117_DF94(&third, &mask);
    fn_117_DD2C(object + 0x180, &third, event);
    fn_117_DF94(&fourth, &mask);
    fn_117_DC44(object + 0x138, &fourth, event);
    fn_117_DF94(&fifth, &mask);
    fn_117_DB5C(object + 0xF0, &fifth, event);
    fn_117_DF94(&sixth, &mask);
    fn_117_DA74(object + 0x98, &sixth, event);
    fn_117_DF94(&seventh, &mask);
    fn_117_D98C(object + 0x64, &seventh, event);
    fn_117_DF94(&eighth, &mask);
    fn_117_D8A4(object + 8, &eighth, event);
}
