#pragma force_active on
struct AdvEntry {
    unsigned char padding[0x2B0];
    int value;
};

struct IfAdvMngr {
    unsigned char padding[0xE8];
    AdvEntry* entries[4];
};

extern "C" {
extern IfAdvMngr* g_IfAdvMngr;
void fn_800E4D28(AdvEntry*, int);

void fn_27_25B508(unsigned char* self, int index, bool state) {
    if (state == false && (self + index)[0xB4] == 1) {
        if (g_IfAdvMngr != 0) {
            fn_800E4D28(g_IfAdvMngr->entries[index], 0);
            g_IfAdvMngr->entries[index]->value = 0;
        }
    }
    (self + index)[0xB4] = state;
}
}
