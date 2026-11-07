#include <snd/snd_system.h>
#pragma force_active on
extern "C" int fn_40_48C04(char* p) {
    int result = 0;
    unsigned int flags = *(unsigned int*)(p + 0x15c);
    if (flags & 0x100) {
        g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
        switch (*(unsigned int*)(p + 0x50)) {
        case 1: result = 7; break;
        case 0: result = 5; break;
        case 2: result = 2; break;
        case 3: result = 8; break;
        case 4: result = 9; break;
        case 5: result = 10; break;
        case 6: result = 11; break;
        }
    } else if (flags & 0x200) {
        g_sndSystem->playSE((SndID)6, -1, 0, 0, -1);
        result = 1;
    }
    return result;
}