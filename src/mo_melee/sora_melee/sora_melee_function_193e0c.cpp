#pragma force_active on
#pragma fp_contract off
typedef unsigned int u32;
struct Work {
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual int getInt(u32);
virtual void gap0();
virtual void gap1();
virtual void gap2();
virtual void gap3();
virtual void gap4();
virtual void gap5();
virtual void gap6();
virtual void gap7();
virtual void gap8();
virtual void gap9();
virtual void gap10();
virtual void gap11();
virtual u32 isFlag(u32);
};
struct Base8 { char pad[8]; };
struct Motion : Base8 {
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual void slot37();
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45();
virtual void slot46();
virtual void slot47();
virtual void slot48();
virtual void slot49();
virtual void slot50();
virtual void slot51();
virtual void slot52();
virtual void slot53();
virtual void slot54();
virtual void slot55();
virtual void slot56();
virtual void slot57();
virtual void slot58();
virtual void slot59();
virtual void slot60();
virtual void slot61();
virtual void slot62();
virtual void slot63();
virtual void slot64();
virtual void slot65();
virtual void slot66();
virtual void slot67();
virtual void slot68();
virtual void slot69();
virtual void slot70();
virtual void slot71();
virtual void slot72();
virtual void slot73();
virtual void slot74();
virtual void slot75();
virtual void slot76();
virtual void slot77();
virtual void slot78();
virtual void slot79();
virtual void slot80();
virtual void slot81();
virtual void slot82();
virtual void slot83();
virtual void slot84();
virtual void slot85();
virtual void slot86();
virtual void slot87();
virtual void slot88();
virtual void slot89();
virtual float getRate(int);
};
struct Special : Base8 {
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual u32 isValid(int);
char pad0C[0xC]; float value18, value1C, value20;
};
struct Modules {
char pad00[0x10]; Motion* motion; char pad14[0x50]; Work* work;
char pad68[0x4C]; void* special;
};
struct Access { char pad00[0xD8]; Modules* modules; };
struct Constants { float zero; float pad04[3]; float one; float pad14[2]; float half; };
extern "C" {
extern const unsigned char lbl_27_rodata_26B0[];
extern const unsigned char lbl_27_data_32C28[];
extern const unsigned char lbl_27_data_9848[];
extern void* g_ftManager;
void* getOwner__9ftManagerFi(void*, int);
u32 fn_27_11213C(void*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Access*, u32, u32);
void* __dynamic_cast(void*, long, const void*, const void*, short);
float randf__Fv();
int fn_27_193E0C(Access* a, int mode, float extra) {
const Constants* c = (const Constants*)lbl_27_rodata_26B0;
if (a->modules->work->isFlag(0x12000025) != 1) {
int id = a->modules->work->getInt(0x10000000);
if (fn_27_11213C(getOwner__9ftManagerFi(g_ftManager, id)) == 1) {
if (a->modules->work->getInt(0x10000009) > 0) return 0;
}
float chance = c->zero;
float factor = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xDB3, 0);
if (mode == 1) {
float high = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xC8B, 0);
float low = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xC8C, 0);
float t = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xDB2, 0);
t = c->one + t;
t *= c->half;
chance = t * (high - low) + low;
if (c->zero != chance) {
float rate = a->modules->motion->getRate(0);
if (rate > c->one) rate = c->one;
if (rate > c->zero) {
float scale = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xC88, 0);
chance *= scale / rate;
}
}
} else if (mode == 2) {
Special* s = (Special*)__dynamic_cast(a->modules->special, 8, lbl_27_data_32C28, lbl_27_data_9848, 1);
if (s->isValid(0) == 1) chance = s->value1C;
if (c->zero == chance) {
chance = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xC89, 0);
float low = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xC8A, 0);
float t = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xDB2, 0);
t = c->one + t;
t *= c->half;
chance = t * (chance - low) + low;
if (c->zero != chance) {
float rate = a->modules->motion->getRate(0);
if (rate > c->one) rate = c->one;
if (rate > c->zero) {
float scale = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a, 0xC88, 0);
chance *= scale / rate;
}
}
}
} else if (mode == 3) {
Special* s = (Special*)__dynamic_cast(a->modules->special, 8, lbl_27_data_32C28, lbl_27_data_9848, 1);
if (s->isValid(0) == 1) chance = s->value18;
if (factor > c->one) chance = c->one / factor;
} else if (mode == 4) {
Special* s = (Special*)__dynamic_cast(a->modules->special, 8, lbl_27_data_32C28, lbl_27_data_9848, 1);
if (s->isValid(0) == 1) chance = s->value20;
if (factor > c->one) chance = c->one / factor;
}
if (c->zero != chance) {
chance = factor * (chance + extra);
if (c->zero != chance) {
if (chance >= randf__Fv()) return 1;
}
}
}
return 0;
}
}
