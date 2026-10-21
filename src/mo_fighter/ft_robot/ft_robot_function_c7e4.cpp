#pragma force_active on
extern "C" void fn_120_C794(unsigned char* obj, void* arg);
extern "C" short* fn_120_CC1C(short* destination, const short* source);
extern "C" int fn_120_C874(unsigned char* obj, short* data, void* arg);

struct RobotFlags {
    unsigned char enabled : 1;
    unsigned char rest : 7;
};

extern "C" void fn_120_C7E4(unsigned char* obj, short* flag, void* arg) {
    unsigned char* p = obj + 0xC;
    if ((flag[0] & 1) != 0) {
        RobotFlags* f = reinterpret_cast<RobotFlags*>(p + 5);
        bool on = f->enabled;
        if (on == true && p[6] == 0) {
            fn_120_C794(p, arg);
        }
    }
    short tmp[4];
    fn_120_CC1C(tmp, flag);
    fn_120_C874(obj + 4, tmp, arg);
}
