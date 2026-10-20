#pragma force_active on
struct StConfigData {
    unsigned char _0[388];
    unsigned char m_byte;
    unsigned int m_flag;
    float m_value;
};

extern "C" void fn_89_197C(StConfigData* data, char b, unsigned int flag, float value)
{
    data->m_byte = b;
    data->m_flag = flag;
    data->m_value = value;
}
