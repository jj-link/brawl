#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* memset(void*, int, unsigned long);
extern "C" const float lbl_27_rodata_4520;
extern "C" const float lbl_27_rodata_4524;

struct grMadeinOverwrite {
    char pad0[0x10];
    float unk10;
    char pad14[0x10];
    float unk24;
    float unk28;
    float unk2C;
    char pad30[0x8];
    unsigned int unk38;
};

class grMadein {
public:
    void* getOverwriteAttackData();

    char m_pad0[0x70];
    int m_heapType;
    char m_pad1[0xF0];
    grMadeinOverwrite* m_overwrite;
};

void* grMadein::getOverwriteAttackData() {
    if (m_overwrite == 0) {
        grMadeinOverwrite* obj = (grMadeinOverwrite*)__nw__FUlQ25Heaps8HeapType(0x40, m_heapType);
        if (obj) {
            obj->unk24 = lbl_27_rodata_4524;
            obj->unk28 = lbl_27_rodata_4524;
            obj->unk2C = lbl_27_rodata_4524;
            obj->unk38 = (obj->unk38 >> 5) << 5;
        }
        m_overwrite = obj;
        memset(obj, 0, 0x40);
        obj->unk24 = lbl_27_rodata_4524;
        obj->unk28 = lbl_27_rodata_4524;
        obj->unk2C = lbl_27_rodata_4524;
        unsigned int flags = (obj->unk38 >> 5) << 5;
        obj->unk10 = lbl_27_rodata_4520;
        flags = flags & 0xFFFFFDFFu;
        obj->unk38 = flags | 0x8000u;
    }
    return m_overwrite;
}
