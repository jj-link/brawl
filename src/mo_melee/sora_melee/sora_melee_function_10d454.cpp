#pragma force_active on
typedef unsigned int u32;

struct ftEntry;

extern "C" {
ftEntry* getEntity__14ftEntryManagerFUl(u32);
void fn_27_115830(ftEntry*);

void fn_27_10D454(void* self) {
    fn_27_115830(getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154)));
}
}
