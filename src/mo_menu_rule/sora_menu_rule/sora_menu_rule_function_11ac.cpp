#pragma force_active on
struct MuMsg {
    void printf(unsigned long, const char*, ...);
};

struct Owner {
    char pad[0x48];
    MuMsg* msg;
};

extern char lbl_18_data_5D0[];

extern "C" void fn_18_11AC(Owner* self) {
    self->msg->printf(0, lbl_18_data_5D0);
}
