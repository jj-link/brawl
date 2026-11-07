#include <gf/gf_pad_system.h>
#pragma force_active on

static inline unsigned char readControllerMap(const unsigned char* map, int index)
{
    return index[map];
}

extern "C" {
extern const float lbl_2_rodata_218[];
void fn_1_6DB4(void*, void*);
void fn_1_6DA0(void*, void*);
void fn_800B6838(void*, const float*);
}

extern "C" void fn_2_B918(char* self, int flag)
{
    gfPadStatus status;
    const char* base = (const char*)lbl_2_rodata_218;
    unsigned int index;

    fn_1_6DB4(*(void**)(self + 0x40),
              *(void**)(*(char**)(self + 0x14c) + 0x10));

    const unsigned char* table = (const unsigned char*)(base + 0x17c);
    for (unsigned int i = 0; i < 4; ++i, ++table) {
        fn_1_6DB4(*(void**)(self + 0x40),
                  *(void**)(*(char**)(self + 0xe8 + *table * 4) + 0x10));
    }

    fn_1_6DA0(*(void**)(self + 0x40),
              *(void**)(*(char**)(self + 0x14c) + 0x10));

    g_gfPadSystem->getSysPadStatus(*(int*)(self + 0x25c), &status);

    void* context = *(void**)(self + 0x40);
    table = (const unsigned char*)(base + 0x17c);
    unsigned int padType = status.m_controllerType;
    table += padType;
    index = *table;

    fn_1_6DA0(context,
              *(void**)(*(char**)(self + 0xe8 + index * 4) + 0x10));

    void* object = *(void**)(self + 0xe8 + (unsigned char)index * 4);
    if (flag) {
        float pos[3];
        pos[0] = *(const float*)(base + 0x88);
        pos[1] = *(const float*)(base + 0x88);
        pos[2] = *(const float*)(base + 0x88);
        fn_800B6838(object, pos);
    } else {
        float pos[3];
        pos[0] = *(const float*)(base + 0x88);
        pos[1] = *(const float*)(base + 0x180);
        pos[2] = *(const float*)(base + 0x88);
        fn_800B6838(object, pos);
    }
}
