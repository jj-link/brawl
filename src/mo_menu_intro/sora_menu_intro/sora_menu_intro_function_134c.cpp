#include <mu/menu.h>
#include <stdio.h>
#pragma force_active on

extern "C" char lbl_13_data_0[];

extern "C" void fn_13_134C(void* self, char* a, char* b, char* c, int kind, int mode)
{
    char* base = lbl_13_data_0;
    char* lower = base + 0xE8;
    char* upper = base + 0xEC;
    int variant;
    switch (mode) {
    case 0: variant = 0; break;
    case 1: variant = 0; break;
    case 2: variant = 1; break;
    case 3: variant = 2; break;
    }
    int id = muMenu::exchangeGmCharacterKind2Something(kind) + 1;
    sprintf(a, base + 0xF0, lower, id);
    sprintf(b, base + 0x110, upper, id, variant);
    sprintf(c, base + 0x130, upper, id);
}