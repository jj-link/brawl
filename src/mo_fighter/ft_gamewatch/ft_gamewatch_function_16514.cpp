#pragma force_active on
struct WatchFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

struct WatchObject {
    unsigned char padding[0xa4];
    WatchFlags flags;
};

extern "C" void fn_107_16514(WatchObject* object, int selected) {
    object->flags.selected = (unsigned char)selected;
}
