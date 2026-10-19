#pragma force_active on
class gfTask {
public:
    enum Category { Category_Info = 0 };
};

extern "C" {
extern const char lbl_18_data_518[];
extern char lbl_18_data_524[];
gfTask* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(gfTask*, const char*, gfTask::Category, int, int, bool);
}

extern "C" void* fn_18_10E0(void* self) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib((gfTask*)self, lbl_18_data_518, (gfTask::Category)8, 0xf, 8, true);
    *(int*)((char*)self + 0x44) = 0;
    *(char**)((char*)self + 0x3c) = lbl_18_data_524;
    return self;
}
