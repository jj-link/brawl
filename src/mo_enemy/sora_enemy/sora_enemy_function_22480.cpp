#pragma force_active on
extern "C" {
float fn_27_8C02C(void*, void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char __RTTI__20emResourceModuleImpl[], __RTTI__16soResourceModule[];
extern const float lbl_41_rodata_D40;

#define F(p,o) (*(float*)((char*)(p)+(o)))
float fn_41_22480(void* self, char* acc, int id) {
    if (id <= 0xBB7) return fn_27_8C02C(self, acc, id);
    char* r = (char*)__dynamic_cast(**(void***)(acc + 0xd8), 8, __RTTI__20emResourceModuleImpl, __RTTI__16soResourceModule, 1);
    char* a = *(char**)(r + 0x1c);
    char* b = *(char**)(r + 0x24);
    char* c = *(char**)(r + 0x28);
    switch (id) {
    case 0xBB8: return F(a,0x0);
    case 0xBB9: return F(a,0x4);
    case 0xBBA: return F(a,0x8);
    case 0xBBB: return F(a,0xC);
    case 0xBBC: return F(a,0x10);
    case 0xBBD: return F(a,0x14);
    case 0xBBE: return F(a,0x18);
    case 0xBBF: return F(a,0x1C);
    case 0xBC0: return F(a,0x20);
    case 0xBC1: return F(a,0x24);
    case 0xBC2: return F(a,0x28);
    case 0xBC3: return F(a,0x2C);
    case 0xBC4: return F(a,0x30);
    case 0xBC5: return F(a,0x48);
    case 0xBC6: return F(a,0x50);
    case 0xBC7: return F(a,0x54);
    case 0xBC8: return F(a,0x5C);
    case 0xBC9: return F(a,0x60);
    case 0xBCA: return F(a,0x64);
    case 0xBCB: return F(a,0x6C);
    case 0xBCC: return F(a,0x70);
    case 0xBCD: return F(a,0x74);
    case 0xBCE: return F(a,0x78);
    case 0xBF9: return F(a,0x84);
    case 0xBFA: return F(a,0x88);
    case 0xBFB: return F(a,0x8C);
    case 0xBFC: return F(a,0x90);
    case 0xBFD: return F(a,0x94);
    case 0xBFF: return F(a,0x98);
    case 0xC00: return F(a,0x9C);
    case 0xBCF: return F(a,0xA0);
    case 0xBD0: return F(a,0xA4);
    case 0xBD1: return F(a,0xA8);
    case 0xBD2: return F(a,0xAC);
    case 0xBD3: return F(a,0xB0);
    case 0xBD4: return F(a,0xB4);
    case 0xBD5: return F(a,0xB8);
    case 0xBD6: return F(a,0xBC);
    case 0xBD7: return F(a,0xC0);
    case 0xBD8: return F(a,0xC4);
    case 0xBD9: return F(a,0xC8);
    case 0xBDA: return F(a,0xCC);
    case 0xBDB: return F(a,0xDC);
    case 0xBDC: return F(a,0xE0);
    case 0xBDD: return F(a,0xE4);
    case 0xBDE: return F(a,0xE8);
    case 0xBDF: return F(a,0xEC);
    case 0xBE0: return F(a,0xF0);
    case 0xBE1: return F(a,0xF4);
    case 0xBE2: return F(a,0xF8);
    case 0xBE3: return F(a,0xFC);
    case 0xBE4: return F(a,0x100);
    case 0xBE5: return F(a,0x104);
    case 0xBE6: return F(a,0x108);
    case 0xBF8: return F(a,0x10C);
    case 0xBE7: return F(b,0x0);
    case 0xBE8: return F(b,0x4);
    case 0xBF0: return F(b,0x8);
    case 0xBE9: return F(b,0x18);
    case 0xBEA: return F(b,0x1C);
    case 0xBEB: return F(b,0x24);
    case 0xBEC: return F(b,0x30);
    case 0xBED: return F(b,0x34);
    case 0xBEE: return F(b,0x58);
    case 0xBEF: return F(b,0x5C);
    case 0xBF1: return F(b,0x9C);
    case 0xBF2: return F(b,0xA0);
    case 0xBFE: return F(b,0xA4);
    case 0xBF3: return F(b,0xAC);
    case 0xBF4: return F(c,0x0);
    case 0xBF5: return F(c,0x4);
    case 0xBF6: return F(c,0x30);
    case 0xBF7: return F(c,0x34);
    default: return lbl_41_rodata_D40;
    }
}
}
