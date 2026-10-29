#pragma force_active on

struct Vec3f { float x, y, z; };

struct soAreaData {
    unsigned char shape, group;
    unsigned short flags;
    int a, b, node;
    float x, y, z, w;
};

template <class T>
struct soSet {
    T* m_elements;
    unsigned long m_size;
};

struct ykAreaData {
    int field;
    int unk;
    soSet<soAreaData>* areaSet;
};

struct LParam {
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
};

extern "C" {
extern LParam lbl_27_rodata_42D0;
void fn_27_2655F0(void*, unsigned long);
void* fn_27_2655FC(void*, unsigned int);
void* fn_27_26560C(void*);
void getPos__9grGimmickFv(void*, void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_265688(void*, LParam*);
void* fn_27_265C40(void*, LParam*);
void* fn_27_266418(void*, LParam*);
void* fn_27_266B9C(void*, LParam*);
void fn_27_264D9C(void*, void*);
}

struct grYakumono {
    void setAreaGimmick(soAreaData*, soSet<soAreaData>*, ykAreaData*, bool);
};

void grYakumono::setAreaGimmick(soAreaData* areaData, soSet<soAreaData>* areaInit, ykAreaData* data, bool unk4) {
    fn_27_2655F0(data, 0xc);
    areaInit->m_elements = areaData;
    areaInit->m_size = 1;
    data->areaSet = areaInit;
    LParam L = lbl_27_rodata_42D0;
    L.a = this;
    L.b = fn_27_26560C(fn_27_2655FC(this, 0));
    Vec3f pos;
    getPos__9grGimmickFv(&pos, this);
    L.e = data;
    L.d = &pos;
    void* obj;
    if (data->field == 0 && !unk4) {
        void* base = __nw__FUlQ25Heaps8HeapType(0x608, 0xf);
        obj = base ? fn_27_265688(base, &L) : base;
    } else if (!unk4) {
        void* base = __nw__FUlQ25Heaps8HeapType(0x854, 0xf);
        obj = base ? fn_27_265C40(base, &L) : base;
    } else if (data->field == 0) {
        void* base = __nw__FUlQ25Heaps8HeapType(0x7d0, 0xf);
        obj = base ? fn_27_266418(base, &L) : base;
    } else {
        void* base = __nw__FUlQ25Heaps8HeapType(0xa18, 0xf);
        obj = base ? fn_27_266B9C(base, &L) : base;
    }
    fn_27_264D9C(this, obj);
}
