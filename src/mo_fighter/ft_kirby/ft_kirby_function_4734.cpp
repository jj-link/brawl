#pragma force_active on
extern "C" void fn_27_711E4(void* a, short b, void* c);
extern "C" void* fn_27_1AB96C(void* o, unsigned char c);

extern "C" void* fn_96_4734(char* obj, short eventId) {
    fn_27_711E4(obj, eventId, obj + 0x24);
    fn_27_1AB96C(obj + 0x24, 0);
    return obj;
}
