#pragma force_active on

struct TypeInfo {
    TypeInfo* parent;
};

extern int lbl_805A05A8;

struct Object {
    virtual TypeInfo* getType();
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual bool isActive();
    virtual void deactivate();

    char pad[0x1F0];
    void* owner;
};

extern "C" bool fn_801BD5E8(Object*);
extern "C" void fn_801BD604(Object*);

inline bool hasType(TypeInfo* info, const void* target) {
    while (info) {
        if (info == target)
            return true;
        info = info->parent;
    }
    return false;
}

inline Object* castObject(Object* obj) {
    const void* target = &lbl_805A05A8;
    TypeInfo* info = obj->getType();
    if (hasType(info, target))
        return obj;
    return 0;
}

extern "C" Object** fn_801C49C0(Object** self, Object** arg) {
    *self = 0;
    if (arg == 0)
        return self;

    Object* obj = *arg;
    if (obj == 0)
        return self;

    obj = castObject(obj);
    if (obj != 0) {
        *self = obj;
        if (fn_801BD5E8(obj))
            fn_801BD604(*self);
        if ((*self)->isActive())
            (*self)->deactivate();
        (*self)->owner = self;
    }
    return self;
}
