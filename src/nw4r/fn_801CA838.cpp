#pragma force_active on
extern "C" {
extern char lbl_80466BD8[];

void fn_801BF698(void* p, void* q);
void OSInitMutex(void* m);

void* fn_801CA838(void* self) {
    char* vt = lbl_80466BD8;
    *(char**)self = vt;
    fn_801BF698((char*)self + 0x1C, vt);
    OSInitMutex((char*)self + 0x4);
    return self;
}
}
