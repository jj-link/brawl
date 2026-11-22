#include <nw4r/ut/ut_LinkList.h>
#include <nw4r/ut/ut_RuntimeTypeInfo.h>
#pragma force_active on

typedef nw4r::ut::detail::RuntimeTypeInfo TypeInfo;
extern TypeInfo lbl_805A0518;

class Class_80465708;
typedef nw4r::ut::LinkList<Class_80465708, 4> ChildList;

class Class_80465708 {
public:
    virtual void fn_80183B38();
    virtual TypeInfo* fn_80183C54();

    char pad[12];
    ChildList children;
    char pad2[216];
    int value;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
};

struct Owner {
    char pad[16];
    Class_80465708* obj;
};

inline Class_80465708* castObj(Class_80465708* p, const TypeInfo* t) {
    if (p->fn_80183C54()->IsDerivedFrom(t))
        return p;
    return 0;
}

extern "C" void fn_80183958(Class_80465708*, int);

extern "C" void fn_8018421C(Owner* self, int value) {
    Class_80465708* obj = self->obj;
            const TypeInfo* grandchildTarget;
        const TypeInfo* childTarget;
    {
        const TypeInfo* const rootTarget = &lbl_805A0518;
        Class_80465708* cast = castObj(obj, rootTarget);
        if (cast)
            cast->value = value;
    }

    Class_80465708* cast;
    for (ChildList::Iterator it(obj->children.GetBeginIter()); it != obj->children.GetEndIter(); ++it) {
        childTarget = &lbl_805A0518;
        Class_80465708* child = it.operator->();
        cast = castObj(child, childTarget);
        if (cast)
            cast->value = value;

        for (ChildList::Iterator it2(child->children.GetBeginIter()); it2 != child->children.GetEndIter(); ++it2) {
            grandchildTarget = &lbl_805A0518;
            Class_80465708* grandchild = it2.operator->();
            cast = castObj(grandchild, grandchildTarget);
            if (cast)
                cast->value = value;

            ChildList::Iterator end3(grandchild->children.GetEndIter());
            for (ChildList::Iterator it3(grandchild->children.GetBeginIter()); it3 != end3; ++it3)
                fn_80183958(it3.operator->(), value);
        }
    }
}
