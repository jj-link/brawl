#include <types.h>
#include <nw4r/g3d/g3d_resmdl.h>

#pragma force_active on

extern "C" u32 GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(void*);
extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(const void*, u32);

class VisHandler {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual int getVis(u32 index);
    char pad[0x10];
    u16* visData;
};

extern "C" void fn_80197A40(void* mdl, VisHandler* handler) {
    u32 count = GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(mdl);
    u32 offset;
    u32 i;

    i = 0;
    offset = 0;
    while (i < count) {
        u16 flags = *(u16*)((char*)handler->visData + offset);
        if (!(flags & 0xC000)) {
            void* node = GetResNode__Q34nw4r3g3d6ResMdlCFUl(mdl, i);
            int visible = handler->getVis(i);
            if (node != 0) {
                u32* nodeFlags = (u32*)((char*)node + 0x14);
                if (visible != 0) {
                    *nodeFlags |= 0x100;
                } else {
                    *nodeFlags &= ~0x100;
                }
            }
        }
        offset += 2;
        i++;
    }
}
