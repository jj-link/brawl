#pragma force_active on
typedef unsigned int u32;

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_235E64(void* obj, void* sub, int arg);

class fn_27_Child {
public:
    u32 unk0;
    virtual void f0();
    virtual void f1(int flag);
};

class fn_27_Owner {
public:
    u32 pad0[6];
    fn_27_Child* m_child; // 0x18
};

extern "C" {
fn_27_Child* fn_27_233808(fn_27_Owner* self, int arg) {
    fn_27_Child* obj = (fn_27_Child*)__nw__FUlQ25Heaps8HeapType(0x40, 0xF);
    if (obj != 0) {
        obj = (fn_27_Child*)fn_27_235E64(obj, (char*)self + 0x2c, arg);
    }
    if (self->m_child && self->m_child) {
        self->m_child->f1(1);
    }
    self->m_child = obj;
    return obj;
}
}
