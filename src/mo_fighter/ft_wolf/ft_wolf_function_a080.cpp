#pragma force_active on
extern "C" {
void fn_27_12DCA8(void* p);

void fn_125_A080(void* p) {
    fn_27_12DCA8(p);
    unsigned char* b = (unsigned char*)p;
    b[0x1CC89] = 0;
    b[0x1CC88] = 0;
}
}
