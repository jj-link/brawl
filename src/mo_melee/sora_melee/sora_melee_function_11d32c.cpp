#include <types.h>
#include <ft/ft_slot_manager.h>
#pragma force_active on

extern "C" u32 fn_27_1444C4(u32,u32,u32,u32,u32,u32,u32,u32,u32);
extern "C" u32 lbl_27_bss_31F8;

struct Class90D8Entry { u32 f00, f04, f08, f0c; };
class Class_90D8 {
public:
    virtual void fn_27_7B274();
    virtual Class90D8Entry* fn_27_7AC18(int);
    virtual void fn_27_7AC28();
    virtual int fn_27_7AB50();
};
struct ManagerView { u8* slots; s32 slotCount; Class_90D8 arr; };

struct Slot { u32 value, flags; u8 padding[0x48]; u16 status; u16 pad52; };
struct Entry {
    u32 f00, f04;
    Slot slots[4];
    u8 f158,f159,f15a,f15b,f15c,f15d,f15e,f15f;
    s32 f160;
    u32 f164,f168,f16c,f170,f174;
};

static inline u32 find90D8_f04(s32 target) {
    ManagerView* manager=(ManagerView*)g_ftSlotManager;
    s32 count=manager->arr.fn_27_7AB50();
    for(s32 i=0;i<count;++i) {
        Class90D8Entry* entry=manager->arr.fn_27_7AC18(i);
        if((s32)entry->f0c==target) return entry->f04;
    }
    return 0xff;
}
static inline u32 find90D8_f00(s32 argument) {
    s32 i;
    s32 target=argument;
    ManagerView* manager=(ManagerView*)g_ftSlotManager;
    s32 count=manager->arr.fn_27_7AB50();
    for(i=0;i<count;++i) {
        Class90D8Entry* entry=manager->arr.fn_27_7AC18(i);
        if((s32)entry->f0c==target) return entry->f00;
    }
    return 0xff;
}
static inline u32 getSlotValue(Entry* self,u32 idx) { return *(u32*)((u8*)self+(s32)(idx*0x54)+8); }
static inline u32 getSlotFlags(Entry* self,u32 idx) { return *(u32*)((u8*)self+idx*0x54+12); }
static inline void setSlotFlags(Entry* self,u32 idx,u32 value) { *(u32*)((u8*)self+12+(s32)(idx*0x54))=value; }

extern "C" void fn_27_11D32C(Entry* self,u32 arg1,u32 mask,u32 arg3) {
    if(self->f15f!=1) {
        u32 acc;
        acc=getSlotFlags(self,arg1);
        mask &= ~acc;
        if(mask!=0) {
            if((u8)mask&1) {
                u32 found=find90D8_f04(self->f170);
                acc|=fn_27_1444C4(lbl_27_bss_31F8,getSlotValue(self,arg1),self->f174,self->f174,mask&1,self->f15b,found,self->f16c,arg3);
            }
            if((s32)mask&0x12) {
                u32 found=find90D8_f00(self->f170);
                acc|=fn_27_1444C4(lbl_27_bss_31F8,getSlotValue(self,arg1),self->f174,self->f174,mask&0x12,self->f15b,found,self->f168,arg3);
            }
            u32 inRange=0;
            if(self->f160>=0x2e && self->f160<=0x31) inRange=1;
            u32 flag=((1-inRange)|(inRange-1))>>31;
            acc|=fn_27_1444C4(lbl_27_bss_31F8,getSlotValue(self,arg1),self->f174,self->f174,mask&~0x13u,self->f15b,self->f168,self->f168,flag);
            self->f04=1;
        }
        setSlotFlags(self,arg1,acc);
    }
}
