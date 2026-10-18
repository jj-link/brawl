#pragma force_active on
extern "C" char lbl_118_data_230C[];

extern "C" void fn_118_6C2C(void* self, unsigned char value) {
    *(char**)self = lbl_118_data_230C;
    *((unsigned char*)self + 4) = value;
}
