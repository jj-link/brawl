#include <so/so_module_accesser.h>
#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_96_9EDC(void*, short);
void* fn_96_9E80(void*, short);
void* fn_96_9E24(void*, short);
void* fn_96_9DC8(void*, short);
void* fn_96_9D6C(void*, short);
void* fn_96_9CEC(void*, short);
void* fn_96_2874(void*, short);
void* fn_96_9BB8(void*, short);
void* fn_96_2814(void*, short);
void* fn_96_9A8C(void*, short);
void* fn_96_9998(void*, short);
void* fn_96_9900(void*, short);
void* fn_96_97AC(void*, short);
void* fn_96_60CC(void*, short);
void* fn_96_5FF4(void*, short);
void* fn_96_5A0C(void*, short);
void* fn_96_4894(void*, short);
void* fn_96_27B8(void*, short);
void* fn_96_46C0(void*, short);
void* fn_96_45D4(void*, short);
void* fn_96_44AC(void*, short);
void* fn_96_4440(void*, short);
void* fn_96_4380(void*, short);
void* fn_96_423C(void*, short);
void* fn_96_4184(void*, short);
void* fn_96_4128(void*, short);
void* fn_96_40CC(void*, short);
void* fn_96_4070(void*, short);
void* fn_96_3FFC(void*, short);
void* fn_96_3F18(void*, short);
void* fn_96_3E10(void*, short);
void* fn_96_3CE8(void*, short);
void* fn_96_3B84(void*, short);
void* fn_96_3A2C(void*, short);
void* fn_96_38E4(void*, short);
void* fn_96_37A8(void*, short);
void* fn_96_259C(void*, short);
void* fn_96_2530(void*, short);
void* fn_96_24BC(void*, short);
void* fn_96_3620(void*, short);
void* fn_96_3024(void*, short);
void* fn_96_2ED4(void*, short);
void* fn_96_2D70(void*, short);
void* fn_96_2460(void*, short);
void* fn_96_2C2C(void*, short);
}
extern "C" void* fn_96_9F38(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_96_9EDC(storage + 0x192D4, destroy);
        fn_96_9E80(storage + 0x19298, destroy);
        fn_96_9E24(storage + 0x19230, destroy);
        fn_96_9DC8(storage + 0x191E4, destroy);
        fn_96_9D6C(storage + 0x19090, destroy);
        fn_96_9CEC(storage + 0x18F30, destroy);
        fn_96_2874(storage + 0x18EE8, destroy);
        fn_96_9BB8(storage + 0x18E68, destroy);
        fn_96_2814(storage + 0x18E1C, destroy);
        fn_96_9A8C(storage + 0x18A3C, destroy);
        fn_96_9998(storage + 0x18A0C, destroy);
        fn_96_9900(storage + 0x18868, destroy);
        fn_96_97AC(storage + 0x5EF8, destroy);
        fn_96_60CC(storage + 0x5D14, destroy);
        fn_96_5FF4(storage + 0x5A0C, destroy);
        fn_96_5A0C(storage + 0x487C, destroy);
        fn_96_4894(storage + 0x4788, destroy);
        fn_96_27B8(storage + 0x4754, destroy);
        fn_96_46C0(storage + 0x46E0, destroy);
        fn_96_45D4(storage + 0x3FBC, destroy);
        fn_96_44AC(storage + 0x3F8C, destroy);
        fn_96_4440(storage + 0x3D8C, destroy);
        fn_96_4380(storage + 0x3D1C, destroy);
        fn_96_423C(storage + 0x3C84, destroy);
        fn_96_4184(storage + 0x3C4C, destroy);
        fn_96_4128(storage + 0x3C28, destroy);
        fn_96_40CC(storage + 0x3BF4, destroy);
        fn_96_4070(storage + 0x3B90, destroy);
        fn_96_3FFC(storage + 0x39E0, destroy);
        fn_96_3F18(storage + 0x3788, destroy);
        fn_96_3E10(storage + 0x3528, destroy);
        fn_96_3CE8(storage + 0x2DAC, destroy);
        fn_96_3B84(storage + 0x2A04, destroy);
        fn_96_3A2C(storage + 0x20A8, destroy);
        fn_96_38E4(storage + 0x19EC, destroy);
        fn_96_37A8(storage + 0x1978, destroy);
        fn_96_259C(storage + 0x193C, destroy);
        fn_96_2530(storage + 0x1894, destroy);
        fn_96_24BC(storage + 0x17E0, destroy);
        fn_96_3620(storage + 0x1444, destroy);
        fn_96_3024(storage + 0x1180, destroy);
        fn_96_2ED4(storage + 0x115C, destroy);
        fn_96_2D70(storage + 0xAC8, destroy);
        fn_96_2460(storage + 0xAB0, destroy);
        reinterpret_cast<soModuleAccesser*>(storage + 0x9D0)->soModuleAccesser::~soModuleAccesser();
        fn_96_2C2C(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
