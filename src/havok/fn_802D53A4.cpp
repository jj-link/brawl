#pragma force_active on
struct Entry { unsigned char pad[0x18]; signed int count; unsigned char tail[0x14]; };
struct Object {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual void v17(); virtual void v18();
 virtual void* get(unsigned int, void*);
 unsigned char pad[0x2C]; unsigned int bits; Entry* entries; unsigned int count;
};
extern float lbl_8059EFC8;
extern "C" unsigned int fn_802D7260(void*, void*, void*, float);
extern "C" int __cntlzw(unsigned int);
extern "C" signed int fn_802D53A4(Object* self, unsigned int index) {
 __declspec(align(16)) unsigned char buffer[0x200];
 unsigned int next;
 unsigned int group = index >> (32 - self->bits);
 int item = (int)(index & (0xFFFFFFFFU >> self->bits));
 do {
  if (++item >= self->entries[group].count) {
   ++group;
   if (group >= self->count) return -1;
   item = 0;
  }
  next = (unsigned int)item | (group << (32 - self->bits));
  void* entry = self->get(next, buffer);
  unsigned int result = fn_802D7260((char*)entry + 0x10, (char*)entry + 0x20, (char*)entry + 0x30, lbl_8059EFC8);
  signed char sc = (signed char)((__cntlzw((unsigned int)(signed char)(result >> 24)) >> 5) & 0xFF);
  if (((unsigned int)(-sc | sc) >> 31) != 0) break;
 } while (true);
 return (signed int)next;
}