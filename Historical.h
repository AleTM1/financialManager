//
// Created by alessandro on 16/08/18.
//

#ifndef FINANCIALMANAGER_HISTORICAL_H
#define FINANCIALMANAGER_HISTORICAL_H

#include "Conto.h"
#include "ResearchOptions.h"

class Historical : public AbstractDataStorage {

public:

	Historical ();

	void addTransaction ( Transaction );

	virtual void saveData () override;

	virtual void loadData () override;

	const std::list<Transaction> &getHistory () const;

	void setOrder ( ResearchOptions & );

	float getTotal () const;

private:

	void updateOrder ();

protected:

	std::list<Transaction> rawHistory;

	std::list<Transaction> orderedHistory;

	ResearchOptions researchOptions;

	float total;
};

#endif //FINANCIALMANAGER_HISTORICAL_H
