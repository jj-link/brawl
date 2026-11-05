struct Vec3f;
#include <snd/snd_3d_generator.h>
#include <string.h>
#pragma force_active on

class Class_1870 {
public:
    virtual void fn_68_94B0();
    virtual void fn_68_8978();
    virtual void fn_68_8988();
    virtual void fn_68_64EC();
    virtual void fn_68_61AC(int, int);
    unsigned int* flags;
    int state;
};
class Class_2428 {
public:
    virtual void fn_68_E3F0();
    virtual void fn_68_D810();
    virtual void fn_68_D820();
    virtual void fn_68_D700();
    virtual void fn_68_D53C();
};
extern "C" {
void* fn_68_2398(void*, const char*);
void* __ct__14snd3DGeneratorFv(void*);
extern char lbl_68_data_8E8[];
extern char lbl_68_data_810[];
extern const float lbl_68_rodata_20[];

void* fn_68_2578(char* self, const char* name) {
    const float* k = &lbl_68_rodata_20[1];
    fn_68_2398(self, name);
    *(void**)(self + 0x3c) = lbl_68_data_8E8;
    __ct__14snd3DGeneratorFv(self + 0x1e4);
    *(void**)(self + 0x1f0) = 0;
    *(void**)(self + 0x1f4) = 0;
    *(int*)(self + 0x1ec) = 0;
    struct Node { Node* prev; Node* next; };
    Node* node = (Node*)(self + 0x1f0);
    node->prev = node;
    node->next = node;
    *(int*)(self + 0xa50) = 0;
    *(int*)(self + 0x158) = 0;
    *(int*)(self + 0x15c) = 0;
    *(int*)(self + 0x160) = 0;
    *(char*)(self + 0x164) = 0;
    *(char*)(self + 0x9bc) = 0;
    *(char*)(self + 0x9bd) = 0;
    *(char*)(self + 0x9be) = 0;
    *(float*)(self + 0x9c0) = k[-1];
    *(float*)(self + 0x9c4) = k[0];
    *(float*)(self + 0x9c8) = k[1];
    *(char*)(self + 0x9cc) = 0;
    strcpy(self + 0x9cd, lbl_68_data_810);
    char* p = self;
    for (int i = 0; i < 31; i++, p += 0x40) {
        *(float*)(p + 0x1f8) = k[2];
        *(float*)(p + 0x1fc) = k[2];
        *(float*)(p + 0x200) = k[2];
        *(float*)(p + 0x204) = k[2];
        *(float*)(p + 0x208) = k[2];
        *(float*)(p + 0x20c) = k[2];
        *(char*)(p + 0x210) = 0;
        *(float*)(p + 0x214) = k[2];
        *(float*)(p + 0x218) = k[2];
        *(float*)(p + 0x21c) = k[2];
        *(float*)(p + 0x220) = k[2];
        *(float*)(p + 0x224) = k[2];
        *(float*)(p + 0x228) = k[2];
        *(float*)(p + 0x22c) = k[2];
        *(char*)(p + 0x230) = 0;
        *(float*)(p + 0x234) = k[2];
    }
    *(int*)(self + 0x9b8) = 0;
    memset(self + 0x168, 0, 0x78);
    Class_1870* sub = (Class_1870*)(self + 0xd0);
    *(char*)(self + 0x1e0) = 7;
    if (!sub) return self;
    sub->state = 1;
    sub->fn_68_61AC(0, 15);
    sub->flags[1] |= 1;
    sub->flags[1] |= 2;
    return self;
}
}