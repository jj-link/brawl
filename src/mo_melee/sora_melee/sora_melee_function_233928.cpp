#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_236600(void*, void*, void*);

struct grGimmickWaterData;

class stWaterObj {
public:
    int m_unk0;
    virtual void v0();
    virtual void v1(int);
};

class stTrigger {
public:
    void* setWaterTrigger(grGimmickWaterData* data);
    char m_pad[0x18];
    stWaterObj* m_obj;
};

void* stTrigger::setWaterTrigger(grGimmickWaterData* data) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x40, 0x0F);
    if (obj != 0) {
        obj = fn_27_236600(obj, (char*)this + 0x2C, data);
    }
    if (m_obj != 0 && m_obj != 0) {
        m_obj->v1(1);
    }
    m_obj = (stWaterObj*)obj;
    return obj;
}
