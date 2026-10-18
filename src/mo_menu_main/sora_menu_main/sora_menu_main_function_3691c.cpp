#pragma force_active on
class MuMsg {
public:
    void printf(unsigned long, const char*, ...);
};

extern "C" char lbl_2_data_4608[];

extern "C" void fn_2_3691C(char* self)
{
    MuMsg* msg = *(MuMsg**)(self + 0x48);
    msg->printf(0, lbl_2_data_4608);
}
