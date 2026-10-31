#pragma once
#include "PdhQuery.h"

// GPU利用率监控类
class CPdhGPUVram : public CPdhQuery
{
public:
    CPdhGPUVram();
    ~CPdhGPUVram();

    bool GetUsedVram(unsigned long long& bytes);
};
