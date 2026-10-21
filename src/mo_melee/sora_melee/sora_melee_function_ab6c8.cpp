#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

class IFlagList {
public:
    virtual void vf2();
    virtual u8* getAt(u32 index);
    virtual void vf4();
    virtual int size();
};

struct soOwner {
    u32 a;
    u32 b;
    u32 c;
    IFlagList* m_list;
};

struct soFlagByte {
    u8 top : 1;
    u8 rest : 7;
};

extern "C" void fn_27_AB6C8(soOwner* self) {
    int n = self->m_list->size();
    int i = 0;
    if (n > 0) {
        for (; i < n; i++) {
            soFlagByte* p = (soFlagByte*)self->m_list->getAt(i);
            p->top = 0;
        }
    }
}
