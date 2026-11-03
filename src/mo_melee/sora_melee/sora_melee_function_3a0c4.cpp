#include <types.h>
#pragma force_active on

struct SoraElem {
    void* vtable;
    unsigned char pad[0x84];
    int field_88;
};

struct SoraChild {
    virtual void vf0();
    virtual SoraElem* vf3(int index);
    virtual void vf4();
    virtual int vf5();
};

struct SoraSelf {
    unsigned char pad0[0x30];
    SoraChild* m_child;
    unsigned char pad1[0x34];
    void* m_unk68;
};

extern "C" void fn_27_38988(SoraElem* p);
extern "C" void fn_27_362E4(void* p, int val);
extern "C" u32 fn_27_37BA8(void* p, int val);
extern "C" u32 fn_27_37C44(void* p, int val);
extern "C" void fn_27_37BDC(void* p, int val);
extern "C" void fn_27_36650(void* p, int val, int flag);

extern "C" void fn_27_3A0C4(SoraSelf* self, int index, int value) {
    SoraElem* elem = self->m_child->vf3(index);
    if (elem->vtable != 0) {
        elem = self->m_child->vf3(index);
        if (value == elem->field_88) {
            return;
        }
    }
    
    elem = self->m_child->vf3(index);
    fn_27_38988(elem);
    elem = self->m_child->vf3(index);
    elem->field_88 = value;
    fn_27_362E4(&self->m_unk68, value);
    
    int i;
    elem = self->m_child->vf3(index);
    int field = elem->field_88;
    
    if (fn_27_37BA8(&self->m_unk68, field) != 1 || fn_27_37C44(&self->m_unk68, field) != 1) {
        i = 0;
        while (i < self->m_child->vf5()) {
            SoraElem* e = self->m_child->vf3(i);
            if (e->vtable != 0 && i != index) {
                e = self->m_child->vf3(i);
                if (field == e->field_88) {
                    goto end_check;
                }
            }
            i++;
        }
        fn_27_36650(&self->m_unk68, field, 1);
    }
    
end_check:
    if (fn_27_37BA8(&self->m_unk68, value) == 1) {
        fn_27_37BDC(&self->m_unk68, value);
    }
}