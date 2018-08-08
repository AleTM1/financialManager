

#include "gtest/gtest.h"

#include "../View.h"

TEST(GameCharacter, DefaultConstructor) {

    auto model = new Model;
    auto controller = new Controller(model);
    View view(controller, model);

    ASSERT_TRUE(view.isFirstTime());
}
