#pragma force_active on
extern char lbl_80529CF8[];
extern int fn_803F6150(const void *, const void *, unsigned long);
extern int fn_8023B8DC(void *, int);
static inline unsigned char *find_entry(const void *arg0, int i) {
 unsigned char *p = (unsigned char *)lbl_80529CF8 + 0x1F30;
 while (i < 16) {
  if ((p[0x76] & 0x80) && fn_803F6150(p + 0x1C, arg0, 6) == 0) return p;
  i++;
  p += 0x88;
 }
 return 0;
}
int fn_80239DCC(void *arg0) {
 unsigned char *p = find_entry(arg0, 0);
 if (p == 0) return 0;
 p[0x76] = 0;
 fn_8023B8DC(arg0, 0);
 return 1;
}
