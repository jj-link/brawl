#pragma force_active on
struct Vec { float x,y,z; };
struct Object { Vec a,b,c,d; unsigned char e,f; };
extern unsigned char lbl_27_bss_1A90;
extern Object lbl_27_bss_1A94;
extern unsigned char lbl_27_bss_1064[];
extern const float lbl_27_rodata_B70;
extern "C" void fn_27_8655C();
extern "C" void *__register_global_object(void *, void *, void *);
extern "C" void *fn_27_8659C() {
 if ((signed char)lbl_27_bss_1A90 == 0) {
  Vec a = {lbl_27_rodata_B70, lbl_27_rodata_B70, lbl_27_rodata_B70};
  lbl_27_bss_1A94.a = a;
  Vec b = {lbl_27_rodata_B70, lbl_27_rodata_B70, lbl_27_rodata_B70};
  lbl_27_bss_1A94.b = b;
  Vec c = {lbl_27_rodata_B70, lbl_27_rodata_B70, lbl_27_rodata_B70};
  lbl_27_bss_1A94.c = c;
  Vec d = {lbl_27_rodata_B70, lbl_27_rodata_B70, lbl_27_rodata_B70};
  lbl_27_bss_1A94.d = d;
  lbl_27_bss_1A94.e = 0;
  lbl_27_bss_1A94.f = 0;
  __register_global_object(&lbl_27_bss_1A94, (void *)fn_27_8655C, lbl_27_bss_1064);
  lbl_27_bss_1A90 = 1;
 }
 return &lbl_27_bss_1A94;
}