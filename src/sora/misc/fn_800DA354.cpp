#pragma force_active on
class gfTask {
public:
    enum Category { Category_Info = 0 };
};

extern "C" {
extern char lbl_80459B68[];
extern char lbl_80459BA4[];
gfTask* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(gfTask*, const char*, gfTask::Category, int, int, bool);
}

extern "C" gfTask* fn_800DA354(gfTask* self) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_80459B68, (gfTask::Category)8, 0xf, 8, true);
    unsigned char* base = (unsigned char*)self;
    unsigned int flags = base[0x2c];
    *(char**)(base + 0x3c) = lbl_80459BA4;
    *(int*)(base + 0x58) = 0;
    *(int*)(base + 0x5c) = 0;
    *(int*)(base + 0x60) = 1;
    *(int*)(base + 0x64) = 0;
    base[0x2c] = flags & 0xFFFFFFFD;
    *(int*)(base + 0x40) = 0;
    *(int*)(base + 0x44) = 0;
    *(int*)(base + 0x48) = 0;
    *(int*)(base + 0x4c) = 0;
    *(int*)(base + 0x50) = 0;
    *(int*)(base + 0x54) = 0;
    return self;
}
