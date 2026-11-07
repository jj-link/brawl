#pragma force_active on
extern "C" {
int getPhase__13grTenganEventCFv(const void*);
void setPhase__13grTenganEventFl(void*, long);
void start__13grTenganEventFv(void*);
void end__13grTenganEventFv(void*);
unsigned long isReadyEnd__13grTenganEventCFv(const void*);
void* getGround__5StageFi(void*, int);
int isEndEntity__8grMadeinFv(void*);
void startEntity__8grMadeinFv(void*);
void setMotion__8grMadeinFUl(void*, unsigned long);
void fn_27_279228(void*, unsigned long);
}

struct Stage {
    char pad0[0x744];
    char event1[0xAC];
    char event2[0xAC];
    unsigned char flag;
};

extern "C" void fn_84_13D4(Stage* self) {
    switch (getPhase__13grTenganEventCFv(self->event1)) {
    case 0:
        fn_27_279228(getGround__5StageFi(self, 6), 1);
        if (isReadyEnd__13grTenganEventCFv(self->event1) == 1) {
            setPhase__13grTenganEventFl(self->event1, 1);
            start__13grTenganEventFv(self->event2);
            fn_27_279228(getGround__5StageFi(self, 6), 0);
            setMotion__8grMadeinFUl(getGround__5StageFi(self, 6), self->flag);
            startEntity__8grMadeinFv(getGround__5StageFi(self, 6));
        }
        break;
    case 1:
        if (isReadyEnd__13grTenganEventCFv(self->event2) == 1) {
            end__13grTenganEventFv(self->event2);
            start__13grTenganEventFv(self->event2);
            if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, 6)) != 0) {
                self->flag ^= 1;
                setMotion__8grMadeinFUl(getGround__5StageFi(self, 6), self->flag);
                startEntity__8grMadeinFv(getGround__5StageFi(self, 6));
            }
        }
        break;
    }
}
