cmake_minimum_required(VERSION 3.10)

#configurazione google test

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

#aggiungo i vari test

set(TEST_SOURCE_FILES runAllTests.cpp ContoTest.cpp HistoricalTests.cpp TransactionTests.cpp AccountTests.cpp InvestmentManagerTests.cpp BondTests.cpp ModelTests.cpp)

#creo l'eseguibile e gli linko le classi del progetto

add_executable(runFinancialManagerTests ${TEST_SOURCE_FILES})
target_link_libraries(runFinancialManagerTests gtest gtest_main core)




