//
// Created by alessandro on 26/08/18.
//

#ifndef FINANCIALMANAGER_SOCIETIESLIST_H
#define FINANCIALMANAGER_SOCIETIESLIST_H


#include <vector>
#include "Entity.h"
#include "Company.h"
#include "FundSociety.h"

struct EntitiesList {

   EntitiesList(){

       Entity* entity;

       entity = new Company(0.5, "Google", "DE000A11RNQ5", 1221.57 );

       entities.push_back(entity);

       entity = new Company(0.6, "FCA", "NL0010877643", 14.49 );

       entities.push_back(entity);

       entity = new Company(0.4, "Microsoft", "US5949181045", 93.6 );

       entities.push_back(entity);

       entity = new FundSociety(2.0, "Allianz", " IT0005282287", 37.4);

       entities.push_back(entity);

       entity = new FundSociety(2.5, "ModernTrading", " FR0007221731", 82.1 );

       entities.push_back(entity);

       entity = new FundSociety(1.5, "AgoraTrading", " SP0004874001", 110.8 );

       entities.push_back(entity);


   }


   ~EntitiesList(){

       for (auto e:entities)
           delete e;
       entities.clear();
   }

   std::vector<Entity*> entities;

};


#endif //FINANCIALMANAGER_SOCIETIESLIST_H
