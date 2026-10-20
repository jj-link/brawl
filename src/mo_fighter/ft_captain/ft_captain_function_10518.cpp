#pragma force_active on
#define SLOT(n) virtual void v##n();
#define TEN(n) \
    SLOT(n##0) SLOT(n##1) SLOT(n##2) SLOT(n##3) SLOT(n##4) \
    SLOT(n##5) SLOT(n##6) SLOT(n##7) SLOT(n##8) SLOT(n##9)

struct Work {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3)
    virtual int getInt(int);
};

struct ArticleModule {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4)
    SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    TEN(1)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    virtual void* get(int);
};

struct Modules {
    char pad[0x64];
    Work* work;
    char pad68[0x1c];
    ArticleModule* article;
};

struct Fighter {
    char pad[0xd8];
    Modules* modules;
};

struct TaskObject {
    char pad[0x3c];
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4)
    SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    TEN(1) TEN(2) TEN(3) TEN(4) TEN(5)
    TEN(6) TEN(7) TEN(8) TEN(9)
    TEN(10) TEN(11) TEN(12) TEN(13)
    TEN(14) TEN(15) TEN(16) TEN(17)
    SLOT(180) SLOT(181) SLOT(182)
    SLOT(183) SLOT(184) SLOT(185)
    virtual int kind();
};

#undef TEN
#undef SLOT

struct Hit {
    unsigned int id;
    int unk;
    Fighter* fighter;
    char pad[0x18];
    unsigned char active : 1;
    unsigned char flags : 7;
    char tail[3];
};

struct Scene {
    char pad[0x465];
    unsigned char upper : 4;
    unsigned char paused : 1;
    unsigned char lower : 3;
};

extern "C" {
void* getInstance__15gfTaskSchedulerFv();
void setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(void*, int, bool);
void* getTask__15gfTaskSchedulerFPCc(void*, const char*);
void setPaused__6gfTaskFb(void*, bool);
void* getTask__6gfTaskFi(int);
void* __dynamic_cast(void*, long, const void*, const void*, short);

extern const int lbl_100_rodata_5C[6];
extern const char* lbl_100_data_69A0[2];
extern Scene* g_gfSceneRoot;
extern void* g_ftManager;
extern Hit* lbl_100_bss_268;
extern char lbl_100_data_18F8[];
extern char lbl_100_data_22AC[];
extern char lbl_100_data_167C[];
extern char lbl_100_data_1A68[];
}

static inline void unpauseHits(int count) {
    int i;
    Hit* hit = lbl_100_bss_268;
    for (i = 0; i < count; ++i, ++hit) {
        if (hit->id != -1 && hit->active) {
            void* task = getTask__6gfTaskFi(hit->id);
            if (task) {
                TaskObject* obj = static_cast<TaskObject*>(__dynamic_cast(
                    task, 0x3c, lbl_100_data_18F8, lbl_100_data_22AC, 0));
                if (obj->kind() == 5) {
                    ArticleModule* article = hit->fighter->modules->article;
                    void* ptr = article->get(10);
                    if (ptr) {
                        setPaused__6gfTaskFb(__dynamic_cast(
                            ptr, 0, lbl_100_data_167C, lbl_100_data_1A68, 0),
                            false);
                    }
                }
            }
        }
    }
}

extern "C" void fn_100_10518(Fighter* self, bool paused) {
    void* scheduler = getInstance__15gfTaskSchedulerFv();
    unsigned i;
    for (i = 0; i < 6; ++i) {
        setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(
            scheduler, lbl_100_rodata_5C[i], paused);
    }

    g_gfSceneRoot->paused = paused;

    for (i = 0; i < 2; ++i) {
        void* task = getTask__15gfTaskSchedulerFPCc(
            scheduler, lbl_100_data_69A0[i]);
        if (task)
            setPaused__6gfTaskFb(task, paused);
    }

    setPaused__6gfTaskFb(g_ftManager, paused);

    if (paused) {
        Work* work = self->modules->work;
        void* task = getTask__6gfTaskFi(work->getInt(0x20000001));
        if (task)
            setPaused__6gfTaskFb(task, false);

        work = self->modules->work;
        int count = work->getInt(0x20000000);
        unpauseHits(count);
    }
}
