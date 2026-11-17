#pragma force_active on
#include <ft/fighter.h>

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);

extern char lbl_27_data_9D370[];
extern char lbl_27_data_9D1F8[];
extern char lbl_27_data_C938[];
extern char lbl_27_data_2C0C0[];
extern char lbl_27_data_CBA0[];
extern char lbl_27_data_69C0[];
extern char lbl_27_data_248[];

void fn_27_3A7A14(void*, int, int);
int fn_27_111364(ftOwner*);
void fn_27_3A963C(void*, int, int, int, float);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual int slot21(int);
};

struct Class_90D8_base {
    char pad[8];
};

class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void* fn_27_7B2EC();
};

struct Container {
    Class_90D8* first;
    char pad[8];
    Object_vptr_0* second;
};

struct Holder {
    char pad[0x28];
    int value;
};

struct Context {
    char pad0[8];
    Holder* holder;
    char pad1[0xCC];
    Container* inner;
};

static inline void buildArrow(
    void* obj, Context* context, int targetValue, float value)
{
    Fighter* source = (Fighter*)__dynamic_cast(
        context->holder, 0x3C, lbl_27_data_69C0, lbl_27_data_248, 1);
    int sourceValue = source->m_taskId;
    int id = fn_27_111364(source->getOwner());
    fn_27_3A963C(obj, sourceValue, targetValue, id, value);
}

extern "C" int fn_27_3A5A40(
    void*, Object_vptr_0* obj, Context* context)
{
    void* p;
    switch (obj->slot6()) {
    case 13: {
        p = __dynamic_cast(
            obj, 0, lbl_27_data_9D370, lbl_27_data_C938, 0);
        if (!p)
            break;

        Object_vptr_0* target = (Object_vptr_0*)__dynamic_cast(
            context->inner->first->fn_27_7B2EC(), 0,
            lbl_27_data_2C0C0, lbl_27_data_CBA0, 1);
        int targetValue = target->slot21(0x29);
        fn_27_3A7A14(p, context->holder->value, targetValue);
        return 1;
    }

    case 14: {
        void* cast14 = __dynamic_cast(
            obj, 0, lbl_27_data_9D1F8, lbl_27_data_C938, 0);
        if (!cast14)
            break;

        p = __dynamic_cast(
            context->inner->first->fn_27_7B2EC(), 0,
            lbl_27_data_2C0C0, lbl_27_data_CBA0, 1);
        Object_vptr_0* target = (Object_vptr_0*)p;
        buildArrow(
            cast14, context, target->slot21(0x29),
            context->inner->second->slot9());
        return 1;
    }

    default:
        break;
    }

    return 0;
}
