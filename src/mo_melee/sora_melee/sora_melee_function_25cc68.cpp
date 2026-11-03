#include <revolution/os.h>
#pragma force_active on

struct Data {
    char pad[0x18];
    int value0;
    int value1;
    int value2;
    int value3;
    char message0[0x28];
    char message1[0x30];
    char message2[0x38];
    char message3[0x38];
    char message4[0x38];
    char message5[0x38];
    char message6[1];
};

extern "C" {
extern Data lbl_27_data_53E58;
extern int g_muWifiInterfaceTask;

int fn_80158638();
int fn_800D99D8(int);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_80154E14(void*, int);
int fn_80155C50(void*);
void fn_80154F08(void*, int);
void fn_80155BD0(void*);
}

struct Upload {
    char pad[0x348];
    unsigned char done;
    char pad349[3];
    int result;
    char pad350[8];
    int timeout;
};

struct Self {
    char pad[0x41];
    unsigned char active;
    unsigned char flag;
    char pad43[5];
    int value;
    int state;
    unsigned char finished;
    char pad51[3];
    Upload* uploader;
};

extern "C" void fn_27_25CC68(Self* self) {
    const Data& data = lbl_27_data_53E58;
    int task;

    if (self->active && !self->finished) {
        if (!(task = g_muWifiInterfaceTask)) {
            self->finished = 1;
            return;
        }

        switch (self->state) {
        case 0:
            self->value = data.value0;
            self->state = 0x43;
        case 0x43:
            if (fn_80158638() && fn_800D99D8(task)) {
                void* p = __nw__FUlQ25Heaps8HeapType(0x3a0, 0xf);
                if (p) {
                    p = fn_80154E14(p, 0xf);
                }
                self->uploader = (Upload*)p;
                if (!p) {
                    OSReport(data.message0);
                    goto finish;
                }

                self->uploader->timeout = 0x2ee0;
                if (!fn_80155C50(self->uploader)) {
                    OSReport(data.message1);
                    fn_80154F08(self->uploader, 1);
                    goto finish;
                }
                goto check82;

            pending:
                if (!self->flag) {
                    goto set82;
                }
                fn_80155BD0(self->uploader);
                goto check7e;

            set7e:
                self->value = data.value1;
                self->state = 0x7e;
                break;

            case 0x7e:
            check7e:
                if (!self->uploader->done) {
                    goto set7e;
                }
                goto report;

            set82:
                self->value = data.value2;
                self->state = 0x82;
                break;

            case 0x82:
            check82:
                if (!self->uploader->done) {
                    goto pending;
                }

            report:
                int result = self->uploader->result;
                switch (result) {
                case 0:
                    OSReport(data.message2);
                    break;
                case 1:
                    OSReport(data.message3);
                    break;
                case 2:
                    OSReport(data.message4);
                    break;
                case 3:
                    OSReport(data.message5);
                    break;
                default:
                    OSReport(data.message6, result);
                    break;
                }
                fn_80154F08(self->uploader, 1);
            }

        finish:
            self->finished = 1;
            self->value = data.value3;
            self->state = 0xae;
            break;
        }
    }
}
