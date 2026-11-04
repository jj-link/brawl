#pragma force_active on
extern "C" void fn_27_131020(void*);

struct Event {
    unsigned int id;
    unsigned char flag;
};

class Class_8AD0 {
public:
    virtual void fn_105_8130();
    virtual void fn_105_17CBC();
    virtual void fn_105_18340();
    virtual void fn_105_1833C();
    virtual void fn_105_18338();
    virtual void fn_105_18334();
    virtual void fn_105_1832C();
    virtual void fn_105_18374();
    virtual void fn_105_1836C();
    virtual void fn_105_18364();
    virtual void fn_105_1835C();
    virtual void fn_105_18354();
    virtual void fn_105_182EC();
    virtual void fn_105_18320();
    virtual void fn_105_18314();
    virtual void fn_105_1830C();
    virtual void fn_105_18300();
    virtual int fn_105_182F8(unsigned int);
};

class Class_8CA8 {
public:
    virtual void fn_105_8130();
    virtual void fn_105_17C60();
    virtual void fn_105_1852C();
    virtual void fn_105_18524();
    virtual void fn_105_1851C();
    virtual void fn_105_18514();
    virtual void fn_105_1850C();
    virtual void fn_105_18504();
    virtual void fn_105_184FC();
    virtual unsigned int fn_105_184F4(int);
    virtual void fn_105_184EC();
    virtual void fn_105_184E4();
    virtual void fn_105_184DC();
    virtual void fn_105_184D4();
    virtual void fn_105_18484();
    virtual void fn_105_184CC();
    virtual void fn_105_184BC(int, Event*, int);
    virtual void fn_105_184AC();
};

extern "C" void fn_105_D180(void* self) {
    fn_27_131020(self);
    unsigned char* p = *(unsigned char**)((unsigned char*)self + 0x60);
    p = *(unsigned char**)(p + 0xd8);
    Class_8AD0* work = *(Class_8AD0**)(p + 0x64);
    if (work->fn_105_182F8(0x1200003e) == 0) {
        p = *(unsigned char**)((unsigned char*)self + 0x60);
        p = *(unsigned char**)(p + 0xd8);
        Class_8CA8* link = *(Class_8CA8**)(p + 0x54);
        if (link->fn_105_184F4(6) == 1U) {
            Event event;
            event.id = 0x461;
            event.flag = 0;
            p = *(unsigned char**)((unsigned char*)self + 0x60);
            p = *(unsigned char**)(p + 0xd8);
            link = *(Class_8CA8**)(p + 0x54);
            link->fn_105_184BC(6, &event, 0);
        }
    }
}