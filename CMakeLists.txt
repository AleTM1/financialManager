cmake_minimum_required(VERSION 3.10)
project(financialManager)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)



add_subdirectory(test)


#Classi del progetto
set(SOURCE_FILES Account.cpp Account.h View.h View.cpp Controller.cpp Controller.h Model.cpp Model.h Subject.h Observer.h ViewWindow.h AbstractDataStorage.h Conto.cpp Conto.h qsliderreadonly.h Transaction.h Historical.cpp Historical.h transactionFormUi.h TransactionForm.h dialogUi.h DialogNoButton.cpp DialogNoButton.h ErrorLog.h enumOrder.h ResearchOptions.h enumSaving.h Investment.h Entity.h Company.cpp Company.h FundSociety.cpp FundSociety.h AbstractStockFund.cpp AbstractStockFund.h Stock.cpp Stock.h Fund.cpp Fund.h Bond.cpp Bond.h InvestmentManager.cpp InvestmentManager.h EntitiesList.h enumInvestmentType.h)

#Creo l'eseguibile unendo le classi del progetto al main
add_executable(financialManager main.cpp ${SOURCE_FILES})

#collego la libreria QT all'eseguibile
target_link_libraries(financialManager Qt5::Widgets)

#creo una libreria 'core' contenente le Classi del progetto e la collego alla libreria Qt per il corretto funzionamento del core
add_library(core ${SOURCE_FILES})
target_link_libraries(core Qt5::Widgets)
