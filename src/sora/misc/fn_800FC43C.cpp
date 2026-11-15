#include <types.h>
#include <gf/gf_file_io_handle.h>
#include <gm/gm_global.h>
#include <nw4r/g3d/g3d_resfile.h>
#pragma force_active on
struct FileHolder { u8 flags; u8 pad[7]; void* res8; void* resC; void* res10; u8 pad14[0x34]; void* p48; void* p4C; u8 pad50[4]; gfFileIOHandle h54,h58,h5c,h60,h64; };
extern "C" { void fn_800FC43C(FileHolder*, int); }
#pragma push
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_800FC43C(FileHolder* self, int arg1) {
    u32 sp10, spC;
    self->h54.read("/info/info_wifi_practice.brres", (HeapType)9, arg1);
    self->h58.read("/info/cmnwindow/wifi_notice_wnd.brres", (HeapType)9, arg1);
    u8* rec = (u8*)g_GameGlobal->getGlobalRecordMenuDatap();
    gfFileIOHandle* h5c = &self->h5c;
    const char* name = ((rec[0x28] >> 7) & 1) ? "/info/defaultcamera/InfoWide.brres" : "/info/defaultcamera/Info.brres";
    h5c->read(name, (HeapType)9, arg1);
    self->h60.read("/menu/msg/wifipr_info.msbin", (HeapType)9, arg1);
    self->h64.read("/menu/msg/wifi_common.msbin", (HeapType)9, arg1);
    if (arg1 == 0) {
        u32 sp8 = 0, r31;
        if(self->h54.getReturnStatus()==0x15) r31=0;
        else {r31=(u32)self->h54.getBuffer();self->h54.release();}
        if(r31){sp8=r31;nw4r::g3d::ResFile::Init(&sp8);} self->res8=(void*)sp8;
        spC=0;
        if(self->h58.getReturnStatus()==0x15)r31=0;
        else{r31=(u32)self->h58.getBuffer();self->h58.release();}
        if(r31){spC=r31;nw4r::g3d::ResFile::Init(&spC);} self->resC=(void*)spC;
        sp10=0;
        if(self->h5c.getReturnStatus()==0x15)r31=0;
        else{r31=(u32)self->h5c.getBuffer();self->h5c.release();}
        if(r31){sp10=r31;nw4r::g3d::ResFile::Init(&sp10);} self->res10=(void*)sp10;
        if(self->h60.getReturnStatus()==0x15)r31=0;
        else{r31=(u32)self->h60.getBuffer();self->h60.release();} self->p48=(void*)r31;
        if(self->h64.getReturnStatus()==0x15)r31=0;
        else{r31=(u32)self->h64.getBuffer();self->h64.release();} self->p4C=(void*)r31;
        self->flags|=0x80;
    }
}
#pragma pop
