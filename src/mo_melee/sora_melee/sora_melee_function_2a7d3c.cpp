#pragma force_active on
typedef int s32;

extern "C" void fn_27_2A7970(void* self, s32 item, s32 a, s32 b);

class ItemList {
public:
    virtual void v2();
    virtual s32* at(s32 index);
    virtual void v4();
    virtual s32 size();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void clear();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void remove(s32 index);
};

struct Mgr {
    char pad[0x6d8];
    ItemList m_list;
};

extern "C" void fn_27_2A7D3C(Mgr* self) {
    s32 i = 0;
    while (i < self->m_list.size()) {
        s32* p = self->m_list.at(i);
        if (*p != 0) {
            self->m_list.remove(i);
            fn_27_2A7970(self, *p, 0, 1);
            i--;
        }
        i++;
    }
    self->m_list.clear();
}
