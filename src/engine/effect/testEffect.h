#pragma once
#include <engine/effect/effect.h>
namespace chenpi{
class TestEffect : public Effect
{
public:
    TestEffect(/* args */);
    virtual ~TestEffect();
public:
    void Draw() override;
private:
    /* data */
};
}

