#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" unsigned char lbl_40_data_7890[];
extern "C" const float lbl_40_rodata_3E0;

struct grYakumono_base { char pad[0x3c]; };
class grYakumono : public grYakumono_base {
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
    virtual void slot42(int);
};
struct Object : grYakumono {
    char pad40[0xb8];
    float fF8;
    char padFC[0x54];
    int i150, i154, i158, i15C, i160;
};
extern "C" Object* fn_40_26104(int arg, const char* name) {
    Object* obj = (Object*)__nw__FUlQ25Heaps8HeapType(0x164, 15);
    if (obj) {
        __ct__10grYakumonoFPCc(obj, name);
        *(void**)((char*)obj + 0x3c) = lbl_40_data_7890;
        obj->i160 = 0;
        obj->fF8 = lbl_40_rodata_3E0;
        obj->i150 = 0;
        obj->i154 = 0;
        obj->i158 = 0;
        obj->i15C = 0;
    }
    if (obj) obj->slot42(arg);
    return obj;
}