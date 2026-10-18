#pragma force_active on
extern char lbl_105_data_31E0[];

extern "C" void fn_105_9E0C(void** self, void* a, void* b, void* c)
{
    self[0] = (void*)lbl_105_data_31E0;
    self[4] = a;
    self[5] = b;
    self[6] = c;
}
