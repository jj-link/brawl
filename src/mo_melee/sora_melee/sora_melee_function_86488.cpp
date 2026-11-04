#pragma force_active on
struct Vec { float x,y,z; };
struct Object { Vec a,b,c,d; unsigned char e,f; };
extern unsigned char lbl_27_bss_1A58;
extern Object lbl_27_bss_1A5C;
extern unsigned char lbl_27_bss_1058[];
extern const float lbl_27_rodata_B70;
extern "C" void fn_27_8655C();
extern "C" void *__register_global_object(void *, void *, void *);
extern "C" void *fn_27_86488() {
 if ((signed char)lbl_27_bss_1A58 == 0) {
  Vec a = {lbl_27_rodata_B70, lbl_27_rodata_B70, lbl_27_rodata_B70};
  lbl_27_bss_1A5C.a = a;
  Vec b = {lbl_27_rodata_B70, lbl_27_rodata_B70, lbl_27_rodata_B70};
  lbl_27_bss_1A5C.b = b;
  Vec c = {lbl_27_rodata_B70, lbl_27_rodata_B70, lbl_27_rodata_B70};
  lbl_27_bss_1A5C.c = c;
  Vec d = {lbl_27_rodata_B70, lbl_27_rodata_B70, lbl_27_rodata_B70};
  lbl_27_bss_1A5C.d = d;
  lbl_27_bss_1A5C.e = 0;
  lbl_27_bss_1A5C.f = 0;
  __register_global_object(&lbl_27_bss_1A5C, (void *)fn_27_8655C, lbl_27_bss_1058);
  lbl_27_bss_1A58 = 1;
 }
 return &lbl_27_bss_1A5C;
}