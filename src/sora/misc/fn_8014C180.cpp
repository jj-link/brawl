#pragma force_active on
class gfTask {
public:
    enum Category { Category_Info = 0 };
};

extern "C" {
extern char lbl_80460D50[];
extern char lbl_80460D64[];
gfTask* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(gfTask*, const char*, gfTask::Category, int, int, bool);
}

extern "C" gfTask* fn_8014C180(gfTask* self) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_80460D50, (gfTask::Category)0, 0xe, 6, true);
    unsigned char* base = (unsigned char*)self;
    unsigned int flags = base[0x2c];
    *(char**)(base + 0x3c) = lbl_80460D64;
    *(int*)(base + 0x40) = 0;
    *(char*)(base + 0x44) = 0;
    base[0x2c] = flags & 0xFFFFFFFD;
    return self;
}
