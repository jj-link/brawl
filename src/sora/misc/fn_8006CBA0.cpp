#pragma force_active on
extern "C" {
extern char lbl_80497D20[0x150];

void* fn_8006CBA0(int arg0) {
    char* base = lbl_80497D20;
    switch (arg0) {
    case 0: return base + 0xC;
    case 1: return base + 0x34;
    case 2: return base + 0x84;
    case 3: return base + 0xAC;
    case 4: return base + 0x124;
    case 5: return base + 0xD4;
    case 6: return base + 0xFC;
    case 7: return base + 0x14C;
    case 8: return base + 0x5C;
    default: return base + 0x34;
    }
}
}