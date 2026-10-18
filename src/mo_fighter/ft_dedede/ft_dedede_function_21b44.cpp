#pragma force_active on
namespace {
struct DededeTraversalIndex {
    short value;
};
}

extern "C" void fn_117_21B44(DededeTraversalIndex* dst, const short* src)
{
    dst->value = *src;
}
