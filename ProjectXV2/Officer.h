#pragma once
#include "Csoldier.h"
class Officer :
    public Csoldier
{
    std::string commanded_unit{"Company A"};
public:
    Officer() = default;
    Officer(std::string cu);
    void promote_soldier(Csoldier& soldier);
    void introduce();
    void show();
};

