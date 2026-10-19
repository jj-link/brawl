#include <types.h>
#pragma force_active on

struct Entry {
    int value;
    float weight;
};

struct Table {
    u8 pad[0x18];
    Entry* entries;
    int count;
};

struct WorkModule;

struct ModuleSet {
    u8 pad[0x64];
    WorkModule* work;
};

struct Accesser {
    u8 pad0[8];
    void* owner;
    u8 pad1[0xCC];
    ModuleSet* modules;
};

struct WorkModule {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void setInt(int, unsigned int);
};

struct Weights;
struct WeightVTable {};

struct WeightInterface {
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
    virtual void push(const float*);
};

struct Weights {
    WeightVTable* vtable;
    void* secondVtable;
    unsigned int count : 19;
    unsigned int flags : 13;
    float values[20];
};

extern "C" {
extern u8 lbl_103_data_654[];
extern u8 lbl_103_data_22A0[];
extern u8 lbl_103_data_64D4[];

int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, unsigned long, unsigned long);
unsigned int fn_27_8E8A4(int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Table* fn_103_9120(void*);
int fn_27_8E950(Weights*);
void* fn_103_F644(void*, short);

void fn_103_F340(void*, Accesser* accesser) {
    if (fn_27_8E8A4(
            getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0x5DC1, 0)) == 1) {
        void* fighter = __dynamic_cast(
            accesser->owner, 0x3C,
            lbl_103_data_654, lbl_103_data_22A0, 0);
        if (fighter == 0) {
            return;
        }

        Table* table = fn_103_9120(fighter);
        Weights weights;
        weights.vtable =
            reinterpret_cast<WeightVTable*>(lbl_103_data_64D4);
        weights.secondVtable = lbl_103_data_64D4 + 0x48;
        weights.count = 0;

        for (int i = 0; i < table->count; ++i) {
            reinterpret_cast<WeightInterface*>(&weights)->push(
                &table->entries[i].weight);
        }

        int index = fn_27_8E950(&weights);
        if (index < 0 || index >= table->count) {
            fn_103_F644(&weights, 0);
            return;
        }

        WorkModule* work = accesser->modules->work;
        work->setInt(table->entries[index].value, 0x20000002);
        fn_103_F644(&weights, 0);
    } else {
        WorkModule* work = accesser->modules->work;
        work->setInt(-1, 0x20000002);
    }
}
}
