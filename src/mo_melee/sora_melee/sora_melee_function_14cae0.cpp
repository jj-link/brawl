#pragma force_active on
typedef unsigned int u32;
extern "C" void fn_27_14B700(void*);
extern "C" const float lbl_27_rodata_18D0;

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_14B698();
    virtual void fn_27_14B6D8();
    virtual void fn_27_14CA0C();
    virtual void fn_27_14CA8C();
    virtual void fn_27_14CAB0();
    virtual void fn_27_14CC78();
    virtual void fn_27_14C9A0();
    virtual void fn_27_14CC70();
    virtual void fn_27_14CC68();
    virtual void fn_27_14BCDC();
    virtual void fn_27_14CC10(void*);
    virtual void fn_27_14C9F4();
    virtual void fn_27_14CA04();
    virtual void fn_27_14C1FC();
    virtual void fn_27_14CC18();
    virtual void fn_27_14CC34();
    virtual void fn_27_14CC4C();
    virtual void fn_27_14BCE4();
    virtual void fn_27_14C204();
    virtual void fn_27_14C6E8();
    virtual void fn_27_14C848();
    virtual void fn_27_14CAE0();
};
class soControllerModuleImpl {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void fn_27_151088();
    virtual void fn_27_150688();
    virtual void fn_27_151078();
    virtual void fn_27_151068();
    virtual void fn_27_151010();
    virtual void fn_27_150FFC();
    virtual void fn_27_150FE8();
    virtual void fn_27_150FD4();
    virtual void getStickAngle();
    virtual float getStickDir();
    virtual void isStickSide();
    virtual void fn_27_150FC0();
    virtual void fn_27_150FAC();
    virtual void fn_27_150F98();
    virtual void fn_27_150F84();
    virtual void fn_27_150F70();
    virtual void fn_27_150F5C();
    virtual void fn_27_150F48();
    virtual void fn_27_150F34();
    virtual void fn_27_150F20();
    virtual void fn_27_150EC8();
    virtual void fn_27_150EB4();
    virtual void fn_27_150EA0();
    virtual void fn_27_150E8C();
    virtual void getSubStickDir();
    virtual void isSubStickSide();
    virtual void fn_27_150E78();
    virtual void fn_27_150E64();
    virtual void fn_27_150E50();
    virtual void fn_27_150E3C();
    virtual void fn_27_150E28();
    virtual void fn_27_150E18();
    virtual void fn_27_1509E8();
    virtual void fn_27_150D28();
    virtual void fn_27_150E10();
    virtual void fn_27_150A7C();
};
class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual void fn_27_14AD8();
    virtual void fn_27_14A60();
    virtual void fn_27_14D08();
    virtual void fn_27_14EDC();
    virtual void fn_27_14D00();
    virtual void fn_27_14B80();
    virtual void fn_27_14B88();
    virtual void fn_27_16A70();
    virtual void fn_27_16AB8();
    virtual void fn_27_1CBB4();
    virtual void fn_27_14A20();
    virtual void fn_27_1CBAC();
    virtual void fn_27_1CBA4();
    virtual void fn_27_14B98();
    virtual void fn_27_14B90();
    virtual void fn_27_1CB88();
    virtual void fn_27_14CF8();
    virtual void fn_27_16778();
    virtual void fn_27_1688C();
    virtual void fn_27_1C2E4();
    virtual void fn_27_1BC08();
    virtual void fn_27_1BCF0();
    virtual void fn_27_16AE0();
    virtual void fn_27_15604();
    virtual void fn_27_16CA8();
    virtual void fn_27_16CB0();
    virtual void fn_27_1CB80();
    virtual void fn_27_16CB8();
    virtual void fn_27_16CC0();
    virtual void fn_27_16E88();
    virtual void fn_27_16FB4();
    virtual void fn_27_170A8();
    virtual void fn_27_171D0();
    virtual void fn_27_1CB6C();
    virtual void fn_27_1CB38();
    virtual void fn_27_17334();
    virtual void fn_27_17374();
};
extern "C" void fn_27_14CAE0(char* self) {
    soNullable* obj = (soNullable*)self;
    fn_27_14B700(self);
    soControllerModuleImpl* controller = (soControllerModuleImpl*)*(char**)(*(char**)(*(char**)(self + 0x14) + 0xd8) + 0xc);
    float dir = controller->getStickDir();
    u32 flags = *(u32*)(self + 0x538);
    if (flags & 1) {
        obj->fn_27_14BCE4();
    } else if (flags & 2) {
        obj->fn_27_14C204();
    } else if (lbl_27_rodata_18D0 != dir) {
        obj->fn_27_14BCE4();
        *(u32*)(self + 0x538) |= 1;
    }
    if (*(u32*)(self + 0x538) & 4) {
        obj->fn_27_14C6E8();
    }
    if (*(u32*)(self + 0x538) & 8) {
        obj->fn_27_14C848();
    }
    char* modules = *(char**)(*(char**)(self + 0x14) + 0xd8);
    Class_1250* finalModule = *(Class_1250**)(modules + 0x54);
    obj->fn_27_14CC10(modules);
    finalModule->fn_27_17374();
}