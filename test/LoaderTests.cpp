#include "gtest/gtest.h"

#include "../Loader.h"

TEST(Loader, FirstOpening) {


    Loader loader;

    ASSERT_TRUE(loader.isFirstTime());
}
