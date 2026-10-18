#pragma force_active on
struct MuMsg {
    static void printf(unsigned long id, const char* fmt, ...);
};

extern char lbl_10_data_DD8[8];

extern "C" {
void fn_10_1C85C(unsigned char* self)
{
    MuMsg::printf(*(unsigned long*)(self + 0x48), 0, lbl_10_data_DD8);
}
}
