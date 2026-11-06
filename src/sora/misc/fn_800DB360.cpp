#include <gf/gf_3d_scene.h>
#pragma force_active on

extern "C" void* fn_801AC554(void*, int);
extern "C" void fn_801A7BE0(void**, float*, int);
extern "C" void fn_801A7720(void**, float*);
extern const float lbl_805A2330;
extern const float lbl_805A2334;
extern const float lbl_805A2338;
extern const float lbl_805A233C;
extern const float lbl_805A2340;
extern const float lbl_805A2344;

extern "C" void fn_800DB360(float* out, int arg1) {
    float pos[3];
    float unused[3];
    void* other = *(void**)((char*)g_gfSceneRoot + 0x44);
    void* first = fn_801AC554(*(void**)((char*)g_gfSceneRoot + 0x40), 0);
    fn_801A7BE0(&first, pos, arg1);
    void* data = fn_801AC554(other, 0);
    void* second = data;
    fn_801A7720(&second, unused);
    float x = *(float*)((char*)data + 0xB0) * (lbl_805A2330 * (pos[0] - lbl_805A2334));
    out[0] = x;
    out[1] = lbl_805A2338 * ((lbl_805A233C - pos[1]) - lbl_805A2340);
    out[2] = lbl_805A2344;
    if ((int)g_gfSceneRoot->m_transformFlag.m_mask >> 24)
        out[0] = -x;
}
