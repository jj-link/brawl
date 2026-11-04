#include <so/so_value_accesser.h>
#pragma force_active on

struct Entry { unsigned int id; float value; unsigned int extra; };

namespace Match {
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(soModuleAccesser*);
    virtual void slot4();
    virtual void slot5(int);
    virtual int slot6();
    virtual void slot7();
    virtual void slot8(int);
    virtual void slot9(float, float, float);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(int);
    virtual void slot14();
    virtual void slot15(int, int);
    virtual void slot16(int, int);
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22(int);
    virtual void slot23();
    virtual void slot24(int, int);
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
};
}
struct Prefix { char pad[0x3c]; };
class Object : public Prefix {
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
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void process(Entry*);
    virtual void slot183();
    virtual void slot184();
    virtual void* getData();
    char pad40[0x20];
    soModuleAccesser* acc;
};

extern "C" {
int fn_27_11222C(void*);
int fn_27_11225C(void*);
int fn_27_112ABC(void*);
void fn_27_112AC8(void*, int, Entry*);
extern const float lbl_27_rodata_1054;
extern const float lbl_27_rodata_1058;
}

extern "C" void fn_27_13DF5C(Object* self) {
    soModuleAccesser* acc;
    Match::soNullable* module;
    void* data = self->getData();
    module = (Match::soNullable*)self->acc->m_enumerationStart->m_glowModule;
    if (module->slot6() != 0) return;
    int first = fn_27_11222C(data);
    int second = fn_27_11225C(data);
    module->slot17();
    int count = fn_27_112ABC(data);
    if (count > 0) {
        for (int i = 0; i < count; ++i) {
            Entry entry;
            fn_27_112AC8(data, i, &entry);
            switch (entry.id) {
            case 0: first += (int)(entry.value * lbl_27_rodata_1054); break;
            case 1: second += (int)(entry.value * lbl_27_rodata_1054); break;
            case 0x6:
            case 0x33:
                module->slot16(4, (int)(entry.value * lbl_27_rodata_1054));
                module->slot16(5, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x7:
            case 0x30:
            case 0x32:
            case 0x34:
            case 0x39:
            case 0x3b:
                module->slot16(6, (int)(entry.value * lbl_27_rodata_1054));
                module->slot16(7, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x8:
            case 0x31:
            case 0x36:
                module->slot16(9, (int)(entry.value * lbl_27_rodata_1054));
                module->slot16(10, (int)(entry.value * lbl_27_rodata_1054));
                module->slot16(11, (int)(entry.value * lbl_27_rodata_1054));
                module->slot16(17, (int)(entry.value * lbl_27_rodata_1054));
                module->slot16(23, (int)(entry.value * lbl_27_rodata_1054));
                module->slot16(20, (int)(entry.value * lbl_27_rodata_1054));
                module->slot16(19, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x9:
            case 0x2f:
                module->slot16(1, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0xa:
                module->slot16(2, (int)(entry.value * lbl_27_rodata_1054));
                module->slot16(3, (int)(entry.value * lbl_27_rodata_1054));
                module->slot16(13, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0xb:
                module->slot16(8, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0xc:
                module->slot16(15, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0xd:
                module->slot16(18, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0xe:
                module->slot16(21, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0xf:
                module->slot16(22, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x10:
                module->slot16(16, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x11:
                module->slot16(14, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x12:
            case 0x38:
                module->slot16(24, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x13:
            case 0x3a:
                module->slot16(4, (int)(entry.value * lbl_27_rodata_1054));
                module->slot16(5, (int)(entry.value * lbl_27_rodata_1054));
                module->slot16(6, (int)(entry.value * lbl_27_rodata_1054));
                module->slot16(7, (int)(entry.value * lbl_27_rodata_1054));
                module->slot16(8, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x42:
                module->slot16(25, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x40:
                module->slot16(12, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x14:
                module->slot15(2, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x15:
                module->slot15(3, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x16:
                module->slot15(5, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x17:
                module->slot15(17, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x43:
                module->slot15(21, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x44:
                module->slot15(4, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x45:
                module->slot15(19, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x18:
            case 0x35:
            case 0x37:
                module->slot24(0, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x19:
                module->slot24(2, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x1a:
                module->slot24(5, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x1b:
                module->slot24(3, (int)(entry.value * lbl_27_rodata_1054));
                break;
            case 0x23:
            case 0x5a:
            case 0x5b:
                self->acc->m_enumerationStart->m_damageModule->setNoReactionMode2nd(entry.value, lbl_27_rodata_1058, 2);
                break;
            case 0x1d:
                module->slot22((int)(entry.value * lbl_27_rodata_1054));
                break;
            default:
                self->process(&entry);
                break;
            }
        }
    }
    module->slot5(first);
    module->slot8(second);
    acc = self->acc;
    float middle;
    float third = soValueAccesser::getConstantFloat(acc, 0xd24, 0);
    middle = soValueAccesser::getConstantFloat(acc, 0xd23, 0);
    float low = soValueAccesser::getConstantFloat(acc, 0xd22, 0);
    module->slot9(low, middle, third);
    module->slot13(soValueAccesser::getConstantInt(self->acc, 0x5a50, 0));
    module->slot3(self->acc);
    module->slot29();
}
