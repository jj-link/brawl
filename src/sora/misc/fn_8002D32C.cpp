#include <gf/gf_scene.h>
#include <string.h>
#pragma force_active on
extern "C" void fn_800274D0(void*, void*);
extern void* lbl_805A0038;
struct ModuleEntry { void* module; const char* name; unsigned char pad; unsigned char state; char pad2[2]; };
extern "C" int postProcess__14gfSceneManagerFv(gfSceneManager* self) {
    if ((unsigned int)(*(unsigned char*)((char*)self + 0x278) >> 6 & 1) == 1) {
        const char* name = **(const char***)((char*)self + 0x27c);
        int i = 0;
        char* p = (char*)self;
        do {
            ModuleEntry* entry = (ModuleEntry*)(p + 0x290);
            void* module = entry->module;
            if (module != 0 && entry->state == 3 && (name == 0 || strcmp(entry->name, name) == 0)) {
                fn_800274D0(lbl_805A0038, module);
                entry->module = 0;
                entry->name = 0;
                entry->state = 0;
            }
            i++;
            p += 12;
        } while (i < 11);
        *(void**)((char*)self + 0x27c) = 0;
        *(unsigned char*)((char*)self + 0x278) &= ~0x40;
    }
    return 0;
}