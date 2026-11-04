#include <gm/gm_global.h>
#include <types.h>

#pragma force_active on

extern "C" int randi__Fl(int);
extern "C" int exchangeMuCharKindToMuSelchkind__6muMenuFiii(int);
extern "C" int getNumCharColor__6muMenuFiii(int);
extern "C" int sprintf(char*, const char*, ...);
extern "C" char lbl_3_data_858[];

extern "C" void fn_3_A4A0(char* self) {
    int array[32];
    for (int x = 0; x < 32; x++) {
        array[x] = -1;
    }
    {
        int count = 0;
        while (count < *(u32*)(self + 0x9E8)) {
            int j;
            do {
                j = randi__Fl(*(u32*)(self + 0x9E8));
            } while (array[j] != -1);
            array[j] = count;
            count++;
        }
    }

    char* entry = (char*)g_GameGlobal->m_tournamentData + 8;
    char* entry2 = self;
    char* name = self + 0x108;
    int* ap = array;
    unsigned int i = 0;

    while (i < *(u32*)(self + 0x9E8)) {
        entry[0x1b] = *(u32*)(entry2 + 0x120);
        switch (*(u32*)(entry2 + 0x104)) {
        case 0:
            entry[0x00] = 0;
            break;
        case 1:
            entry[0x00] = 1;
            if (*(u32*)(self + 0xA0C) == 9) {
                entry[0x24] = randi__Fl(9);
            } else {
                entry[0x24] = *(u32*)(self + 0xA0C);
            }
            break;
        case 2:
            entry[0x00] = 2;
            break;
        }
        sprintf(entry + 2, lbl_3_data_858, name);
        entry[0x17] = entry2[0x128];
        entry[0x18] = entry2[0x129];
        entry[0x19] = entry2[0x12A];
        if (*(s32*)(entry2 + 0x120) == 0x29) {
            int flag = 1;
            int n = 0;
            while (flag) {
                flag = 0;
                int temp = randi__Fl(*(u32*)(self + 0xA00) - 1);
                int kind = exchangeMuCharKindToMuSelchkind__6muMenuFiii(*(int*)(self + 0xA4C + temp * 4));
                *(u32*)(entry2 + 0x120) = kind;
                int color = randi__Fl(getNumCharColor__6muMenuFiii(kind));
                entry2[0x124] = color;
                int old_n = n;
                n++;
                if (old_n >= 0x12C) {
                    break;
                }
                char* other = self;
                for (unsigned int k = 0; k < i; k++) {
                    if (*(int*)(other + 0x120) == *(int*)(entry2 + 0x120) &&
                        *(u8*)(other + 0x124) == *(u8*)(entry2 + 0x124)) {
                        flag = 1;
                        break;
                    }
                    other += 0x28;
                }
            }
        }
        entry[0x1A] = *(u32*)(entry2 + 0x120);
        entry[0x1C] = entry2[0x124];
        *(u16*)(entry + 0x1E) = *(u16*)(entry2 + 0x126);
        *(u32*)(entry + 0x20) = *ap;
        ap++;
        entry2 += 0x28;
        name += 0x28;
        entry += 0x28;
        i++;
    }
}