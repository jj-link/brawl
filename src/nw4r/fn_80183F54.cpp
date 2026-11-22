#include <types.h>
#include <nw4r/ut/ut_LinkList.h>
#pragma force_active on

extern "C" int fn_8018C140(u8*);
extern "C" void* fn_80204E5C(void*, int);
extern "C" void* fn_8018B3C0(void*);
extern void* lbl_805A0508;

class Class_80465708 {
public:
    virtual void fn_80183B38();
    virtual void fn_80183C54(void*, int);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
};

class List : public nw4r::ut::detail::LinkListImpl {
public:
    using LinkListImpl::Insert;
    using LinkListImpl::GetEndIter;
};

struct Manager {
    void* vtable;
    List list;
};
inline void insert(Manager* manager, void* obj) {
    manager->list.Insert(
        manager->list.GetEndIter(),
        (nw4r::ut::LinkListNode*)((char*)obj + 4));
}

extern "C" void* fn_80183F54(Manager* list, int archive, int arg2) {
    u8* data = (u8*)archive;
    archive = arg2;
    if (fn_8018C140(data) == 0) return 0;
    u8* entry;
    void* result;
    result = 0;
    entry = data + *(u16*)(data + 0xC);
    for (arg2 = 0; arg2 < *(u16*)(data + 0xE); arg2++) {
        switch (*(int*)entry) {
        case 0x70616931:
            switch (*(int*)data) {
            case 0x524C5450:
            case 0x524C4D43:
            case 0x524C414E:
            case 0x524C5041:
            case 0x524C5643:
            case 0x524C5453:
            case 0x524C5649:
                void* mem = fn_80204E5C(lbl_805A0508, 0x20);
                Class_80465708* obj;
                if (mem) {
                    obj = (Class_80465708*)mem;
                    if (mem) obj = (Class_80465708*)fn_8018B3C0(mem);
                } else {
                    obj = 0;
                }
                if (obj) {
                    obj->fn_80183C54(entry, archive);
                    result = obj;
                }
                break;
            }
            if (result) insert(list, result);
            break;
        }
        entry += *(u32*)(entry + 4);
    }
    return result;
}