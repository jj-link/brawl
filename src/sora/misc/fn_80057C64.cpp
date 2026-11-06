#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
void* fn_8004E5D8(void*, int);
int fn_80055398(int);
void fn_800553B8(int);
unsigned int fn_800580AC(int);
unsigned int fn_80058170(int);
unsigned int fn_8005825C(int);
unsigned int fn_80058320(int);
unsigned int fn_80058544(int);
unsigned int fn_800587FC(int);
unsigned int fn_800589C8(int);
unsigned int fn_80058C48(int);
unsigned int fn_80058F64(int);
unsigned int fn_800591AC(int);
unsigned int fn_8005925C(int);
}
extern "C" void fn_80057C64() {
 int passes = 0;
 do {
  int changed = 0;
  for (int i = 0; i < 128; ++i) {
   if (fn_80055398(i) == 0) {
    int unlock = 0;
    switch (i) {
    case 0x2e:
     if (*(unsigned short*)((char*)fn_8004E5D8(g_GameGlobal, 5) + 0x98) >= 20) unlock = 1;
     break;
    case 0xf:
     if (*(unsigned short*)((char*)fn_8004E5D8(g_GameGlobal, 1) + 0x98) >= 20) unlock = 1;
     break;
    case 0x10:
     if (*(unsigned short*)((char*)fn_8004E5D8(g_GameGlobal, 9) + 0x98) >= 10) unlock = 1;
     break;
    case 0x9:
     if (*(unsigned short*)((char*)fn_8004E5D8(g_GameGlobal, 8) + 0x98) >= 3) unlock = 1;
     break;
    case 0x34:
     if (*(unsigned short*)((char*)fn_8004E5D8(g_GameGlobal, 32) + 0x98) >= 10) unlock = 1;
     break;
    case 0x18:
    case 0x1b:
    case 0x22:
    case 0x2c:
    case 0x3c:
    case 0x41:
    case 0x5f:
    case 0x62:
     if (fn_800580AC(i) == 1U) unlock = 1;
     break;
    case 0x0:
    case 0x17:
    case 0x24:
    case 0x3d:
    case 0x5a:
    case 0x65:
    case 0x67:
    case 0x7f:
     if (fn_80058170(i) == 1U) unlock = 1;
     break;
    case 0x5:
    case 0x7:
    case 0x25:
    case 0x29:
    case 0x2d:
    case 0x3e:
    case 0x78:
     if (fn_8005825C(i) == 1U) unlock = 1;
     break;
    case 0xe:
    case 0x28:
    case 0x2b:
    case 0x2f:
    case 0x45:
    case 0x47:
    case 0x4c:
    case 0x50:
    case 0x55:
    case 0x56:
    case 0x5e:
    case 0x6d:
    case 0x72:
    case 0x76:
     if (fn_80058320(i) == 1U) unlock = 1;
     break;
    case 0xc:
    case 0xd:
    case 0x26:
    case 0x4b:
    case 0x57:
    case 0x5d:
    case 0x69:
    case 0x7b:
    case 0x7c:
     if (fn_80058544(i) == 1U) unlock = 1;
     break;
    case 0x2:
    case 0x1a:
    case 0x27:
    case 0x48:
    case 0x4f:
    case 0x51:
    case 0x5b:
    case 0x73:
    case 0x77:
    case 0x7a:
     if (fn_800587FC(i) == 1U) unlock = 1;
     break;
    case 0x6:
    case 0x14:
    case 0x3f:
    case 0x44:
    case 0x52:
    case 0x54:
    case 0x60:
    case 0x74:
    case 0x79:
     if (fn_800589C8(i) == 1U) unlock = 1;
     break;
    case 0xa:
    case 0x11:
    case 0x13:
    case 0x15:
    case 0x1c:
    case 0x31:
    case 0x32:
    case 0x37:
    case 0x49:
    case 0x4e:
    case 0x6e:
    case 0x6f:
    case 0x70:
    case 0x71:
     if (fn_80058C48(i) == 1U) unlock = 1;
     break;
    case 0x4:
    case 0x8:
    case 0xb:
    case 0x12:
    case 0x16:
    case 0x1d:
    case 0x1f:
    case 0x23:
    case 0x2a:
    case 0x38:
    case 0x3a:
    case 0x43:
    case 0x46:
    case 0x4a:
    case 0x4d:
    case 0x58:
    case 0x61:
    case 0x63:
    case 0x68:
    case 0x6a:
     if (fn_80058F64(i) == 1U) unlock = 1;
     break;
    case 0x21:
    case 0x6c:
     if (fn_800591AC(i) == 1U) unlock = 1;
     break;
    case 0x1:
    case 0x3:
    case 0x19:
    case 0x1e:
    case 0x20:
    case 0x30:
    case 0x33:
    case 0x36:
    case 0x3b:
    case 0x40:
    case 0x53:
    case 0x59:
    case 0x5c:
    case 0x64:
    case 0x66:
    case 0x6b:
    case 0x7d:
    case 0x7e:
     if (fn_8005925C(i) == 1U) unlock = 1;
     break;
    }
    if (unlock) { fn_800553B8(i); changed = 1; }
   }
  }
  if (!changed) break;
  ++passes;
 } while (passes < 3);
}