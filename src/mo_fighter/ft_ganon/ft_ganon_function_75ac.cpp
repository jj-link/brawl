#pragma force_active on
extern "C" {
void fn_27_711E4(void*, short, void*);
void* fn_27_1AB96C(void* o, unsigned char c);

void* fn_109_75AC(char* p, short s) {
    fn_27_711E4(p, s, p + 0x24);
    fn_27_1AB96C(p + 0x24, 0);
    return p;
}
}
