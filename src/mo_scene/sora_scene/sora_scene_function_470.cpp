#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct TaskA {
    char pad[0x78];
    int f78;
};

struct TaskB {
    char pad[0x16C];
    int f16C;
};

struct Archive {
    char pad[9];
    u8 flags;
};

struct Scene {
    void* unk0;
    void* unk4;
    Archive* archive;
    TaskA* taskA;
    TaskB* taskB;
    u32 state;
};

extern "C" {

void* getInstance__16CameraControllerFv(void);
void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
Archive* __ct__9gfArchiveFv(Archive*);
void __dt__9gfArchiveFv(Archive*, int);
extern char lbl_1_data_8[];
void fn_800151FC(void*, const char*, int, int, int, int);
TaskA* fn_22_0(void);
void fn_22_1454(TaskA*);
TaskB* fn_22_1688(void);
void fn_22_1BEC(TaskB*);
void fn_22_1564(TaskA*, Archive*);
void fn_22_1C8C(TaskB*, Archive*);
void fn_22_14C0(TaskA*);
void fn_22_1DDC(TaskB*);
void fn_22_1C40(TaskB*);
void exit__6gfTaskFv(void*);
void endKeepScreen__17gfKeepFrameBufferFv(void*);
void startKeepScreen__17gfKeepFrameBufferFv(void*);
void* getInstance__14gfSceneManagerFv(void);
extern char* g_gfApplication;

int fn_1_470(Scene* self) {
    switch (self->state) {
    case 0: {
        changeInput__16CameraControllerFQ216CameraController4Kind(getInstance__16CameraControllerFv(), 9);
        Archive* archive = (Archive*)__nw__FUlQ25Heaps8HeapType(0x80, 0x2A);
        if (archive)
            archive = __ct__9gfArchiveFv(archive);
        self->archive = archive;
        fn_800151FC(archive, lbl_1_data_8, 0x2B, 0, 0, 0xFF);
        self->taskA = fn_22_0();
        fn_22_1454(self->taskA);
        self->taskB = fn_22_1688();
        fn_22_1BEC(self->taskB);
        self->state = 1;
        break;
    }
    case 1:
        if ((self->archive->flags >> 7) & 1)
            self->state = 2;
        break;
    case 2:
        fn_22_1564(self->taskA, self->archive);
        fn_22_1C8C(self->taskB, self->archive);
        endKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
        self->state = 3;
        break;
    case 3:
        self->taskA->f78 = 1;
        self->state = 4;
        break;
    case 4:
        if (self->taskA->f78 == 0x3D)
            self->state = 5;
        break;
    case 5:
        self->state = 6;
        break;
    case 6:
        self->taskB->f16C = 1;
        self->state = 7;
        break;
    case 7:
        if (self->taskB->f16C == 0xF)
            self->state = 8;
        break;
    case 8:
        self->state = 9;
        break;
    case 9: {
        __dt__9gfArchiveFv(self->archive, 1);
        self->archive = 0;
        fn_22_14C0(self->taskA);
        exit__6gfTaskFv(self->taskA);
        self->taskA = 0;
        fn_22_1DDC(self->taskB);
        fn_22_1C40(self->taskB);
        exit__6gfTaskFv(self->taskB);
        self->taskB = 0;
        startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
        void* mgr = getInstance__14gfSceneManagerFv();
        *(u32*)((u8*)mgr + 0x284) = 0;
        *(u32*)((u8*)mgr + 0x288) = 2;
        self->state++;
        break;
    }
    }
    return 0;
}

}
