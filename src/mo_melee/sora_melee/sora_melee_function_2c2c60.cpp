#pragma force_active on
typedef unsigned long u32;

enum ARCNodeType { Data_Type_Misc = 0 };

struct Holder {
    u32 m_0;
    u32 m_4;
};

extern "C" void* getManager__11soArchiveDbFUl(u32);
extern "C" int fn_80045DC0(void* manager, u32 id, u32 flag);
extern "C" void* getResFileFromId__16utArchiveManagerFl11ARCNodeTypeUlUlUl(
    void*, long, ARCNodeType, u32, u32, u32);

extern "C" void* fn_27_2C2C60(const Holder* self, u32 index) {
    const u32& id = self->m_4;
    if (id == 0xFFFF) {
        return 0;
    }
    if (fn_80045DC0(getManager__11soArchiveDbFUl(2), id, 0) != 1) {
        return 0;
    }
    return getResFileFromId__16utArchiveManagerFl11ARCNodeTypeUlUlUl(
        getManager__11soArchiveDbFUl(2), (long)id, (ARCNodeType)3, index, 0, -1);
}
