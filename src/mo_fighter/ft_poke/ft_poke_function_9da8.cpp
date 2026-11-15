#include <so/so_module_accesser.h>
#pragma force_active on

extern const float lbl_116_rodata_4;
extern const float lbl_116_rodata_8;

#define D(n) virtual void d##n();

class PartialMotionModule {
public:
    D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9)
    D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19)
    D(20) D(21) D(22) D(23) D(24) D(25) D(26) D(27) D(28) D(29)
    D(30) D(31) D(32) D(33) D(34) D(35) D(36) D(37) D(38)
    virtual void start(int, int, int, unsigned char, float, float, unsigned char);
    virtual void stop(int);
};

extern "C" void fn_116_9DA8(
    void* self, int a, int b, unsigned char* flags, soModuleAccesser* accesser)
{
    if (flags[1] & 8) {
        if (*((unsigned char*)self + 0x17FD8) == 0) {
            *((unsigned char*)self + 0x17FD8) = 1;
            ((PartialMotionModule*)accesser->m_enumerationStart->m_motionModule)
                ->start(1, 0x1DB, 0x10, 0, lbl_116_rodata_8, lbl_116_rodata_4, 0);
            ((PartialMotionModule*)accesser->m_enumerationStart->m_motionModule)
                ->start(2, 0x1DC, 0x2C, 0, lbl_116_rodata_8, lbl_116_rodata_4, 0);
        }
    } else if (*((unsigned char*)self + 0x17FD8) == 1) {
        *((unsigned char*)self + 0x17FD8) = 0;
        ((PartialMotionModule*)accesser->m_enumerationStart->m_motionModule)->stop(1);
        ((PartialMotionModule*)accesser->m_enumerationStart->m_motionModule)->stop(2);
    }
}
