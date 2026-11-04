#include <gf/gf_scene.h>
#include <gm/gm_lib.h>
#pragma force_active on

extern gfSceneManager* lbl_1_bss_1A40;
extern char lbl_1_data_7880[];
struct Pair { int key; int value; };
struct Table { Pair entries[37]; };
extern Table lbl_1_rodata_C28;
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

extern "C" void fn_1_29194(int arg0, int arg1) {
    FigureScene* scene = (FigureScene*)lbl_1_bss_1A40->searchScene(lbl_1_data_7880);
    Table table = lbl_1_rodata_C28;
    int value = 0;
    for (int i = 0; i < 2; i++) {
        int key = arg0;
        if (i == 0) key = arg1;
        if (key != -1) {
            switch (key) {
            case 0x11: case 0x12:
                key = 0x10; break;
            case 0x1d: case 0x1e: case 0x1f: case 0x20: case 0x21: case 0x22:
                key = 0x1d; break;
            }
            for (int j = 0; j < 37; j++) {
                if (key == table.entries[j].key) {
                    value = table.entries[j].value;
                    break;
                }
            }
            fn_80052704((u16)value, 1);
        }
    }
    scene->value = value;
    int i = 0;
    Pair* p = table.entries;
    for (; i < 37; i++, p++) {
        if (gmCheckExistFigure((u16)p->value) == true && p->value != value)
            scene->list.append(p->value);
    }
}