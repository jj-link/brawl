#include <types.h>
#pragma force_active on

struct Stage_base {
    char pad[0x3c];
};

#define SLOT(n) virtual void f##n() = 0;

class Stage : public Stage_base {
public:
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47) SLOT(48) SLOT(49)
    SLOT(50) SLOT(51)
    virtual void fn_88_4194(int, int, u32, int, int) = 0;
    char pad2[0x128];
    u32 values[1];
};

extern "C" void fn_88_731C(Stage* self, unsigned long index) {
    index = self->values[index];
    self->fn_88_4194(0, 0, index, 1, 0);
}
