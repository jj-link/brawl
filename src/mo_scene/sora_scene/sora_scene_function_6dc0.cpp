#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_8000D2E0(void*, void*, int);
extern "C" void* fn_80196E7C(void*, int);
extern "C" void fn_80196530(void*, float*, float);
extern "C" void* getManager__15gfCameraManagerFv();

extern void* g_gfSceneRoot;
extern const float lbl_1_rodata_10;

struct Tmp {
    void* obj;
    float f[6];
    u32 pad[8];
};

extern "C" void fn_1_6DC0(void*, void* arg) {
    Tmp t;
    t.obj = 0;

    fn_8000D2E0(g_gfSceneRoot, arg, 42);
    t.obj = fn_80196E7C(arg, 0);
    fn_80196530(&t.obj, t.f, lbl_1_rodata_10);
    char* mgr = (char*)getManager__15gfCameraManagerFv();
    *(float*)(mgr + 0xE4) = t.f[5];
}
