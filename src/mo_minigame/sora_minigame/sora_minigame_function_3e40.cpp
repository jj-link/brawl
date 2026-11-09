#include <snd/snd_system.h>
#pragma force_active on

extern "C" void fn_80101378(void* p);
extern "C" void fn_80101384(void* p, int n);
extern "C" void fn_80101438(void* p, int a, int b, int c);
extern "C" void fn_801018EC(void* p, void* v);

extern void* lbl_20_bss_8;
extern void* lbl_805A0310;

extern "C" void fn_20_3E40(void* arg0, int arg1) {
    char sp8[16];
    unsigned char* s;
    int var;

    s = (unsigned char*)lbl_20_bss_8;
    if (arg1 != 0) {
        if ((int)s[0x46] != 0) {
            g_sndSystem->playSE((SndID)0x1EC7, -1, 0, 0, -1);
        }
        fn_80101378(sp8);
        fn_80101438(sp8, 3, 0, 0);
        fn_801018EC(sp8, arg0);
        fn_80101384(sp8, -1);
    }
    if (*(unsigned int*)(s + 0x124) >= *(unsigned int*)(s + 0x120)) {
        if ((int)s[0x46] != 0) {
            var = g_sndSystem->playSE((SndID)0x1EC5, -1, 0, 0, -1);
        } else {
            var = 0;
        }
        *(int*)(s + 0x384) = var;
        s[0x64] = 1;
        *(unsigned int*)(s + 0x378) = *(unsigned int*)(s + 0x37C);
        fn_80101438(s + 0x374, 6, 0, 0);
        *(unsigned int*)(s + 0x124) = *(unsigned int*)(s + 0x124) - *(unsigned int*)(s + 0x120);
    }
    *(unsigned int*)((char*)lbl_805A0310 + 0x1C0) = *(unsigned int*)(s + 0x124);
}
