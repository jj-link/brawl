#pragma force_active on
extern "C" {
void fn_96_1DCD4(void* p);
void fn_27_12E7C8(void* p);
void fn_96_DDE4(void* p);

void fn_96_B0C4(void* fighter) {
    fn_96_1DCD4((char*)fighter + 0x1B72C);
    fn_27_12E7C8(fighter);
    fn_96_DDE4(fighter);
}
}
