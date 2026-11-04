#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Service {
    u32 type, outgoing, incoming;
    u16 psm;
    u8 flags;
    u8 pad[0x2d];
} Service;
typedef void (*Callback)(void *, void *, u8);
typedef struct Obj {
    Service *service;
    Callback callback;
    void *userdata;
    u8 pad[0x6a];
    u8 flags;
    u8 pad2[9];
    u8 incoming;
    u8 service_flags;
} Obj;
extern u8 lbl_80529CF8[];
extern char lbl_80481A20[];
extern Obj *fn_8023A0F0(void *);
extern Obj *fn_80239F18(void *);
extern u8 fn_80241D40(Obj *);
extern void fn_80231A2C(int, char *, u32, u32, u32);

static inline Service *find_service(u32 psm, int incoming, u32 type, u32 channel) {
    Service *service = (Service *)(lbl_80529CF8 + 0x1990);
    int i;
    for (i = 0; i < 24; i++, service++) {
        if ((service->flags & 0x80) && service->psm == psm && service->type == type) {
            if ((incoming && service->outgoing == channel) ||
                (!incoming && service->incoming == channel))
                return service;
        }
    }
    return 0;
}

void fn_80240250(void *addr, u32 psm, int incoming, u32 type, u32 channel, Callback callback, void *userdata) {
    Obj *obj;
    Service *service;
    u8 result;
    obj = fn_8023A0F0(addr);
    if (obj == 0) {
        obj = fn_80239F18(addr);
        if (obj == 0) {
            if (callback != 0)
                callback(addr, userdata, 3);
            return;
        }
    }
    service = find_service(psm, incoming, type, channel);
    if (service == 0) {
        if (callback)
            callback(addr, userdata, 4);
        if (lbl_80529CF8[0x27c0] >= 1)
            fn_80231A2C(0xd0000, lbl_80481A20, psm, type, channel);
    } else {
        obj->service = service;
        obj->service_flags = service->flags;
        obj->incoming = incoming;
        obj->callback = callback;
        obj->userdata = userdata;
        obj->flags &= 0xfe;
        result = fn_80241D40(obj);
        if (result != 1 && callback) {
            if (obj->incoming && obj->service && obj->service->type == 3)
                obj->service->outgoing = 0;
            callback(addr, userdata, result);
            obj->callback = 0;
        }
    }
}