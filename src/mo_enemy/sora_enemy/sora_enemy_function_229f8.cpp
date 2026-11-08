#pragma force_active on
extern "C" {
void* fn_27_8C078(void*, void*, int, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char __RTTI__20emResourceModuleImpl[], __RTTI__16soResourceModule[];
void* fn_41_229F8(void* self, char* acc, int id, int arg3) {
 if (id <= 0xA7F7) return fn_27_8C078(self, acc, id, arg3);
 char* r = (char*)__dynamic_cast(**(void***)(acc + 0xd8), 8, __RTTI__20emResourceModuleImpl, __RTTI__16soResourceModule, 1);
 char* a = *(char**)(r + 0x18);
 char* b = *(char**)(r + 0x20);
 char* c = *(char**)(r + 0x24);
 char* d = *(char**)(r + 0x28);
 switch (id) {
 case 43000: return *(void**)(a + 4);
 case 43001: return *(void**)(a + 8);
 case 43002: return *(void**)(a + 12);
 case 43003: return *(void**)(a + 16);
 case 43038: return *(void**)(a + 20);
 case 43039: return *(void**)(a + 24);
 case 43004: return *(void**)(b + 0);
 case 43005: return *(void**)(b + 4);
 case 43006: return *(void**)(b + 8);
 case 43007: return b + 12;
 case 43008: return *(void**)(b + 20);
 case 43009: return *(void**)(b + 36);
 case 43010: return *(void**)(b + 40);
 case 43011: return *(void**)(b + 44);
 case 43012: return *(void**)(b + 48);
 case 43013: return *(void**)(b + 52);
 case 43014: return *(void**)(b + 56);
 case 43015: return *(void**)(b + 60);
 case 43016: return *(void**)(b + 64);
 case 43017: return *(void**)(b + 68);
 case 43018: return *(void**)(b + 72);
 case 43019: return *(void**)(b + 76);
 case 43020: return *(void**)(b + 80);
 case 43021: return *(void**)(b + 84);
 case 43022: return *(void**)(b + 88);
 case 43023: return *(void**)(b + 92);
 case 43024: return *(void**)(b + 96);
 case 43025: return *(void**)(b + 100);
 case 43026: return *(void**)(b + 104);
 case 43027: return *(void**)(b + 108);
 case 43028: return c + 108;
 case 43029: return c + 116;
 case 43030: return c + 124;
 case 43031: return c + 72;
 case 43032: return d + 8;
 case 43033: return d + 40;
 case 43034: return d + 56;
 case 43035: return d + 76;
 case 43036: return d + 164;
 case 43037: return d + 172;
 default: return 0;
 }
}
}