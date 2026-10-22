#pragma force_active on
extern "C" {
extern char lbl_80489098[];
extern char lbl_8059FFA8[];

int fn_8033413C(const char* arg0);
void fn_8027DC18(void* dst, const char* src);

void* fn_80334160(void* self) {
    char* p = static_cast<char*>(self);
    *(short*)(p + 6) = 1;
    *(void**)p = lbl_80489098;
    const char* g = lbl_8059FFA8;
    int r = fn_8033413C(g);
    *(int*)(p + 0xC) = fn_8033413C(g);
    *(const char**)(p + 8) = g;
    *(unsigned int*)(p + 0x10) = (unsigned int)r | 0x80000000u;
    fn_8027DC18(p + 0x14, g);
    return self;
}
}
