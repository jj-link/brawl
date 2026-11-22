#pragma force_active on
#include <types.h>

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* slot2();
    virtual void slot3(void*, int, short*, int);
    virtual void* slot4();
    virtual void* slot5();
};

struct Vec3 {
    float x, y, z;
};

struct Vec3Block {
    Vec3 v[5];
};
struct Build { int data[18]; };
struct ShortSlot { short n; short pad; };
struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };

extern "C" {
extern char lbl_27_data_13730[];
extern char lbl_27_data_8EB68[];
extern char lbl_27_data_8EB7C[];
extern char lbl_27_data_8EDE8[];
extern char lbl_27_data_8F054[];
extern float lbl_27_rodata_7968;
extern float lbl_27_rodata_796C;

void fn_27_1DC5E8(void*, int, const void*, void*, void*, void*, unsigned char, int,
                  void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void* fn_27_3546A4(void*, void*, void*);
void fn_27_3097BC(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
}

#define WORD(p, o) (*(int*)((char*)(p) + (o)))
#define PTR(p, o) (*(char**)((char*)(p) + (o)))
#define BYTE(p, o) (*(unsigned char*)((char*)(p) + (o)))

extern "C" void* fn_27_354048(char* self, int kind, char* resource, const int* argument) {
    void* second;
    void* third;
    void* first;

    Object_vptr_0* object = (Object_vptr_0*)PTR(resource, 0x4);
    third = object->slot5();
    second = object->slot4();
    first = object->slot2();

    Build build;
    Vec3Block block;
    ShortSlot another;
    ShortSlot one;
    int* descriptor = build.data;
    unsigned char id = *argument & 0xff;
    fn_27_1DC5E8(descriptor, 0x24, argument, first, second, third,
                 id, -1, self + 0x2140,
                 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_8EB68, descriptor[1], descriptor[2],
                 kind, resource, self + 0x8C4, 1);

    char* lbl = lbl_27_data_8EDE8;
    PTR(self, 0x3C) = lbl;
    PTR(self, 0x40) = lbl + 0x64;
    PTR(self, 0x48) = lbl + 0x70;
    PTR(self, 0x54) = lbl + 0x84;
    PTR(self, 0x64) = lbl + 0xDC;
    PTR(self, 0x70) = lbl + 0xEC;
    PTR(self, 0x7C) = lbl + 0x100;
    PTR(self, 0x88) = lbl + 0x118;
    PTR(self, 0x90) = lbl + 0x124;

    char* part = self + 0xCC;
    fn_27_3546A4(part, self, descriptor);
    fn_27_3097BC(part + 0x1A44, part + 0x7F8, descriptor);
    fn_27_1DBA64(self + 0x20C0);

    float m = lbl_27_rodata_7968;
    block.v[3].x = lbl_27_rodata_796C;
    block.v[4].x = m;
    block.v[4].y = m;
    block.v[4].z = m;
    block.v[3].y = lbl_27_rodata_796C;
    block.v[3].z = lbl_27_rodata_796C;
    block.v[2].x = m;
    block.v[2].y = m;
    block.v[2].z = m;
    block.v[1].x = lbl_27_rodata_796C;
    block.v[1].y = lbl_27_rodata_796C;
    block.v[1].z = lbl_27_rodata_796C;
    block.v[0].x = lbl_27_rodata_796C;
    block.v[0].y = lbl_27_rodata_796C;
    block.v[0].z = lbl_27_rodata_796C;

    BYTE(self, 0x20FC) = 0;
    ((FlagByte*)(self + 0x20FD))->flag = 1;
    BYTE(self, 0x20FE) = 0;
    PTR(self, 0x20F8) = lbl_27_data_13730;
    *(Vec3Block*)(self + 0x2100) = block;

    fn_27_1D90FC(self);

    one.n = 1;
    char* module = PTR(PTR(self, 0x60), 0xD8);
    ((Object_vptr_0*)PTR(module, 0x7C))->slot3(self + 0x20C0, 0, &one.n, -1);
    another.n = 1;
    module = PTR(PTR(self, 0x60), 0xD8);
    ((Object_vptr_0*)PTR(module, 0x7C))->slot3(self + 0x20F8, 1, &another.n, -1);

    PTR(self, 0x3C) = lbl_27_data_8EB7C;
    PTR(self, 0x40) = lbl_27_data_8EB7C + 0x64;
    PTR(self, 0x48) = lbl_27_data_8EB7C + 0x70;
    PTR(self, 0x54) = lbl_27_data_8EB7C + 0x84;
    PTR(self, 0x64) = lbl_27_data_8EB7C + 0xDC;
    PTR(self, 0x70) = lbl_27_data_8EB7C + 0xEC;
    PTR(self, 0x7C) = lbl_27_data_8EB7C + 0x100;
    PTR(self, 0x88) = lbl_27_data_8EB7C + 0x118;
    PTR(self, 0x90) = lbl_27_data_8EB7C + 0x124;
    WORD(self, 0x213C) = argument[13];
    BYTE(self, 0x2144) = 0;
    WORD(self, 0x214C) = 0x24;
    WORD(self, 0x2150) = 0xF9F;
    WORD(self, 0x2154) = 0x5DBF;
    WORD(self, 0x2158) = 0;
    PTR(self, 0x2148) = lbl_27_data_8F054;
    PTR(self, 0x2140) = lbl_27_data_8F054 + 8;
    WORD(self, 0x215C) = argument[13] + 4;
    WORD(self, 0x2160) = argument[13] + 8;
    WORD(self, 0x2168) = argument[13];
    fn_27_1D8FC8(self, 0);
    return self;
}
