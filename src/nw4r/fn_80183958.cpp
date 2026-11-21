#include <nw4r/ut/ut_LinkList.h>
#include <nw4r/ut/ut_RuntimeTypeInfo.h>
#pragma force_active on

typedef nw4r::ut::detail::RuntimeTypeInfo TypeInfo;

extern TypeInfo lbl_805A0518;

class Class_80465690;
typedef nw4r::ut::LinkList<Class_80465690, 4> ChildList;

class Class_80465690 {
public:
    virtual void fn_80182894();
    virtual TypeInfo* fn_80183620();

    char pad[12];
    ChildList children;
    char pad2[216];
    int value;
};

inline Class_80465690* castObj(Class_80465690* p, const TypeInfo* t) {
    if (p->fn_80183620()->IsDerivedFrom(t))
        return p;
    return 0;
}

extern "C" void fn_80183958(Class_80465690* obj, int value) {
    const TypeInfo* const rootTarget = &lbl_805A0518;
    Class_80465690* cast = castObj(obj, rootTarget);
    if (cast)
        cast->value = value;

    for (ChildList::Iterator it(obj->children.GetBeginIter()); it != obj->children.GetEndIter(); ++it) {
        const TypeInfo* childTarget = &lbl_805A0518;
        Class_80465690* child = it.operator->();
        cast = castObj(child, childTarget);
        if (cast)
            cast->value = value;

        for (ChildList::Iterator it2(child->children.GetBeginIter()); it2 != child->children.GetEndIter(); ++it2) {
            const TypeInfo* grandchildTarget = &lbl_805A0518;
            Class_80465690* grandchild = it2.operator->();
            cast = castObj(grandchild, grandchildTarget);
            if (cast)
                cast->value = value;

            ChildList::Iterator end3(grandchild->children.GetEndIter());
            for (ChildList::Iterator it3(grandchild->children.GetBeginIter()); it3 != end3; ++it3)
                fn_80183958(it3.operator->(), value);
        }
    }
}
