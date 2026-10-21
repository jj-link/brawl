#pragma force_active on

extern "C" void fn_27_13D34C();

extern "C" const float lbl_104_rodata_E0;

#define DUMMY(n) virtual void d##n() = 0;

struct WorkModule {
    DUMMY(0) DUMMY(1) DUMMY(2) DUMMY(3)
    virtual int get(unsigned int index) = 0;
    virtual void set7(int value, unsigned int index) = 0;
    DUMMY(6) DUMMY(7) DUMMY(8) DUMMY(9) DUMMY(10) DUMMY(11)
    DUMMY(12) DUMMY(13) DUMMY(14) DUMMY(15) DUMMY(16) DUMMY(17)
    virtual void setFlag(unsigned int index) = 0;
};

struct SubModule {
    DUMMY(0) DUMMY(1) DUMMY(2) DUMMY(3) DUMMY(4)
    DUMMY(5) DUMMY(6) DUMMY(7) DUMMY(8) DUMMY(9)
    DUMMY(10) DUMMY(11) DUMMY(12) DUMMY(13) DUMMY(14)
    DUMMY(15) DUMMY(16) DUMMY(17) DUMMY(18) DUMMY(19)
    DUMMY(20) DUMMY(21) DUMMY(22) DUMMY(23) DUMMY(24)
    DUMMY(25) DUMMY(26) DUMMY(27) DUMMY(28) DUMMY(29)
    DUMMY(30) DUMMY(31) DUMMY(32) DUMMY(33) DUMMY(34)
    DUMMY(35) DUMMY(36) DUMMY(37)
    virtual void fnA0(int value, float f) = 0;
};

extern "C" void fn_104_1B0CC(void* object, void* arg) {
    fn_27_13D34C();
    unsigned char* accesser = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x60);
    unsigned char* modules = *reinterpret_cast<unsigned char**>(accesser + 0xd8);
    WorkModule* work = *reinterpret_cast<WorkModule**>(modules + 0x64);
    int value = *reinterpret_cast<int*>(static_cast<unsigned char*>(arg) + 0x100);

    work->set7(value, 0x10000040);
    if (work->get(0x10000040) >= 6) {
        work->setFlag(0x1200003d);
        unsigned char* m2 = *reinterpret_cast<unsigned char**>(accesser + 0xd8);
        SubModule* sub = *reinterpret_cast<SubModule**>(m2 + 0x88);
        sub->fnA0(0x1a, lbl_104_rodata_E0);
    }
}
