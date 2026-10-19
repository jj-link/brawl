#include <types.h>
#include <snd/snd_system.h>
#pragma force_active on

extern "C" {
void fn_103_106E4(void* unused, void* fighter);
void fn_103_10488(void* unused, void* fighter);
void fn_80076274(sndSystem*, int);
extern sndSystem* g_sndSystem;

void fn_103_10438(void* unused, void* fighter, int kind) {
    if (kind != 0 && kind != 0xE) {
        fn_103_106E4(unused, fighter);
    } else {
        fn_103_10488(unused, fighter);
    }

    if (g_sndSystem != 0) {
        fn_80076274(g_sndSystem, 0x1B4A);
    }
}
}
