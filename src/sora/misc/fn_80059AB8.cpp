#include <gm/gm_lib.h>
#pragma force_active on

struct Figures49 { unsigned short ids[49]; };
struct Figures10 { unsigned short ids[10]; };
extern "C" {
extern Figures49 lbl_80406FE8;
extern Figures10 lbl_8040704C;

int fn_80059AB8(int arg) {
    int result = 0;
    switch (arg) {
    case 0x3a: {
        Figures49 figures = lbl_80406FE8;
        result = 1;
        for (int i = 0; i < 49; i++) {
            if (!gmCheckExistFigure(figures.ids[i])) {
                result = 0;
                break;
            }
        }
        break;
    }
    case 0x3b: {
        Figures10 figures = lbl_8040704C;
        result = 1;
        for (int i = 0; i < 10; i++) {
            if (!gmCheckExistFigure(figures.ids[i])) {
                result = 0;
                break;
            }
        }
        break;
    }
    }
    return result;
}
}