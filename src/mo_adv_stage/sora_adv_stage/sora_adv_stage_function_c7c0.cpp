#pragma force_active on
typedef unsigned long u32;

struct Count {
    u32 pad;
    u32 count;
};

struct Container {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void* get(u32);

    u32 pad;
    Count* data;
};

extern "C" {
Container* searchContainer__20stDataMultiContainerFUlUl(void*, u32, u32);
void fn_40_4828(void*, void*);

void fn_40_C7C0(void* arg1, u32 type, void* multi) {
    Container* container;
    u32 index = 0;
    u32 i;

    while ((container = searchContainer__20stDataMultiContainerFUlUl(
                multi, type, index++)) != 0) {
        for (i = 0; i < container->data->count; ++i) {
            fn_40_4828(arg1, container->get(i));
        }
    }
}
}
