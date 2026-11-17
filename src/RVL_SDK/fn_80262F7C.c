#include <types.h>
#pragma force_active on
typedef struct {
u16 width,height; u8 pad4[9]; u8 tileWidth,tileHeight,padF;
u16 tilesAcross,tilesDown; s32 tileCount;
u8 remainderX,remainderY,pad1A,levelCount,levelSizes[4];
u8 f20,pad21[3],f24,pad25[3],tileSizeX,tileSizeY;
} ImageInfo;
#pragma opt_strength_reduction off
static inline void levels(void *arg0, ImageInfo *info) {
s32 i;
for(i=0;i<info->levelCount;i++) {
s32 v;
u8 index=((u8*)arg0)[i+0x18];
if(info->levelCount==1) v=1;
else v=((u8*)info)[0x20+index]*((u8*)info)[0x24+index];
info->levelSizes[i]=v;
}
for(;i<4;i++) info->levelSizes[i]=0;
}
s32 fn_80262F7C(void *arg0) {
ImageInfo *info;
((u8*)arg0)[0x17E8]|=0x100;
info=(ImageInfo*)((u8*)arg0+0x17DC);
if(((u8*)arg0)[0x17F7]==1) {
u8 tileHeight;
info->tileWidth=(u8)(((s32)info->tileSizeX*8)/((u8*)info+((u8*)arg0)[0x18])[0x20]);
tileHeight=(u8)(((s32)info->tileSizeY*8)/((u8*)info+((u8*)arg0)[0x18])[0x24]);
info->tilesAcross=(u16)(info->width/info->tileWidth);
info->tileHeight=tileHeight;
info->tilesDown=(u16)(info->height/info->tileHeight);
} else {
info->tileWidth=(u8)((info->tileSizeX*8)&0xF8);
info->tileHeight=(u8)((info->tileSizeY*8)&0xF8);
info->tilesAcross=(u16)(info->width/info->tileWidth);
info->tilesDown=(u16)(info->height/info->tileHeight);
}
info->remainderX=(u8)(info->width%info->tileWidth);
info->remainderY=(u8)(info->height%info->tileHeight);
info->tilesAcross+=info->remainderX!=0;
info->tilesDown+=info->remainderY!=0;
info->tileCount=info->tilesAcross*info->tilesDown;
levels(arg0,info);
return 0;
}
