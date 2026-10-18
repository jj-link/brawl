#pragma force_active on
class MuMsg {
public:
    void printf(unsigned long id, const char* fmt, ...);
};

struct SelfObj {
    char pad[0x48];
    MuMsg* msg;
};

extern "C" const char lbl_3_data_E80[8];

extern "C" void fn_3_EE78(SelfObj* self)
{
    self->msg->printf(0, lbl_3_data_E80);
}
