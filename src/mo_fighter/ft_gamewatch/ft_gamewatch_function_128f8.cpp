#pragma force_active on
extern "C" unsigned char lbl_107_data_9108[];

namespace {

struct Watcher {
    void* vtable;
};

} // namespace

extern "C" void fn_107_128F8(Watcher* obj)
{
    obj->vtable = lbl_107_data_9108;
}
