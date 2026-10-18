#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

extern "C" {
void fn_27_12BAF8(void* object, int param);
}

#define DUMMY(n) virtual void d##n() = 0;

struct WorkModule {
    DUMMY(0) DUMMY(1) DUMMY(2) DUMMY(3)
    virtual int get(unsigned int index) = 0;
    virtual void offFlag(unsigned int flag, unsigned int index) = 0;
    DUMMY(6) DUMMY(7) DUMMY(8) DUMMY(9)
    DUMMY(10) DUMMY(11) DUMMY(12) DUMMY(13) DUMMY(14)
    DUMMY(15) DUMMY(16) DUMMY(17) DUMMY(18)
    virtual void setFlag(unsigned int index) = 0;
};

struct SubModule {
    DUMMY(0) DUMMY(1) DUMMY(2) DUMMY(3) DUMMY(4)
    DUMMY(5) DUMMY(6) DUMMY(7) DUMMY(8) DUMMY(9)
    DUMMY(10) DUMMY(11) DUMMY(12) DUMMY(13) DUMMY(14)
    DUMMY(15) DUMMY(16) DUMMY(17) DUMMY(18) DUMMY(19)
    virtual void fn58(int value) = 0;
    DUMMY(22) DUMMY(23) DUMMY(24) DUMMY(25) DUMMY(26)
    DUMMY(27) DUMMY(28) DUMMY(29) DUMMY(30) DUMMY(31)
    DUMMY(32) DUMMY(33) DUMMY(34) DUMMY(35) DUMMY(36)
    DUMMY(37) DUMMY(38) DUMMY(39)
    virtual void fnA4(int value) = 0;
};

extern "C" void fn_94_8FF4(void* object, int param) {
    unsigned char* accesser = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x60);
    unsigned char* modules = *reinterpret_cast<unsigned char**>(accesser + 0xd8);
    WorkModule* work = *reinterpret_cast<WorkModule**>(modules + 0x64);

    if (param == 8) {
        int result = work->get(0x10000040);
        if (result != 0) {
            unsigned char* a2 = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x60);
            unsigned char* m2 = *reinterpret_cast<unsigned char**>(a2 + 0xd8);
            SubModule* m = *reinterpret_cast<SubModule**>(m2 + 0x88);
            m->fn58(result);
        }
    }

    work->offFlag(0, 0x10000040);
    work->offFlag(0, 0x10000041);
    work->offFlag(0, 0x10000042);
    work->setFlag(0x1200003e);
    work->setFlag(0x1200003d);

    unsigned char* m3 = *reinterpret_cast<unsigned char**>(accesser + 0xd8);
    SubModule* m = *reinterpret_cast<SubModule**>(m3 + 0x88);
    m->fnA4(0x1a);

    fn_27_12BAF8(object, param);
}
