#pragma force_active on
namespace {
struct IceFlags {
    unsigned char pad[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    unsigned char disabled;
};
}

extern "C" {
void fn_105_1C360(void* object, void* arg);
short* fn_105_1C448(short* destination, const short* source);
void fn_105_1C440(void* object, short* data, void* arg);
}

extern "C" void fn_105_1C3B0(unsigned char* object, const short* source, void* arg) {
    IceFlags* p = reinterpret_cast<IceFlags*>(object + 0xC);
    if ((source[0] & 1) != 0) {
        bool enabled = p->enabled;
        if (enabled == true && p->disabled == 0) {
            fn_105_1C360(p, arg);
        }
    }

    short local[4];
    fn_105_1C448(local, source);
    fn_105_1C440(object + 4, local, arg);
}
