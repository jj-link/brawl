#include <types.h>
#pragma force_active on

extern int lbl_805A0528;
extern "C" void* fn_8015C1EC(void*, u16);

struct TypeInfo {
    TypeInfo* parent;
};

class Object {
public:
    virtual void v00();
    virtual TypeInfo* getType();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
};

class Handler {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(int);
};

struct Entry {
    Object* obj;
    Handler* handler;
};

struct Owner {
    char pad[0x10];
    u16 count;
    char pad2[6];
    char data[1];
};

inline bool hasType(TypeInfo* info, const void* target) {
    while (info) {
        if (info == target)
            return true;
        info = info->parent;
    }
    return false;
}

inline Object* castObject(Object* obj, const void* target) {
    TypeInfo* info = obj->getType();
    if (hasType(info, target))
        return obj;
    return 0;
}

extern "C" void fn_80279C1C(Owner* self, int arg1) {
    const void* target;
    unsigned int i = 0;
    target = &lbl_805A0528;
    for (; i < self->count; i++) {
        Entry* entry = (Entry*)fn_8015C1EC(self->data, (u16)i);
        Object* obj = castObject(entry->obj, target);
        if (obj != 0)
            entry->handler->v18(arg1);
    }
}
