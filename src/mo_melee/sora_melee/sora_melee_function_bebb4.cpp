#pragma force_active on

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;

struct Module {
    u8 pad[0x80];
    void* object;
};

struct Owner {
    u8 pad[0xD8];
    Module* module;
};

struct Getter {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual s16 get();
};

struct Obs {
    virtual void addObserver(s16, s8);
    s16 m_manageID;
    s16 m_unitID;
    s16 m_sendID;
};

extern "C" u8 lbl_27_data_9A48[];
extern "C" u8 lbl_27_data_14F8[];
extern "C" u8 lbl_27_data_178A4[];
extern "C" void* __vt__21soStatusEventObserver[];
extern "C" void* __vt__22soAnimCmdEventObserver[];
extern "C" void* fn_27_C0F38(void* self);

extern "C" void* fn_27_BEBB4(void* self_in, Owner* owner, s32 arg2, s8 arg3, void* arg5) {
    u8* self = (u8*)self_in;

    self[4] = 0;
    *(void**)self = (void*)lbl_27_data_9A48;

    s16 id = ((Getter*)((u8*)owner->module->object + 8))->get();

    Obs* o1 = (Obs*)(self + 8);
    o1->m_manageID = -1;
    o1->m_unitID = 4;
    o1->m_sendID = -1;
    *(void**)o1 = __vt__21soStatusEventObserver;
    o1->addObserver(id, -1);

    id = ((Getter*)((u8*)owner->module->object + 8))->get();

    Obs* o2 = (Obs*)(self + 0x14);
    o2->m_manageID = -1;
    o2->m_unitID = 5;
    o2->m_sendID = -1;
    *(void**)o2 = __vt__22soAnimCmdEventObserver;
    o2->addObserver(id, -1);

    id = ((Getter*)((u8*)owner->module->object + 8))->get();

    Obs* o3 = (Obs*)(self + 0x20);
    o3->m_manageID = -1;
    o3->m_unitID = 9;
    o3->m_sendID = -1;
    *(void**)o3 = (void*)lbl_27_data_14F8;
    o3->addObserver(id, -1);

    *(void**)(self + 0x2C) = owner;

    *(void**)self = (void*)lbl_27_data_178A4;
    *(void**)(self + 8) = (void*)(lbl_27_data_178A4 + 0x5C);
    *(void**)(self + 0x14) = (void*)(lbl_27_data_178A4 + 0x6C);
    *(void**)(self + 0x20) = (void*)(lbl_27_data_178A4 + 0x80);

    fn_27_C0F38(self + 0x30);
    fn_27_C0F38(self + 0xB8);

    *(s32*)(self + 0x140) = arg2;
    *(s32*)(self + 0x144) = 0;
    self[0x148] = 0xFF;
    self[0x149] = 0x14;
    self[0x14E] = 1;
    self[0x14F] = 0;
    self[0x150] = 0;
    self[0x151] = (u8)arg3;

    return self_in;
}