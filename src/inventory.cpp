//
// Created by alexa on 6/6/2019.
//
#include "inventory.h"

Inventory::~Inventory()
{

}

Inventory::Inventory(Store * storePointer, fstream &infile)
{
    store = storePointer;
}

void Inventory::process()
{
    store->displayAll();
}