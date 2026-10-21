#pragma force_active on
extern "C" void fn_801F0530();
extern "C" void fn_801F08D8(unsigned short);

extern "C" void fn_80023C70(int* arg0) {
    arg0[8] = 2;
    fn_801F08D8(0xFFE0);
    fn_801F0530();
}
