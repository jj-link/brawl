#pragma force_active on
#pragma use_lmw_stmw on
typedef unsigned char u8;
typedef unsigned short u16;
static inline u16 getTexel(u16 *source, unsigned long row, int column) {
 return source[(column & 3) + (((column >> 2) + row) * 16)];
}
static inline void unpackPixel(int pixel, u8 *red, u8 *green, u8 *blue) {
 *red=pixel>>8; *green=pixel>>3; *blue=pixel<<3;
 *red&=0xF8; *green&=0xFC; *blue&=0xF8;
}
int fn_8026EBE4(u8 *output, u8 *input, int x, int y) {
 u8 red;
 int chroma_stride;
 int stride;
 u16 *source;
 int tile_row;
 u16 *pixels;
 u8 *luma;
 u8 blue;
 u8 *cb;
 u8 *cr;
 int column;
 int width;
 int rowEndX;
 int rowEndY;
 int pitch;
 u16 pixel;
 luma=output+4;
 cb=output+0x84;
 cr=output+0xc4;
 pitch=*(unsigned long*)(input+0x48)>>2;
 width=16/input[0x2c];
 stride=16-width;
 rowEndX=x+width;
 chroma_stride=stride>>1;
 rowEndY=y+8/input[0x2c];
 pixels=*(u16**)(input+0x64);
 blue=0;
 for(;y<rowEndY;y++) {
  source=(u16*)((u8*)pixels+(y&3)*8);
  tile_row=(y>>2)*pitch;
  for(column=x;column<rowEndX;column+=2) {
   u8 green;
   pixel=getTexel(source,(unsigned long)tile_row,column);
   unpackPixel(pixel,&red,&green,&blue);
   *luma=(red*77+green*150+blue*29+128)>>8;
   *cb=((blue-*luma)*144+128)>>8;
   cb++;
   *cr=((red-*luma)*183+128)>>8;
   cr++;
   pixel=getTexel(source,(unsigned long)tile_row,column+1);
   unpackPixel(pixel,&red,&green,&blue);
   luma[1]=(red*77+green*150+blue*29+128)>>8;
   luma+=2;
  }
  luma+=stride;
  cb+=chroma_stride;
  cr+=chroma_stride;
 }
 return 0;
}
