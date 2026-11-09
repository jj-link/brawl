#include <types.h>
#include <gf/gf_scene.h>
#include <gm/gm_lib.h>
#pragma force_active on

extern gfSceneManager* lbl_1_bss_1994;
extern char lbl_1_data_7578[];
struct Pair { int key; int value; };
struct Table { Pair entries[39]; };
extern Table lbl_1_rodata_AC8;
extern "C" void fn_80052704(u16, u32);

class FigureList {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void append(int);
};
struct FigureScene {
    char pad[12];
    int value;
    FigureList list;
};

extern "C" void fn_1_2739C(int kind) {
    FigureScene* scene = (FigureScene*)lbl_1_bss_1994->searchScene(lbl_1_data_7578);
    switch (kind) {
    case 17: case 18: kind = 16; break;
    case 30: kind = 29; break;
    case 32: kind = 31; break;
    case 34: kind = 33; break;
    }
    Table table = lbl_1_rodata_AC8;
    Pair* p;
    int value = 0;
    for (int i = 0; i < 39; i++) {
        if (kind == table.entries[i].key) {
            value = table.entries[i].value;
            break;
        }
    }
    fn_80052704((u16)value, 1);
    switch (value) {
    case 0x43: case 0x45: case 0x47:
        value = 0x41;
        fn_80052704(0x41, 1);
        break;
    }
    scene->value = value;
    int i = 0;
    p = table.entries;
    for (; i < 39; i++, p++) {
        if (gmCheckExistFigure((u16)p->value) == true &&
            p->value != 0x43 && p->value != 0x45 && p->value != 0x47 &&
            p->value != value)
            scene->list.append(p->value);
    }
    if (gmCheckExistFigure(0x41) == true && value != 0x41)
        scene->list.append(0x41);
}