#pragma force_active on
class gfTask {
public:
    enum Category {
        Category_0 = 0,
    };
};

class gfTaskScheduler {
public:
    static gfTaskScheduler* getInstance();
    void setPauseCategory(gfTask::Category category, bool pause);
};

void cmRemoveQuake(int quake);

extern "C" void fn_27_25C2B8(unsigned char* self) {
    gfTaskScheduler::getInstance()->setPauseCategory((gfTask::Category)0, false);
    gfTaskScheduler::getInstance()->setPauseCategory((gfTask::Category)10, false);
    gfTaskScheduler::getInstance()->setPauseCategory((gfTask::Category)2, false);
    gfTaskScheduler::getInstance()->setPauseCategory((gfTask::Category)12, false);
    cmRemoveQuake(1);
    *(int*)(self + 0x48) = 5;
}
