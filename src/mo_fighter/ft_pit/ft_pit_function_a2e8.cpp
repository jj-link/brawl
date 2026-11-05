#pragma force_active on
typedef unsigned char u8;
struct A { float f0; int i4; float f8, fC; };
struct B { int i0; float f4, f8, fC, f10, f14, f18; };
struct C { float f0, f4; int i8; float fC, f10, f14, f18, f1C, f20, f24, f28, f2C; int i30; float f34, f38, f3C, f40; };
struct D { float f0; int i4, i8; float fC, f10; int i14; float f18, f1C, f20; };
struct Access { u8 pad[0x10]; float* floats[2][31]; int* ints[2][8]; };
extern "C" void fn_112_A2E8(Access* self, const u8* data) {
 for (int i = 0; i < 2; ++i) {
 self->floats[i][0] = &(*(A**)(data + 0x7C))->f0;
 self->floats[i][1] = &(*(A* const*)(data + 0x7C))->f8;
 self->floats[i][2] = &(*(A* const*)(data + 0x7C))->fC;
 self->floats[i][3] = &(*(B* const*)(data + 0x80))->f4;
 self->floats[i][4] = &(*(B* const*)(data + 0x80))->f8;
 self->floats[i][5] = &(*(B* const*)(data + 0x80))->fC;
 self->floats[i][6] = &(*(B* const*)(data + 0x80))->f10;
 self->floats[i][7] = &(*(B* const*)(data + 0x80))->f14;
 self->floats[i][8] = &(*(B* const*)(data + 0x80))->f18;
 self->floats[i][9] = &(*(C**)(data + 0x84))->f0;
 self->floats[i][10] = &(*(C* const*)(data + 0x84))->f4;
 self->floats[i][11] = &(*(C* const*)(data + 0x84))->fC;
 self->floats[i][12] = &(*(C* const*)(data + 0x84))->f10;
 self->floats[i][13] = &(*(C* const*)(data + 0x84))->f14;
 self->floats[i][14] = &(*(C* const*)(data + 0x84))->f18;
 self->floats[i][15] = &(*(C* const*)(data + 0x84))->f1C;
 self->floats[i][16] = &(*(C* const*)(data + 0x84))->f20;
 self->floats[i][17] = &(*(C* const*)(data + 0x84))->f24;
 self->floats[i][18] = &(*(C* const*)(data + 0x84))->f28;
 self->floats[i][19] = &(*(C* const*)(data + 0x84))->f2C;
 self->floats[i][20] = &(*(C* const*)(data + 0x84))->f34;
 self->floats[i][21] = &(*(C* const*)(data + 0x84))->f38;
 self->floats[i][22] = &(*(C* const*)(data + 0x84))->f3C;
 self->floats[i][23] = &(*(C* const*)(data + 0x84))->f40;
 self->floats[i][24] = &(*(D**)(data + 0x88))->f0;
 self->floats[i][25] = &(*(D* const*)(data + 0x88))->fC;
 self->floats[i][26] = &(*(D* const*)(data + 0x88))->f10;
 self->floats[i][27] = &(*(D* const*)(data + 0x88))->f18;
 self->floats[i][28] = &(*(D* const*)(data + 0x88))->f1C;
 self->floats[i][29] = &(*(D* const*)(data + 0x88))->f20;
 self->ints[i][0] = &(*(A* const*)(data + 0x7C))->i4;
 self->ints[i][1] = &(*(B**)(data + 0x80))->i0;
 self->ints[i][2] = &(*(C* const*)(data + 0x84))->i8;
 self->ints[i][3] = &(*(C* const*)(data + 0x84))->i30;
 self->ints[i][4] = &(*(D* const*)(data + 0x88))->i4;
 self->ints[i][5] = &(*(D* const*)(data + 0x88))->i8;
 self->ints[i][6] = &(*(D* const*)(data + 0x88))->i14;
 }
}
