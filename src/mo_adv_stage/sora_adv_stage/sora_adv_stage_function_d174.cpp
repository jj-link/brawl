#pragma force_active on
#include <st/st_data_container.h>
#include <st/st_trigger.h>

class Class_5648 {
public:
    virtual void fn_40_215A4();
    virtual void fn_40_20A6C();
    virtual void fn_40_20A7C();
    virtual stDataContainerData* fn_40_1E5E0(u32);
};
class Class_6C68 {
public:
    virtual void fn_40_215A4();
    virtual void fn_40_20A6C();
    virtual void fn_40_20A7C();
    virtual stDataContainerData* fn_40_24BA4(u32);
};
class Class_83C8 {
public:
    virtual void fn_40_295F8();
    virtual void fn_40_28A18();
    virtual void fn_40_28A28();
    virtual stDataContainerData* fn_40_28908(u32);
};
class Class_CEC8 {
public:
    virtual void fn_40_215A4();
    virtual void fn_40_20A6C();
    virtual void fn_40_20A7C();
    virtual stDataContainerData* fn_40_30C08(u32);
};
class Class_D270 {
public:
    virtual void fn_40_295F8();
    virtual void fn_40_28A18();
    virtual void fn_40_28A28();
    virtual stDataContainerData* fn_40_30D68(u32);
};

struct Callback {
    u32 field0;
    void* vtable;
    u32 kind;
    void* owner;
    stDataContainerData* data;
    unsigned char flag;
    float value;
    u32 field1C;
};

extern "C" {
extern char lbl_40_data_22D8[];
extern const float lbl_40_rodata_2C[];
void fn_27_233F58(stTrigger*, void*);

void fn_40_D174(void* owner, u32 kind, stDataMultiContainer* multi) {
    stDataContainerData* data;
    stTrigger* trigger;
    stDataContainer* container;
    u32 n = 0;
    u32 i;
    while ((container = multi->searchContainer(kind, n++)) != 0) {
        for (i = 0; i < container->m_filedata->m_numFiles; i++) {
            data = container->getData(i);
            trigger = g_stTriggerMng->createTrigger(
                (Gimmick::AreaKind)0x18,
                (stTriggerData*)((char*)data + 8));
            Callback* cb = (Callback*)operator new(0x20, Heaps::StageInstance);
            if (cb) {
                cb->field0 = 0;
                cb->kind = 0x18;
                cb->vtable = lbl_40_data_22D8;
                cb->owner = owner;
                cb->data = data;
                cb->flag = 0;
                cb->value = lbl_40_rodata_2C[0];
            }
            fn_27_233F58(trigger, cb);
        }
    }
}
}
