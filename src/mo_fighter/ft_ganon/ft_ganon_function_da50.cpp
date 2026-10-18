#pragma force_active on
struct StGhostFootData {
    float f[16];
};

extern "C" extern const StGhostFootData lbl_109_data_6588;

// Set the ghost-foot effect data pointer (e.g. in the character's GStatus
// block): point at the shared table of foot-effect parameters.
extern "C" void fn_109_DA50(const StGhostFootData **object)
{
    *object = &lbl_109_data_6588;
}
