#pragma force_active on

extern "C" {
extern void* g_GameGlobal;
unsigned int* fn_8004E594(void*);
int exchangeMuStageKindToGmHideStageKind__6muMenuFiii(int);
}

extern "C" int fn_2_1EE8C(void) {
    unsigned int* bits = fn_8004E594(g_GameGlobal);
    int i;
    int count = 0;
    i = 0;

    do {
        int id = exchangeMuStageKindToGmHideStageKind__6muMenuFiii(i);
        if (id != 0xc) {
            if (bits[id / 32] & (1 << (id % 32)))
                ++count;
        } else {
            ++count;
        }
        ++i;
    } while (i < 0x29);

    return count;
}
