#include <types.h>
#pragma force_active on

extern "C" void fn_27_5AF7C(void* self);

class Class_6170 {
public:
    virtual void fn_27_5AF08();
    virtual void fn_27_5B234();
    virtual void fn_27_5B230();
    virtual void fn_27_5B22C();
    virtual void fn_27_5B228();
    virtual s32 fn_27_5AF7C();
    virtual void fn_27_5B224();
    virtual void fn_27_5AF14();
    virtual void fn_27_5B214();
    virtual void fn_27_5AF1C();
};

class Class_Result {
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
    virtual s32 slot9();
};

class DispatchPrefix {
public:
    u32 word0;
    u32 word1;
};

class Class_1250Call : public DispatchPrefix {
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
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void method(s32, s32);
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void recordMethod(s32, s32, s32, s32);
};

extern "C" void fn_27_5B6A8(void* arg0) {
    s32 result;
    char* a = (char*)arg0;
    s32 outerOffset;
    s32 innerOffset;
    s32 outer;
    void* elem;
    s32 inner;

    fn_27_5AF7C(arg0);

    result = 0;
    void* p = *(void**)(a + 0x10);
    p = *(void**)((char*)p + 0xD8);
    Class_6170* p68 = (Class_6170*)*(void**)((char*)p + 0x68);
    if (p68->fn_27_5AF7C() != 0) {
        result = ((Class_Result*)arg0)->slot9();
    }

    s32 i = 1;
    while (i < *(s32*)(a + 0x28)) {
        Class_1250Call* p4 = (Class_1250Call*)*(void**)((char*)*(void**)((char*)*(void**)(a + 0x10) + 0xD8) + 4);
        p4->method(result, i);
        i++;
    }

    outer = 0;
    outerOffset = 0;
    while (outer < *(s32*)(a + 0x28)) {
        elem = *(void**)((char*)(*(void**)(*(void**)(a + 0x20))) + outerOffset);
        if (elem != 0) {
            inner = 0;
            innerOffset = 0;
            while (inner < *(s32*)((char*)*(void**)(a + 0x20) + 4)) {
                char* data = (char*)*(void**)(a + 0x24) + innerOffset;
                s32 selected = *(s8*)(data + 1) + *(u8*)(data + 2);
                if (*(s32*)((char*)elem + 4) > 0) {
                    s32 j = 0;
                    result = 0;
                    while (j < *(s32*)((char*)elem + 4)) {
                        if (j != selected) {
                            Class_1250Call* p4 = (Class_1250Call*)*(void**)((char*)*(void**)((char*)*(void**)(a + 0x10) + 0xD8) + 4);
                            char* record = (char*)*(void**)elem + result;
                            p4->recordMethod(
                                *(s32*)(record + 4), *(s32*)record, 0, outer);
                        }
                        result += 8;
                        j++;
                    }
                    if (selected != -1) {
                        Class_1250Call* p4 = (Class_1250Call*)*(void**)((char*)*(void**)((char*)*(void**)(a + 0x10) + 0xD8) + 4);
                        char* record = (char*)*(void**)elem + selected * 8;
                        p4->recordMethod(
                            *(s32*)(record + 4), *(s32*)record, 1, outer);
                    }
                }
                innerOffset += 3;
                elem = (void*)((char*)elem + 8);
                inner++;
            }
        }
        outerOffset += 4;
        outer++;
    }
}
