#pragma force_active on
typedef int s32;

struct MetaKnightWorkList {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual s32 find(s32 value) = 0;
    virtual void erase(s32 index, s32 value) = 0;
};

struct MetaKnightWorkContainer {
    char padding[0x64];
    MetaKnightWorkList* list;
};

struct MetaKnightObject {
    char padding[0xD8];
    MetaKnightWorkContainer* container;
};

extern "C" s32 fn_111_CF50(MetaKnightObject* object) {
    s32 value = 0x20000003;
    goto test;

loop:
    if (object->container->list->find(value) != -1) {
        s32 index = object->container->list->find(value);
        object->container->list->erase(-1, value);
        return index;
    }
    ++value;

test:
    if (value < 0x2000000A)
        goto loop;
    return -1;
}
