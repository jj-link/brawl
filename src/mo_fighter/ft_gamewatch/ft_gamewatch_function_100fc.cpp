#pragma force_active on
struct Vec2f {
    float x, y;
};

struct GameWatchDispatchSpeed {
    float x, y;
};

struct GameWatchResetContext {
    unsigned char initialized;
    GameWatchResetContext() {
        __memclr(&initialized, sizeof(initialized));
    }
};

extern "C" {
void* __memcpy(void*, const void*, unsigned long);
void fn_27_15FA20(int, int, void*);
GameWatchDispatchSpeed fn_27_164B10(void*, bool, bool);
void fn_27_160268(void*);
void fn_107_10374(void*, int, const Vec2f*, void*);
void fn_107_104D8(void*, int, const Vec2f*, void*);
void fn_107_10654(void*, int, const Vec2f*, void*);
void fn_107_1083C(void*, int, const Vec2f*, void*);
void fn_107_10A14(void*, int, const Vec2f*, void*);
void fn_107_10B48(void*, int, const Vec2f*, void*);
void fn_107_10D1C(void*, int, const Vec2f*, void*);
void fn_107_10E68(void*, int, const Vec2f*, void*);
void fn_107_1111C(void*, int, const Vec2f*, void*);
void fn_107_11328(void*, int, const Vec2f*, void*);
void fn_107_114E4(void*, int, const Vec2f*, void*);
void fn_107_115B4(void*, int, const Vec2f*, void*);
void fn_107_11684(void*, int, const Vec2f*, void*);
void fn_107_1182C(void*, int, const Vec2f*, void*);
void fn_107_119A8(void*, int, const Vec2f*, void*);
}

extern "C" void fn_107_100FC(int kind, int resetKind, void* accesser) {
    if (kind <= 0x63) {
        fn_27_15FA20(kind, resetKind, accesser);
        return;
    }
    Vec2f speed;
    GameWatchDispatchSpeed returned = fn_27_164B10(accesser, 1, 1);
    __memcpy(&speed, &returned, sizeof(speed));
    switch (kind) {
    case 0x64: {
        GameWatchResetContext context;
        fn_107_10374(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x65: {
        GameWatchResetContext context;
        fn_107_104D8(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x66: {
        GameWatchResetContext context;
        fn_107_10654(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x67: {
        GameWatchResetContext context;
        fn_107_1083C(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x68: {
        GameWatchResetContext context;
        fn_107_10A14(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x69: {
        GameWatchResetContext context;
        fn_107_10B48(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x6A: {
        GameWatchResetContext context;
        fn_107_10D1C(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x6B: {
        GameWatchResetContext context;
        fn_107_10E68(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x6C: {
        GameWatchResetContext context;
        fn_107_1111C(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x6D: {
        GameWatchResetContext context;
        fn_107_11328(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x6E: {
        GameWatchResetContext context;
        fn_107_114E4(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x6F: {
        GameWatchResetContext context;
        fn_107_115B4(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x70: {
        GameWatchResetContext context;
        fn_107_11684(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x71: {
        GameWatchResetContext context;
        fn_107_1182C(&context, resetKind, &speed, accesser);
        break;
    }
    case 0x72: {
        GameWatchResetContext context;
        fn_107_119A8(&context, resetKind, &speed, accesser);
        break;
    }
    default:
        return;
    }
    fn_27_160268(accesser);
}