//
// Created by Christopher Clement on 2021-03-27.
//
#include "includes/Reltt.hpp"
instruction::instruction(int charline, int charstr2)
{
    this->insnumber = charstr2;
    this->line = charline;
}