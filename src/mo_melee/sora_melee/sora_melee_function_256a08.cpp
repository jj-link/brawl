#pragma force_active on
#include <ip/ip_switch.h>
struct Flags { unsigned char high : 6; unsigned char middle : 1; unsigned char low : 1; };
struct Flags2 { unsigned char high : 1; unsigned char rest : 7; };
extern "C" {
extern unsigned int lbl_27_data_53050;
extern char lbl_27_data_53054[];
extern char lbl_27_data_53100[];
extern char lbl_27_bss_59E0[];
void fn_27_255808(void*, const void*);
void fn_8004B780(void*, void*);
void* fn_27_256A08(void* arg0) {
    unsigned char* obj = (unsigned char*)arg0;
    fn_27_255808(arg0, lbl_27_data_53054);
    *(char**)(obj + 0x3c) = lbl_27_data_53100;
    Flags* f = (Flags*)(obj + 0x11b);
    f->high = 0;
    f->middle = 1;
    f->low = 0;
    ((Flags2*)(obj + 0x11c))->high = 0;
    *(signed char*)(obj + 0x138) = -1;
    *(unsigned int*)(obj + 0x13c) = lbl_27_data_53050;
    *(unsigned int*)(obj + 0x140) = 0;
    *(unsigned int*)(obj + 0x144) = lbl_27_data_53050;
    *(unsigned int*)(obj + 0x148) = 0;
    *(unsigned int*)(obj + 0x14c) = lbl_27_data_53050;
    *(unsigned int*)(obj + 0x150) = 0;
    if (ipSwitch::getInstance() != 0) {
        if (ipSwitch::getInstance()->m_keyRecorder != 0) {
            fn_8004B780(ipSwitch::getInstance()->m_keyRecorder, lbl_27_bss_59E0);
        }
    }
    return arg0;
}
}
