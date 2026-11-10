#pragma use_lmw_stmw on
#include <types.h>
#include <stl/internal/mem.h>
#pragma force_active on
typedef struct {
 u8 pad0[0x22]; u8 countX, countY;
 unsigned long offsetX, offsetY; u8 tileSize;
 u8 pad2d[0x48-0x2d]; unsigned long pitch;
 u8 pad4c[0x64-0x4c]; u16 *pixels;
} Input;
static inline void unpack(u16 *source, unsigned long row, int column, u8 *red, u8 *green, u8 *blue) {
 unsigned long index = (column >> 2) * 2 - (-row);
 u16 pixel2 = source[(column & 3) + ((index + 1) * 16)];
 u16 pixel1 = source[(column & 3) + (index * 16)];
 *green = pixel2 >> 8; *blue = pixel2; *red = pixel1;
}
int fn_8026E4AC(u8 *output, Input *input, int x, int y) {
 u8 *luma=output+4; u8 *cb=output+0x84; u8 *cr=output+0xc4;
 int row;
 u16 *pixels=input->pixels;
 u16 *source;
 u8 red;
 int column,width,rowEndX,rowEndY,height,i;
 int pitch=(input->pitch>>1)&0x7ffffffe;
 if(input->offsetX==(unsigned long)x) width=input->countX;
 else width=16/input->tileSize;
 if(input->offsetY==(unsigned long)y) height=input->countY;
 else height=8/input->tileSize;
 rowEndX=x+width; rowEndY=y+height;
 for(;y<rowEndY;y++){
 source=(u16 *)((u8 *)pixels+((y&3)*8));
 row=(y>>2)*pitch;
 for(column=x;column<rowEndX;column++){
 u8 green,blue;
 unpack(source,row,column,&red,&green,&blue);
 *luma=(u8)((red*77+green*150+blue*29+128)>>8);
 if((column&1)==0){
 *cb=(u8)(((blue-*luma)*144+128)>>8); cb++;
 *cr=(u8)(((red-*luma)*183+128)>>8); cr++;
 }
 luma++;
 }
 for(i=width;i<16;i++){
 *luma=luma[-1];luma++;
 if((i&1)==0){*cb=cb[-1];cb++;*cr=cr[-1];cr++;}
 }
 }
 for(;height<8;height++){
 memcpy(luma,luma-16,16);luma+=16;
 memcpy(cb,cb-8,8);memcpy(cr,cr-8,8);cb+=8;cr+=8;
 }
 return 0;
}