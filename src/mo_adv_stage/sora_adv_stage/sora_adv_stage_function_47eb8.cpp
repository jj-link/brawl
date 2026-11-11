#include <gf/gf_task.h>
#include <gf/gf_heap_manager.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_obj.h>
#include <string.h>
#include <stdio.h>

#pragma force_active on

extern "C" {
extern char lbl_40_data_18480[];
extern char lbl_40_data_184C4[];
extern char lbl_40_data_18454[];
extern char lbl_40_data_18450[];
extern char lbl_40_data_18490[];
extern float lbl_40_rodata_B60;
extern float lbl_40_rodata_B64;
extern void* g_IfAdvMngr;
extern int* lbl_805A0348;
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void fn_800B96E8(void*, int);
void* fn_801AB6CC(void*, void*, int);
void fn_80107E5C(void*);
int fn_8010EC6C(int*);
int fn_8010ECB8(int);
}
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(float);
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(int, int);
};
struct DelBase { char pad[0x5c]; };
class DelObject : public DelBase {
public:
    virtual void destroy(int);
};
struct Name { char text[65]; };
struct Arguments { int value[7]; };
struct ResTemp { int value; };
extern "C" void* fn_40_47EB8(char* p, const Arguments* a) {
    Name n12, n11, n10, n9, n8, n7, n6, n5, n4, n3, n2, n1;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(p, lbl_40_data_18480, 8, 15, 8, true);
    *(char**)(p + 0x3c) = lbl_40_data_184C4;
    *(int*)(p + 0x40) = 0x40;
    *(int*)(p + 0x44) = 0;
    *(int*)(p + 0x48) = a->value[3];
    *(int*)(p + 0x4c) = 0;
    *(int*)(p + 0x50) = 0;
    fn_800B96E8(p + 0x150, 0xff);

    *(int*)(p + 0x1fc) = 0;
    *(int*)(p + 0x200) = 0;
    *(Arguments*)(p + 0x204) = *a;
    *(int*)(p + 0x220) = 0;
    *(void**)(p + 0x224) = 0;
    *(void**)(p + 0x228) = 0;
    ((gfTask*)p)->unk2C_b1 = false;
    fn_800B96E8(p + 0x150, (unsigned char)*(int*)(p + 0x48));
    void* files = *(void**)((char*)g_IfAdvMngr + 0x78);
    void* allocator = gfHeapManager::getMEMAllocator((Heaps::HeapType)0x2a);
    void* mdl = fn_801AB6CC(allocator, 0, 0x10);
    if (*(void**)(p + 0x228))
        ((nw4r::g3d::G3dObj*)*(void**)(p + 0x228))->Destroy();
    *(void**)(p + 0x228) = mdl;
    fn_80107E5C(g_IfAdvMngr);
    int selected = fn_8010EC6C(lbl_805A0348) == 2;
    ResTemp res;
    res.value = *(int*)files;
    MuObject* obj = MuObject::create((nw4r::g3d::ResFile*)&res, lbl_40_data_18490,
        *(int*)(p + 0x40), 0, (Heaps::HeapType)0x2a);
    MuObject* old = *(MuObject**)(p + 0x224);
    if (old != obj) {
        if (old)
            ((DelObject*)old)->destroy(1);
        *(MuObject**)(p + 0x224) = obj;
    }
    Object_vptr_0* scene = *(Object_vptr_0**)(p + 0x228);
    MuObject* current = *(MuObject**)(p + 0x224);
    scene->slot11(*(int*)((char*)scene + 0xe4), *(int*)((char*)current + 0x10));
    obj = *(MuObject**)(p + 0x224);
    char* model = *(char**)((char*)obj + 8);
    int off = *(int*)(model + 0x3c);
    const char* source = off ? model + off : 0;
    n1.text[0] = 0;
    strcat(n1.text, source);
    n2 = n1;
    strcat(n2.text, lbl_40_data_18454);
    n3 = n2;
    selected = selected != 0;
    sprintf(n3.text + strlen(n3.text), lbl_40_data_18450, selected);
    n4 = n3;
    obj->changeNodeAnimNIf(n4.text);
    MuObject* clrObj = *(MuObject**)(p + 0x224);
    model = *(char**)((char*)clrObj + 8);
    off = *(int*)(model + 0x3c);
    source = off ? model + off : 0;
    n5.text[0] = 0;
    strcat(n5.text, source);
    n6 = n5;
    strcat(n6.text, lbl_40_data_18454);
    n7 = n6;
    sprintf(n7.text + strlen(n7.text), lbl_40_data_18450, 2);
    n8 = n7;
    clrObj->changeClrAnimNIf(n8.text);
    MuObject* visObj = *(MuObject**)(p + 0x224);
    model = *(char**)((char*)visObj + 8);
    off = *(int*)(model + 0x3c);
    source = off ? model + off : 0;
    n9.text[0] = 0;
    strcat(n9.text, source);
    n10 = n9;
    strcat(n10.text, lbl_40_data_18454);
    n11 = n10;
    sprintf(n11.text + strlen(n11.text), lbl_40_data_18450, 0);
    n12 = n11;
    visObj->changeVisAnimNIf(n12.text);
    obj = *(MuObject**)(p + 0x224);
    ((Object_vptr_0*)*(void**)((char*)obj->m_modelAnim + 8))->slot8(lbl_40_rodata_B60);
    obj = *(MuObject**)(p + 0x224);
    ((Object_vptr_0*)*(void**)((char*)obj->m_modelAnim + 12))->slot8(lbl_40_rodata_B64);
    *(int*)(p + 0x58) = 6;
    *(int*)(p + 0x5c) = 5;
    *(int*)(p + 0x60) = 7;
    *(int*)(p + 0x64) = 7;
    *(int*)(p + 0x68) = 7;
    *(int*)(p + 0x6c) = 7;
    *(int*)(p + 0x70) = 1;
    *(int*)(p + 0x74) = 7;
    *(int*)(p + 0x7c) = 5;
    *(int*)(p + 0x80) = 6;
    *(int*)(p + 0x84) = 7;
    *(int*)(p + 0x88) = 7;
    *(int*)(p + 0x8c) = 0;
    *(int*)(p + 0x90) = 7;
    *(int*)(p + 0x94) = 2;
    *(int*)(p + 0x98) = 7;
    *(int*)(p + 0xa0) = 5;
    *(int*)(p + 0xa4) = 6;
    *(int*)(p + 0xa8) = 7;
    *(int*)(p + 0xac) = 7;
    *(int*)(p + 0xb0) = 1;
    *(int*)(p + 0xb4) = 7;
    *(int*)(p + 0xb8) = 7;
    *(int*)(p + 0xbc) = 7;
    *(int*)(p + 0xc4) = 7;
    *(int*)(p + 0xc8) = 7;
    *(int*)(p + 0xcc) = 6;
    *(int*)(p + 0xd0) = 5;
    *(int*)(p + 0xd4) = 7;
    *(int*)(p + 0xd8) = 7;
    *(int*)(p + 0xdc) = 4;
    *(int*)(p + 0xe0) = 5;
    *(int*)(p + 0xe8) = 7;
    *(int*)(p + 0xec) = 7;
    *(int*)(p + 0xf0) = 5;
    *(int*)(p + 0xf4) = 6;
    *(int*)(p + 0xf8) = 3;
    *(int*)(p + 0xfc) = 6;
    *(int*)(p + 0x100) = 7;
    *(int*)(p + 0x104) = 7;
    *(int*)(p + 0x10c) = 4;
    *(int*)(p + 0x110) = 3;
    *(int*)(p + 0x114) = 1;
    *(int*)(p + 0x118) = 2;
    *(int*)(p + 0x11c) = 6;
    *(int*)(p + 0x120) = 3;
    *(int*)(p + 0x124) = 7;
    *(int*)(p + 0x128) = 7;
    *(int*)(p + 0x130) = 3;
    *(int*)(p + 0x134) = 4;
    *(int*)(p + 0x138) = 0;
    *(int*)(p + 0x13c) = 1;
    *(int*)(p + 0x140) = 7;
    *(int*)(p + 0x144) = 7;
    *(int*)(p + 0x148) = 5;
    *(int*)(p + 0x14c) = 4;
    if (fn_8010EC6C(lbl_805A0348) == 2) {
        p[0x54] = 1;
        p[0x78] = 1;
        p[0x9c] = 1;
        p[0xc0] = fn_8010ECB8(1);
        p[0xe4] = fn_8010ECB8(2);
        p[0x108] = fn_8010ECB8(3);
        p[0x12c] = fn_8010ECB8(4);
    } else {
        p[0x54] = 1;
        p[0x78] = 1;
        p[0x9c] = 0;
        p[0xc0] = 0;
        p[0xe4] = 0;
        p[0x108] = 0;
        p[0x12c] = 0;
    }
    *(int*)(p + 0x50) = 0;
    ((MuObject*)*(void**)(p + 0x224))->setFrameVisible((float)*(int*)(p + 0x50));
    return p;
}
