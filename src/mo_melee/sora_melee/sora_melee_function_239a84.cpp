#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" void fn_80075F1C(void*, u32, int);
extern void* g_sndSystem;
extern "C" const float lbl_27_rodata_395C;

class stMelee {
public:
    void stopSeBasic(s32 id, float frames);
};

void stMelee::stopSeBasic(s32 id, float frames) {
    if (id != -1) {
        fn_80075F1C(g_sndSystem, id, (s32)(lbl_27_rodata_395C * frames));
    }
}
