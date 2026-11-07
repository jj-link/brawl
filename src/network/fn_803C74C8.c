#pragma force_active on
extern void fn_803A9644(void*, void*, int);
typedef struct {
 unsigned char magic[4];
 unsigned short bom;
 unsigned char size[2];
 unsigned char value[4];
 unsigned short header;
 unsigned short zero;
 unsigned char type;
 unsigned char rest[15];
} Header;
void fn_803C74C8(void *dst, unsigned int value, unsigned int size, unsigned char type) {
 Header h;
 h.size[1] = size;
 h.value[3] = value;
 h.magic[0] = 0x56;
 h.magic[1] = 0x46;
 h.magic[2] = 0x46;
 h.magic[3] = 0x20;
 h.bom = 0xFEFF;
 h.size[0] = size >> 8;
 h.value[0] = value >> 24;
 h.value[1] = value >> 16;
 h.value[2] = value >> 8;
 h.header = 0x20;
 h.zero = 0;
 h.type = type;
 h.rest[0]=0; h.rest[1]=0; h.rest[2]=0; h.rest[3]=0; h.rest[4]=0;
 h.rest[5]=0; h.rest[6]=0; h.rest[7]=0; h.rest[8]=0; h.rest[9]=0;
 h.rest[10]=0; h.rest[11]=0; h.rest[12]=0; h.rest[13]=0; h.rest[14]=0;
 fn_803A9644(dst, &h, 0x20);
}