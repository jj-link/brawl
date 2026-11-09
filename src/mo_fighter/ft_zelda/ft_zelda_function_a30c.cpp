#pragma force_active on
struct P1 { float f0; int i4; float f8, fC; };
struct P2 { int i0, i4, i8; float fC, f10, f14, f18; };
struct P3 { float f0, f4, f8, fC; int i10; float f14, f18, f1C, f20, f24; int i28; float f2C, f30, f34; };
struct P4 { float f0, f4, f8, fC, f10; };
struct P5 { float f0, f4, f8, fC, f10, f14, f18; };
struct Access { char pad[16]; float* f[2][32]; int* n[2][7]; };
extern "C" void fn_104_A30C(Access* a, const unsigned char* d) {
 for (int i=0;i<2;++i) {
  a->f[i][0] = &(*(P1* *)(d + 0x7c))->f0;
  a->f[i][1] = &(*(P1* const*)(d + 0x7c))->f8;
  a->f[i][2] = &(*(P1* const*)(d + 0x7c))->fC;
  a->f[i][3] = &(*(P2* const*)(d + 0x80))->fC;
  a->f[i][4] = &(*(P2* const*)(d + 0x80))->f10;
  a->f[i][5] = &(*(P2* const*)(d + 0x80))->f14;
  a->f[i][6] = &(*(P2* const*)(d + 0x80))->f18;
  a->f[i][7] = &(*(P3* *)(d + 0x84))->f0;
  a->f[i][8] = &(*(P3* const*)(d + 0x84))->f4;
  a->f[i][9] = &(*(P3* const*)(d + 0x84))->f8;
  a->f[i][10] = &(*(P3* const*)(d + 0x84))->fC;
  a->f[i][11] = &(*(P3* const*)(d + 0x84))->f14;
  a->f[i][12] = &(*(P3* const*)(d + 0x84))->f18;
  a->f[i][13] = &(*(P3* const*)(d + 0x84))->f1C;
  a->f[i][14] = &(*(P3* const*)(d + 0x84))->f20;
  a->f[i][15] = &(*(P3* const*)(d + 0x84))->f24;
  a->f[i][16] = &(*(P3* const*)(d + 0x84))->f2C;
  a->f[i][17] = &(*(P3* const*)(d + 0x84))->f30;
  a->f[i][18] = &(*(P3* const*)(d + 0x84))->f34;
  a->f[i][19] = &(*(P4* *)(d + 0x88))->f0;
  a->f[i][20] = &(*(P4* const*)(d + 0x88))->f4;
  a->f[i][21] = &(*(P4* const*)(d + 0x88))->f8;
  a->f[i][22] = &(*(P4* const*)(d + 0x88))->fC;
  a->f[i][23] = &(*(P4* const*)(d + 0x88))->f10;
  a->f[i][24] = &(*(P5* *)(d + 0x8c))->f0;
  a->f[i][25] = &(*(P5* const*)(d + 0x8c))->f4;
  a->f[i][26] = &(*(P5* const*)(d + 0x8c))->f8;
  a->f[i][27] = &(*(P5* const*)(d + 0x8c))->fC;
  a->f[i][28] = &(*(P5* const*)(d + 0x8c))->f10;
  a->f[i][29] = &(*(P5* const*)(d + 0x8c))->f14;
  a->f[i][30] = &(*(P5* const*)(d + 0x8c))->f18;
  a->n[i][0] = &(*(P1* const*)(d + 0x7c))->i4;
  a->n[i][1] = &(*(P2* *)(d + 0x80))->i0;
  a->n[i][2] = &(*(P2* const*)(d + 0x80))->i4;
  a->n[i][3] = &(*(P2* const*)(d + 0x80))->i8;
  a->n[i][4] = &(*(P3* const*)(d + 0x84))->i10;
  a->n[i][5] = &(*(P3* const*)(d + 0x84))->i28;
 }
}
