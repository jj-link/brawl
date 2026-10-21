#pragma force_active on
class soModuleAccesser;

extern "C" {
void fn_100_C1C0(void*, soModuleAccesser*);
void fn_100_C648(short*, const short*);
void fn_100_C2A0(void*, short*, soModuleAccesser*);
}

struct CaptainSubState {
    unsigned char pad[5];
    unsigned char enabled : 1;
    unsigned char rest : 7;
    unsigned char suspended;
};

extern "C" void fn_100_C210(unsigned char* self, short* flags, soModuleAccesser* accesser) {
    CaptainSubState* sub = reinterpret_cast<CaptainSubState*>(self + 0xC);
    if ((flags[0] & 1) != 0) {
        bool on = sub->enabled;
        if (on == true && sub->suspended == 0) {
            fn_100_C1C0(sub, accesser);
        }
    }
    short local;
    fn_100_C648(&local, flags);
    fn_100_C2A0(self + 4, &local, accesser);
}
