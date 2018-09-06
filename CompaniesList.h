//
// Created by alessandro on 26/08/18.
//

#ifndef FINANCIALMANAGER_SOCIETIESLIST_H
#define FINANCIALMANAGER_SOCIETIESLIST_H

#include <vector>
#include "Company.h"

struct CompaniesList {

  CompaniesList()
  {

      Company* entity;

      entity = new Company(0.5, "Google", "DE000A11RNQ5", 1221.57);

      companies.push_back(entity);

      entity = new Company(0.6, "FCA", "NL0010877643", 14.49);

      companies.push_back(entity);

      entity = new Company(0.4, "Microsoft", "US5949181045", 93.6);

      companies.push_back(entity);

  }

  ~CompaniesList()
  {

      for (auto e:companies)
          delete e;
      companies.clear();
  }

  std::vector<Company*> companies;

};

#endif //FINANCIALMANAGER_SOCIETIESLIST_H
