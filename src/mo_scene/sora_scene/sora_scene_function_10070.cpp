#pragma force_active on

struct InputBase {
    unsigned char pad[0x200];
};

struct InputObj : InputBase {
    virtual void func1(int arg);
};

struct SceneState {
    unsigned char pad[8];
    void* task;
    InputObj* input;
    int result;
    unsigned int state;
};

extern "C" {
void fn_24_2F48(void*);
void* fn_24_2960(void);
void fn_24_2B10(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_24_2EF8(void*);
void fn_24_2C18(void*);
bool fn_24_2C98(void*);
void fn_24_2D18(void*);
void fn_24_2E38(void*);
void fn_24_2E80(void*);
unsigned int fn_24_31F4(void*);
unsigned int fn_24_2FC8(void*);
void fn_24_2EB0(void*);
void fn_24_2E98(void*);
void fn_24_2B6C(void*);
void exit__6gfTaskFv(void*);
void endKeepScreen__17gfKeepFrameBufferFv(void*);
void startKeepScreen__17gfKeepFrameBufferFv(void*);
void* getInstance__14gfSceneManagerFv(void);
int __cntlzw(unsigned int);
extern char* g_gfApplication;
}

extern "C" int fn_1_10070(SceneState* self) {
    int result;
    if (self->input) {
        fn_24_2F48(self->input);
    }

    switch (self->state) {
    case 0:
        self->task = fn_24_2960();
        fn_24_2B10(self->task);
        {
            void* p = __nw__FUlQ25Heaps8HeapType(0x204, 0x2A);
            if (p) {
                p = fn_24_2EF8(p);
            }
            self->input = (InputObj*)p;
        }
        fn_24_2C18(self->task);
        self->state = 1;
        break;
    case 1:
        if (static_cast<unsigned int>(
                __cntlzw(static_cast<unsigned int>(static_cast<int>(fn_24_2C98(self->task)) - 1))) >> 5)
            break;
        self->state = 2;
        break;
    case 2:
        fn_24_2D18(self->task);
        endKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
        self->state = 3;
        break;
    case 3:
        *(int*)((char*)self->task + 0x60) = 1;
        fn_24_2E38(self->task);
        fn_24_2E80(self->task);
        self->state = 4;
        break;
    case 4:
        if (fn_24_31F4(self->input) == 1) {
            fn_24_2EB0(self->task);
            self->result = 1;
        }
        if (fn_24_2FC8(self->input) == 1) {
            fn_24_2EB0(self->task);
            self->result = 0;
        }
        if (*(int*)((char*)self->task + 0x60) == 3) {
            self->state = 5;
        }
        break;
    case 5:
        fn_24_2E98(self->task);
        self->state = 6;
        break;
    case 6:
        fn_24_2B6C(self->task);
        exit__6gfTaskFv(self->task);
        self->task = 0;
        if (self->input) {
            self->input->func1(1);
        }
        self->input = 0;
        startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
        result = self->result;
        {
            char* mgr = (char*)getInstance__14gfSceneManagerFv();
            *(int*)(mgr + 0x284) = result;
            *(int*)(mgr + 0x288) = 2;
        }
        self->state++;
        break;
    }
    return 0;
}
