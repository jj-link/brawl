#pragma force_active on
typedef unsigned long u32;

enum ARCNodeType { Data_Type_Misc = 0 };

struct ArchiveHolder {
    unsigned char pad[0x14];
    u32 archiveId;
};

extern "C" void* getManager__11soArchiveDbFUl(u32);
extern "C" void* getResFileFromId__16utArchiveManagerFl11ARCNodeTypeUlUlUl(
    void*, long, ARCNodeType, u32, u32, u32);

extern "C" void* fn_27_2B26E8(const ArchiveHolder* self, ARCNodeType type, u32 index, u32 group) {
    const u32& id = self->archiveId;
    if (id != 0xFFFF) {
        return getResFileFromId__16utArchiveManagerFl11ARCNodeTypeUlUlUl(
            getManager__11soArchiveDbFUl(2), id, type, index, group, -1);
    }
    return 0;
}
