#include <so/so_module_accesser.h>
#pragma force_active on

struct FtPokeEvent {
    int kind;
    unsigned char flag4;
    unsigned char flag5;
    unsigned char pad[2];
    int payload;
};

struct FtPokeHandler {
    unsigned char reserved[0x60];
    soModuleAccesser* accesser;
};

extern "C" void fn_27_377B30(soModuleAccesser* accesser, void* data);
extern "C" void fn_27_12D904(void* self, bool a, bool b, int c);
extern "C" void fn_27_1324D4(FtPokeHandler* self, FtPokeEvent* event, soModuleAccesser* accesser, void* object, int eventType);

extern "C" void fn_116_183D8(FtPokeHandler* self, FtPokeEvent* event, soModuleAccesser* accesser, void* object, int eventType) {
    switch (event->kind) {
    case 0x455:
        fn_27_377B30(accesser, &event->payload);
        fn_27_12D904(self, true, true, 0);
        break;
    case 6:
        switch (self->accesser->getStatusModule().getStatusKind()) {
        case 0x113:
        case 0x119:
            event->flag4 = 1;
            event->flag5 = 1;
            event->payload = self->accesser->getModelModule().getCorrectNodeId(0x133);
            self->accesser->getStatusModule().changeStatusRequest(0x11B, self->accesser);
            return;
        }
        break;
    }
    fn_27_1324D4(self, event, accesser, object, eventType);
}
