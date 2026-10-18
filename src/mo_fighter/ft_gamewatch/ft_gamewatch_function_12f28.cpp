#pragma force_active on
struct GWWatch;

extern "C" GWWatch lbl_107_data_9328;

extern "C" void fn_107_12F28(GWWatch *obj)
{
    GWWatch *ptr = &lbl_107_data_9328;
    *reinterpret_cast<GWWatch **>(obj) = ptr;
}
