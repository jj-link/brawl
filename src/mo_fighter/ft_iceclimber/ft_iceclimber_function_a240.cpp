#pragma force_active on

struct LinkEvent {
    unsigned int id;
    unsigned char flag;
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
    virtual void fn_105_184D4(unsigned int);
    virtual unsigned int fn_105_18484(unsigned int);
    virtual void fn_105_184CC();
    virtual void fn_105_184BC(int, LinkEvent*, int);
    virtual unsigned int fn_105_184AC(unsigned int);
    virtual void fn_105_1849C(unsigned int);
};

struct Modules {
    char pad0[0x54];
    Class_8CA8* link;
    char pad58[0x0C];
    Class_8CA8* value;
};

struct Accesser {
    char pad0[0xD8];
    Modules* modules;
};

extern "C" void fn_27_13138C(void*, int, int, void*, void*);
extern "C" void fn_27_12D450(void*);
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned int, unsigned int);

extern "C" void fn_105_A240(void* self, int status, int previous, void* data, void* accesser) {
    fn_27_13138C(self, status, previous, data, accesser);

    switch (status) {
    case 0x19:
        switch (previous) {
        case 0x112: {
            Class_8CA8* value = *(Class_8CA8**)((char*)*(Modules**)((char*)*(void**)((char*)self + 0x60) + 0xD8) + 0x64);
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                *(void**)((char*)self + 0x60), 0xFA1, 0);
            value->fn_105_184D4(0x11000000);
            (*(Class_8CA8**)((char*)*(Modules**)((char*)*(void**)((char*)self + 0x60) + 0xD8) + 0x64))
                ->fn_105_1849C(0x12000003);
            break;
        }
        case 0x113: {
            Class_8CA8* value = *(Class_8CA8**)((char*)*(Modules**)((char*)*(void**)((char*)self + 0x60) + 0xD8) + 0x64);
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                *(void**)((char*)self + 0x60), 0xFA9, 0);
            value->fn_105_184D4(0x11000000);
            (*(Class_8CA8**)((char*)*(Modules**)((char*)*(void**)((char*)self + 0x60) + 0xD8) + 0x64))
                ->fn_105_1849C(0x12000003);
            break;
        }
        case 0x11C: {
            Class_8CA8* value = *(Class_8CA8**)((char*)*(Modules**)((char*)*(void**)((char*)self + 0x60) + 0xD8) + 0x64);
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                *(void**)((char*)self + 0x60), 0xFBD, 0);
            value->fn_105_184D4(0x11000000);
            (*(Class_8CA8**)((char*)*(Modules**)((char*)*(void**)((char*)self + 0x60) + 0xD8) + 0x64))
                ->fn_105_1849C(0x12000003);
            Class_8CA8* value2 = *(Class_8CA8**)((char*)*(Modules**)((char*)*(void**)((char*)self + 0x60) + 0xD8) + 0x64);
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                *(void**)((char*)self + 0x60), 0xFBC, 0);
            value2->fn_105_184D4(0x11000001);
            break;
        }
        case 0x11B: {
            Class_8CA8* value = *(Class_8CA8**)((char*)*(Modules**)((char*)*(void**)((char*)self + 0x60) + 0xD8) + 0x64);
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                *(void**)((char*)self + 0x60), 0xFD2, 0);
            value->fn_105_184D4(0x11000000);
            (*(Class_8CA8**)((char*)*(Modules**)((char*)*(void**)((char*)self + 0x60) + 0xD8) + 0x64))
                ->fn_105_1849C(0x12000003);
            Class_8CA8* value2 = *(Class_8CA8**)((char*)*(Modules**)((char*)*(void**)((char*)self + 0x60) + 0xD8) + 0x64);
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                *(void**)((char*)self + 0x60), 0xFD1, 0);
            value2->fn_105_184D4(0x11000001);
            break;
        }
        }
        break;
    case 0x10:
        if (previous == 0x11B) {
            if (((Accesser*)accesser)->modules->link->fn_105_184F4(6) == 1) {
                LinkEvent event;
                event.id = 0x45D;
                event.flag = 0;
                ((Accesser*)accesser)->modules->link->fn_105_184BC(6, &event, 0);
            }
        }
        break;
    case 0x73:
        if (previous == 0x11D) {
            if ((*(Class_8CA8**)((char*)*(Modules**)((char*)*(void**)((char*)self + 0x60) + 0xD8) + 0x64))
                    ->fn_105_184AC(0x1200003E) == 1) {
                if (((Accesser*)accesser)->modules->link->fn_105_184F4(6) == 1) {
                    LinkEvent event;
                    event.id = 0x45A;
                    event.flag = 0;
                    ((Accesser*)accesser)->modules->link->fn_105_184BC(6, &event, 0);
                }
            }
        }
        break;
    case 0x120:
        fn_27_12D450(self);
        break;
    }
}
